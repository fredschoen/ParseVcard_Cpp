#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <windows.h> // Pour SetConsoleOutputCP et SetConsoleCP

using namespace std;

//============================================================================
string transcodeEscapeChar(string sTexte, string sCode, string sDecode) {
// objectif: trouver la chaine "sCode" dans le texte "sTexte" et le remplacer par "sDecode"
//============================================================================

	//cout<<"transcodeEscapeChar, in  : " << sTexte << "," << sCode << "," << sDecode << "," << endl;
	std::string sRetour=sTexte;
	std::size_t found =sRetour.find(sCode);
	while(found!=std::string::npos) {
		sRetour.replace(found, sCode.length(), sDecode);
		found =sRetour.find(sCode);
	}
	//cout<<"transcodeEscapeChar, out : " << sRetour << endl;
return sRetour;
}



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

		//line=transcodeTousLesEscapeCar(line);
		
		line=transcodeEscapeChar(line, "&", "&amp;"); //commencer par le & , sinon le reste est KO !!
		line=transcodeEscapeChar(line, "'", "&apos;");
		line=transcodeEscapeChar(line, "\"", "&quot;");

		line=transcodeEscapeChar(line, "à", "&agrave;");
		line=transcodeEscapeChar(line, "â", "&acirc;");
		line=transcodeEscapeChar(line, "ä", "&auml;");
		line=transcodeEscapeChar(line, "ç", "&ccedil;");
		line=transcodeEscapeChar(line, "é", "&eacute;");
		line=transcodeEscapeChar(line, "è", "&egrave;");
		line=transcodeEscapeChar(line, "ê", "&ecirc;");
		line=transcodeEscapeChar(line, "ë", "&euml;");
		line=transcodeEscapeChar(line, "î", "&icirc;");
		line=transcodeEscapeChar(line, "ï", "&iuml;");
		line=transcodeEscapeChar(line, "ô", "&ocirc;");
		line=transcodeEscapeChar(line, "ö", "&ouml;");
		line=transcodeEscapeChar(line, "ù", "&ugrave;");
		line=transcodeEscapeChar(line, "û", "&ucirc;");
		line=transcodeEscapeChar(line, "ü", "&uuml;");
		line=transcodeEscapeChar(line, "ÿ", "&yuml;");
		line=transcodeEscapeChar(line, "À", "&Agrave;");
		line=transcodeEscapeChar(line, "Â", "&Acirc;");
		line=transcodeEscapeChar(line, "Ä", "&Auml;");
		line=transcodeEscapeChar(line, "Ç", "&Ccedil;");
		line=transcodeEscapeChar(line, "É", "&Eacute;");
		line=transcodeEscapeChar(line, "È", "&Egrave;");
		line=transcodeEscapeChar(line, "Ê", "&Ecirc;");
		line=transcodeEscapeChar(line, "Ë", "&Euml;");
		line=transcodeEscapeChar(line, "Î", "&Icirc;");
		line=transcodeEscapeChar(line, "Ï", "&Iuml;");
		line=transcodeEscapeChar(line, "Ô", "&Ocirc;");
		line=transcodeEscapeChar(line, "Ö", "&Ouml;");
		line=transcodeEscapeChar(line, "Ù", "&Ugrave;");
		line=transcodeEscapeChar(line, "Û", "&Ucirc;");
		line=transcodeEscapeChar(line, "Ü", "&Uuml;");
		line=transcodeEscapeChar(line, "«", "&laquo;");
		line=transcodeEscapeChar(line, "»", "&raquo;");
		line=transcodeEscapeChar(line, "<", "&lt;");
		line=transcodeEscapeChar(line, ">", "&gt;");

	
		
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
