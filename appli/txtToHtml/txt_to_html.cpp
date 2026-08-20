#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <windows.h> // Pour SetConsoleOutputCP et SetConsoleCP
#include <dirent.h> // Header file for directory operations
#include <filesystem>

using namespace std;

//============================================================================
string replaceString(string sTexte, string sCode, string sDecode) {
// objectif: trouver la chaine "sCode" dans le texte "sTexte" et le remplacer par "sDecode"
//============================================================================

	//cout<<"replaceString, in  : " << sTexte << "," << sCode << "," << sDecode << "," << endl;
	std::string sRetour=sTexte;
	std::size_t found =sRetour.find(sCode);
	while(found!=std::string::npos) {
		sRetour.replace(found, sCode.length(), sDecode);
		found =sRetour.find(sCode);
	}
	//cout<<"replaceString, out : " << sRetour << endl;
return sRetour;
}



void transcodeToHTML(const std::string& inputFilePath, const std::string& outputFilePath) {
    std::ifstream inFile(inputFilePath);
    std::ofstream outFile(outputFilePath);

    if (!inFile.is_open()) {
        std::cerr << "Erreur : Impossible d'ouvrir le fichier d'entrée : " << inputFilePath << std::endl;
        return;
    }

    if (!outFile.is_open()) {
        std::cerr << "Erreur : Impossible de créer le fichier de sortie : " << outputFilePath << std::endl;
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

		//line=transcodeTousLesEscapeCar(line);
		
		line=replaceString(line, "&", "&amp;"); //commencer par le & , sinon le reste est KO !!
		line=replaceString(line, "'", "&apos;");
		line=replaceString(line, "\"", "&quot;");

		line=replaceString(line, "à", "&agrave;");
		line=replaceString(line, "â", "&acirc;");
		line=replaceString(line, "ä", "&auml;");
		line=replaceString(line, "ç", "&ccedil;");
		line=replaceString(line, "é", "&eacute;");
		line=replaceString(line, "è", "&egrave;");
		line=replaceString(line, "ê", "&ecirc;");
		line=replaceString(line, "ë", "&euml;");
		line=replaceString(line, "î", "&icirc;");
		line=replaceString(line, "ï", "&iuml;");
		line=replaceString(line, "ô", "&ocirc;");
		line=replaceString(line, "ö", "&ouml;");
		line=replaceString(line, "ù", "&ugrave;");
		line=replaceString(line, "û", "&ucirc;");
		line=replaceString(line, "ü", "&uuml;");
		line=replaceString(line, "ÿ", "&yuml;");
		line=replaceString(line, "À", "&Agrave;");
		line=replaceString(line, "Â", "&Acirc;");
		line=replaceString(line, "Ä", "&Auml;");
		line=replaceString(line, "Ç", "&Ccedil;");
		line=replaceString(line, "É", "&Eacute;");
		line=replaceString(line, "È", "&Egrave;");
		line=replaceString(line, "Ê", "&Ecirc;");
		line=replaceString(line, "Ë", "&Euml;");
		line=replaceString(line, "Î", "&Icirc;");
		line=replaceString(line, "Ï", "&Iuml;");
		line=replaceString(line, "Ô", "&Ocirc;");
		line=replaceString(line, "Ö", "&Ouml;");
		line=replaceString(line, "Ù", "&Ugrave;");
		line=replaceString(line, "Û", "&Ucirc;");
		line=replaceString(line, "Ü", "&Uuml;");
		line=replaceString(line, "«", "&laquo;");
		line=replaceString(line, "»", "&raquo;");
		line=replaceString(line, "<", "&lt;");
		line=replaceString(line, ">", "&gt;");

	
		
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
    outFile << "          <table style=\"width: 100%; border-collapse: collapse; margin-bottom: 1em;\">\n";
    outFile << "            <tr>\n";
    outFile << "              <td style=\"width: 20%; text-align: center; padding: 0.5em; border: 1px solid #ccc;\">\n";
    outFile << "                <a href=\"index.html\" style=\"display: inline-block;\">\n";
    outFile << "                  <img src=\"left-arrow.svg\" alt=\"Retour\" style=\"width: 32px; height: 32px;\">\n";
    outFile << "                </a>\n";
    outFile << "              </td>\n";
    outFile << "            </tr>\n";
    outFile << "          </table>\n";
    outFile << "</body>\n</html>";

    inFile.close();
    outFile.close();
    std::cout << "Transcodage terminé : " << outputFilePath << " généré avec succès !" << std::endl;
}

int trtDirTxt() {
    namespace fs = std::filesystem;
    fs::path txtDirPath = fs::current_path() / "txt";

    fs::path indexPath = fs::current_path() / "html" / "index.html";
    std::ofstream indexFile(indexPath.string());

    if (!indexFile.is_open()) {
        std::cerr << "Erreur : Impossible de créer le fichier index de sortie : " << indexPath.string() << std::endl;
        return 0;
    }

    // Début du document index HTML avec le <head> personnalisé
    indexFile << "<!DOCTYPE html>\n<html>\n<head>\n";
    indexFile << "  <meta charset=\"UTF-8\" />\n";
    indexFile << "  <title>index</title>\n";
    indexFile << "  <style>\n";
    indexFile << "    p {\n";
    indexFile << "      margin: 0 0 0.7em 0;\n";
    indexFile << "      line-height: 1.3;\n";
    indexFile << "      font-family: Arial;\n";
    indexFile << "      font-size: 24px;\n";
    indexFile << "      text-indent: 0.5cm;\n";
    indexFile << "    }\n";
    indexFile << "    h1 {\n";
    indexFile << "      margin: 0.1em 0 0.1em 0;\n";
    indexFile << "      color: rgb(150, 0, 0);\n";
    indexFile << "    }\n";
    indexFile << "  </style>\n";
    indexFile << "</head>\n<body>\n";

    indexFile << "	<table style=\"width: 100%; border-collapse: collapse; margin-bottom: 1em;\">\n";
    indexFile << "		<tr>\n";
    indexFile << "		  <td style=\"width: 80%; text-align: center; padding: 0.5em; border: 1px solid #ccc;\">\n";
    indexFile << "			<h1>index de x</h1>\n";
    indexFile << "		  </td>\n";
    indexFile << "		</tr>\n";
    indexFile << "	</table>\n";
    indexFile << "	<p>\n";



    std::string inputFilePath, outputFilePath;
	std::string pageRef, pageLib;

    if (fs::exists(txtDirPath) && fs::is_directory(txtDirPath)) {
        for (const auto& entry : fs::directory_iterator(txtDirPath)) {
            if (entry.is_regular_file() && entry.path().extension() == ".txt") {
                //std::cout << entry.path().filename().string() << std::endl;
                std::cout << entry.path().string() << std::endl;
				
				inputFilePath=entry.path().string();
				outputFilePath=replaceString(entry.path().string(),".txt",".html");
				outputFilePath=replaceString(outputFilePath,"\\txt\\","\\html\\");
				
				pageRef=replaceString(entry.path().filename().string(),".txt",".html");
				pageLib=replaceString(entry.path().filename().string(),".txt","");
				indexFile << "		<a href=\"" << pageRef << "\">" << pageLib << "</a><br>\n";

				transcodeToHTML(inputFilePath, outputFilePath);				
            }
        }
    } else {
        std::cerr << "Directory 'txt' does not exist." << std::endl;
    }

    // Fin du document index HTML
    indexFile << "	</p>\n";
    indexFile << "</body>\n</html>";
    indexFile.close();
    std::cout << "Transcodage terminé : " << indexPath.string() << " généré avec succès !" << std::endl;

    return 0;
}

int main() {
    // Forcer la console Windows à utiliser UTF-8
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

	trtDirTxt();

    return 0;
}
