#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <windows.h> // Pour SetConsoleOutputCP et SetConsoleCP

void transcodeToHTML(const std::string& inputFile, const std::string& outputFile) {
    std::ifstream inFile(inputFile);
    std::ofstream outFile(outputFile);

    if (!inFile.is_open()) {
        std::cerr << "Erreur : Impossible d'ouvrir le fichier d'entrée : " << inputFile << std::endl;
        return;
    }

    if (!outFile.is_open()) {
        std::cerr << "Erreur : Impossible de créer le fichier de sortie : " << outputFile << std::endl;
        return;
    }

    std::string line;
    bool firstLine = true;

    // Début du document HTML avec le <head> personnalisé
    outFile << "<!DOCTYPE html>\n<html>\n<head>\n";
    outFile << "  <meta charset=\"UTF-8\" />\n";
    outFile << "  <title>texte</title>\n";
    outFile << "  <style>\n";
    outFile << "    p {\n";
    outFile << "      margin: 0 0 0.7em 0;\n";
    outFile << "      line-height: 1.3;\n";
    outFile << "      font-family: Arial;\n";
    outFile << "      font-size: 24px;\n";
    outFile << "      text-indent: 0.5cm;\n";
    outFile << "    }\n";
    outFile << "    h1 {\n";
    outFile << "      margin: 0.1em 0 0.1em 0;\n";
    outFile << "      color: rgb(150, 0, 0);\n";
    outFile << "    }\n";
    outFile << "  </style>\n";
    outFile << "</head>\n<body>\n";

    while (std::getline(inFile, line)) {
        if (line.empty()) {
            continue; // Ignorer les lignes vides
        }

        if (line == "-") {
            outFile << "<hr>\n";
        } else if (firstLine) {


            // Envelopper le <h1> dans la structure de tableau
            outFile << "<table style=\"width: 100%; border-collapse: collapse; margin-bottom: 1em;\">\n";
            outFile << "  <tr>\n";
            outFile << "    <td style=\"width: 80%; text-align: center; padding: 0.5em; border: 1px solid #ccc;\">\n";
            outFile << "      <h1>" << line << "</h1>\n";
            outFile << "    </td>\n";
            outFile << "    <td style=\"width: 20%; text-align: center; padding: 0.5em; border: 1px solid #ccc;\">\n";
            outFile << "      <a href=\"index.html\" style=\"display: inline-block;\">\n";
            outFile << "        <img src=\"left-arrow.svg\" alt=\"Retour\" style=\"width: 32px; height: 32px;\">\n";
            outFile << "      </a>\n";
            outFile << "    </td>\n";
            outFile << "  </tr>\n";
            outFile << "</table>\n";			
 
            firstLine = false;
        } else {
            outFile << "<p>" << line << "</p>\n";
        }
    }

    // Fin du document HTML
    outFile << "</body>\n</html>";

    inFile.close();
    outFile.close();
    std::cout << "Transcodage terminé : " << outputFile << " généré avec succès !" << std::endl;
}

int main() {
    // Forcer la console Windows à utiliser UTF-8
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    std::string reponse, inputFile, outputFile;

    std::cout << "Entrez le nom du fichier .txt à transcoder en .html : ";
    std::cin >> reponse;
	// Si inputFile est vide, on retourne
    if (reponse == "") {
        return 0;
    }
	inputFile  = reponse + ".txt";
	outputFile = reponse + ".html";

    transcodeToHTML(inputFile, outputFile);

    return 0;
}
