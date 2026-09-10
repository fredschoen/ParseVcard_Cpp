#include <chrono>
#include <filesystem>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>

namespace fs = std::filesystem;

struct FileInfo {
    fs::path path;
    std::uintmax_t size = 0;
    fs::file_time_type modificationTime;
};

std::string relativeName(const fs::path& path) {
    return path.generic_string();
}

std::map<std::string, FileInfo> listFiles(const fs::path& root) {
    std::map<std::string, FileInfo> files;

    if (!fs::exists(root) || !fs::is_directory(root)) {
        return files;
    }

    for (const fs::directory_entry& entry : fs::recursive_directory_iterator(root)) {
        if (!entry.is_regular_file()) {
            continue;
        }

        const fs::path relativePath = fs::relative(entry.path(), root);
        files.emplace(relativeName(relativePath), FileInfo{
            entry.path(),
            entry.file_size(),
            entry.last_write_time()
        });
    }

    return files;
}

std::set<std::string> listDirectories(const fs::path& root) {
    std::set<std::string> directories;

    if (!fs::exists(root) || !fs::is_directory(root)) {
        return directories;
    }

    for (const fs::directory_entry& entry : fs::recursive_directory_iterator(root)) {
        if (!entry.is_directory()) {
            continue;
        }

        directories.insert(relativeName(fs::relative(entry.path(), root)));
    }

    return directories;
}

std::string nowAsText() {
    const std::time_t now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    std::tm localTime{};
#ifdef _WIN32
    localtime_s(&localTime, &now);
#else
    localtime_r(&now, &localTime);
#endif

    std::ostringstream result;
    result << std::put_time(&localTime, "%Y-%m-%d %H:%M:%S");
    return result.str();
}

void writeLog(std::ofstream& log, const std::string& action,
              const std::string& relativePath, bool execution) {
    log << nowAsText() << " | " << (execution ? "EXEC" : "SIMU")
        << " | " << action << " | " << relativePath << '\n';
}

bool copySourceFile(const FileInfo& source, const fs::path& target) {
    try {
        fs::create_directories(target.parent_path());
        fs::copy_file(source.path, target, fs::copy_options::overwrite_existing);
        fs::last_write_time(target, source.modificationTime);
        return true;
    } catch (const fs::filesystem_error& error) {
        std::cerr << "Erreur de copie de " << source.path << " vers "
                  << target << " : " << error.what() << '\n';
        return false;
    }
}

bool removeTargetFile(const fs::path& target) {
    try {
        return fs::remove(target);
    } catch (const fs::filesystem_error& error) {
        std::cerr << "Erreur de suppression de " << target << " : "
                  << error.what() << '\n';
        return false;
    }
}

bool removeTargetDirectory(const fs::path& target) {
    try {
        return fs::remove(target);
    } catch (const fs::filesystem_error& error) {
        std::cerr << "Erreur de suppression du repertoire " << target << " : "
                  << error.what() << '\n';
        return false;
    }
}

int main(int argc, char* argv[]) {
    if (argc < 3 || argc > 4) {
        std::cerr << "Usage : iterativeSave <repertoire_source> <repertoire_cible> [simu|exec]\n";
        return 1;
    }

    const fs::path sourceRoot = fs::absolute(argv[1]).lexically_normal();
    const fs::path targetRoot = fs::absolute(argv[2]).lexically_normal();
    const std::string mode = argc == 4 ? argv[3] : "simu";
    const bool execution = mode == "exec";

    if (!execution && mode != "simu") {
        std::cerr << "Mode invalide : utiliser simu ou exec.\n";
        return 1;
    }

    if (execution) {
        std::cout << "Mode execution : confirmer le traitement (o/n) : " << std::flush;
        std::string confirmation;
        std::getline(std::cin, confirmation);
        if (confirmation != "o" && confirmation != "O") {
            std::cout << "Traitement annule.\n";
            return 0;
        }
    }

    if (!fs::exists(sourceRoot) || !fs::is_directory(sourceRoot)) {
        std::cerr << "Le repertoire source n'existe pas ou n'est pas un repertoire : "
                  << sourceRoot << '\n';
        return 1;
    }
    if (execution) {
        try {
            fs::create_directories(targetRoot);
        } catch (const fs::filesystem_error& error) {
            std::cerr << "Impossible de creer le repertoire cible : "
                      << error.what() << '\n';
            return 1;
        }
    }

    std::ofstream log("iterativeSave.log", std::ios::trunc);
    if (!log) {
        std::cerr << "Impossible d'ouvrir iterativeSave.log.\n";
        return 1;
    }

    const std::map<std::string, FileInfo> sourceFiles = listFiles(sourceRoot);
    const std::map<std::string, FileInfo> targetFiles = listFiles(targetRoot);
    const std::set<std::string> sourceDirectories = listDirectories(sourceRoot);
    const std::set<std::string> targetDirectories = listDirectories(targetRoot);
    std::set<std::string> allNames;
    for (const auto& file : sourceFiles) {
        allNames.insert(file.first);
    }
    for (const auto& file : targetFiles) {
        allNames.insert(file.first);
    }

    int differenceCount = 0;
    for (const std::string& name : allNames) {
        const auto source = sourceFiles.find(name);
        const auto target = targetFiles.find(name);
        const fs::path targetPath = targetRoot / fs::path(name);

        if (source != sourceFiles.end() && target == targetFiles.end()) {
            differenceCount++;
            writeLog(log, "NOUVEAU", name, execution);
            if (execution && !copySourceFile(source->second, targetPath)) {
                return 1;
            }
        } else if (source == sourceFiles.end() && target != targetFiles.end()) {
            differenceCount++;
            writeLog(log, "SUPPRIME", name, execution);
            if (execution && !removeTargetFile(targetPath)) {
                return 1;
            }
        } else if (source->second.size != target->second.size ||
                   source->second.modificationTime != target->second.modificationTime) {
            differenceCount++;
            writeLog(log, "MODIFIE", name, execution);
            if (execution && !copySourceFile(source->second, targetPath)) {
                return 1;
            }
        }
    }

    for (const std::string& name : sourceDirectories) {
        if (targetDirectories.find(name) != targetDirectories.end()) {
            continue;
        }

        differenceCount++;
        writeLog(log, "NOUVEAU", name + "/", execution);
        if (execution) {
            try {
                fs::create_directories(targetRoot / fs::path(name));
            } catch (const fs::filesystem_error& error) {
                std::cerr << "Erreur de creation du repertoire "
                          << targetRoot / fs::path(name) << " : "
                          << error.what() << '\n';
                return 1;
            }
        }
    }

    for (auto directory = targetDirectories.rbegin();
         directory != targetDirectories.rend(); ++directory) {
        if (sourceDirectories.find(*directory) != sourceDirectories.end()) {
            continue;
        }

        differenceCount++;
        writeLog(log, "SUPPRIME", *directory + "/", execution);
        if (execution && !removeTargetDirectory(targetRoot / fs::path(*directory))) {
            return 1;
        }
    }

    std::cout << "Nombre de differences : " << differenceCount << '\n';
    return 0;
}