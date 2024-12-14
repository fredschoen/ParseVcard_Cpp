//============================================================================
// Name        : ParseVCard.cpp
// Author      : F SCHOEN
// Version     : 41212a
// Copyright   : F SCHOEN
// Description : conversion aller et retour Vcf/Csv
//============================================================================
// fonctions:
// string fChoixNomFic()
// void fCsvVersVcf(void)
// void fVcfVersCsv(void)
// void fDecouperLigneCsv(string ligneEntree)
// void fDecouperLigneVcf(string ligneEntree)
// void fSeparerElements(string sousLigne)
// string fTranscoderTexte(string sTexte)
// string fTranscoderTouesOccurrences(string sTexte, string sCode, string sDecode)
//============================================================================

#include <iostream>     // std::cout
#include <fstream>      // std::ifstream

using namespace std;

string sElement1="";
string sElement2="";
string sElement3="";
string sElement4="";
string sElement5="";
string sElement6="";
string sElement7="";

string sN1="";
string sN2="";
string sN3="";
string sN4="";

string sTC="";
string sTH="";
string sTW="";
string sEH="";
string sEW="";

string sO1="";
string sO2="";
string sO3="";

string sAH1="";
string sAH2="";
string sAH3="";
string sAH4="";
string sAH5="";
string sAH6="";
string sAH7="";

string sAW1="";
string sAW2="";
string sAW3="";
string sAW4="";
string sAW5="";
string sAW6="";
string sAW7="";

string sTI="";
string sNT="";

string nomFicEntree="";
string nomFicSortie="";

string nom1="vcard";
string nom2="test";
string nom3="adr_col";

string separAttributValeur = ":";
string separateurElements = ";";


//============================================================================
string fTranscoderTouesOccurrences(string sTexte, string sCode, string sDecode) {
// objectif: trouver la chaine "sCode" dans le texte "sTexte" et le remplacer par "sDecode"
//============================================================================

	//	cout<<"fTranscoderTouesOccurrences, in  : " << sTexte << "," << sCode << "," << sDecode << "," << endl;
	std::string sRetour=sTexte;
	std::size_t found =sRetour.find(sCode);
	while(found!=std::string::npos) {
		sRetour.replace(found, sCode.length(), sDecode);
		found =sRetour.find(sCode);
	}
//	cout<<"fTranscoderTexte, out : " << sRetour << endl;
return sRetour;
}

//============================================================================
string fTranscoderDebutLigne(string sTexte, string sCode, string sDecode) {
// objectif: trouver la chaine "sCode" dans le texte "sTexte" et le remplacer par "sDecode"
//============================================================================

	//	cout<<"fTranscoderDebutLigne, in  : " << sTexte << "," << sCode << "," << sDecode << "," << endl;
	std::string sRetour=sTexte;
	std::size_t found =sRetour.find(sCode);
	if(found==0) {
		sRetour.replace(found, sCode.length(), sDecode);
		cout<<"fTranscoderDebutLigne,0 sRetour=" << sRetour << endl;
	}
return sRetour;
}


//============================================================================
string fTranscoderTexte(string sTexte) {
	//============================================================================
//	cout<<"fTranscoderTexte, in  : " << sTexte << endl;
	string sRetour=sTexte;

// d'abord les "=C3"

//accent des majuscules
	sRetour=fTranscoderTouesOccurrences(sRetour, "=C3=89", "É");

//accent du a
	sRetour=fTranscoderTouesOccurrences(sRetour, "=C3=A0", "à");
	sRetour=fTranscoderTouesOccurrences(sRetour, "=C3=A2", "â");

//accent du c
	sRetour=fTranscoderTouesOccurrences(sRetour, "=C3=A7", "ç");

//accent du e
	sRetour=fTranscoderTouesOccurrences(sRetour, "=C3=A8", "è");
	sRetour=fTranscoderTouesOccurrences(sRetour, "=C3=A9", "é");
	sRetour=fTranscoderTouesOccurrences(sRetour, "=C3=AA", "ê");
	sRetour=fTranscoderTouesOccurrences(sRetour, "=C3=AB", "ë");

//accent du i
	sRetour=fTranscoderTouesOccurrences(sRetour, "=C3=AE", "î");
	sRetour=fTranscoderTouesOccurrences(sRetour, "=C3=AF", "ï");

//accent du o
	sRetour=fTranscoderTouesOccurrences(sRetour, "=C3=B4", "ô");

//accent du u
	sRetour=fTranscoderTouesOccurrences(sRetour, "=C3=B9", "ù");
	sRetour=fTranscoderTouesOccurrences(sRetour, "=C3=BB", "û");

// ensuite les <> "=C3"

	sRetour=fTranscoderTouesOccurrences(sRetour, "=20", " ");
	sRetour=fTranscoderTouesOccurrences(sRetour, "=26", "&");
	sRetour=fTranscoderTouesOccurrences(sRetour, "=28", "(");
	sRetour=fTranscoderTouesOccurrences(sRetour, "=29", ")");
	sRetour=fTranscoderTouesOccurrences(sRetour, "=2E", ".");

	sRetour=fTranscoderTouesOccurrences(sRetour, "=30", "0");
	sRetour=fTranscoderTouesOccurrences(sRetour, "=31", "1");
	sRetour=fTranscoderTouesOccurrences(sRetour, "=32", "2");
	sRetour=fTranscoderTouesOccurrences(sRetour, "=33", "3");
	sRetour=fTranscoderTouesOccurrences(sRetour, "=34", "4");
	sRetour=fTranscoderTouesOccurrences(sRetour, "=35", "5");
	sRetour=fTranscoderTouesOccurrences(sRetour, "=36", "6");
	sRetour=fTranscoderTouesOccurrences(sRetour, "=37", "7");
	sRetour=fTranscoderTouesOccurrences(sRetour, "=38", "8");
	sRetour=fTranscoderTouesOccurrences(sRetour, "=39", "9");

	sRetour=fTranscoderTouesOccurrences(sRetour, "=41", "A");
	sRetour=fTranscoderTouesOccurrences(sRetour, "=42", "B");
	sRetour=fTranscoderTouesOccurrences(sRetour, "=43", "C");
	sRetour=fTranscoderTouesOccurrences(sRetour, "=44", "D");
	sRetour=fTranscoderTouesOccurrences(sRetour, "=45", "E");
	sRetour=fTranscoderTouesOccurrences(sRetour, "=46", "F");
	sRetour=fTranscoderTouesOccurrences(sRetour, "=47", "G");
	sRetour=fTranscoderTouesOccurrences(sRetour, "=48", "H");
	sRetour=fTranscoderTouesOccurrences(sRetour, "=49", "I");
	sRetour=fTranscoderTouesOccurrences(sRetour, "=4A", "J");
	sRetour=fTranscoderTouesOccurrences(sRetour, "=4B", "K");
	sRetour=fTranscoderTouesOccurrences(sRetour, "=4C", "L");
	sRetour=fTranscoderTouesOccurrences(sRetour, "=4D", "M");
	sRetour=fTranscoderTouesOccurrences(sRetour, "=4E", "N");
	sRetour=fTranscoderTouesOccurrences(sRetour, "=4F", "O");

	sRetour=fTranscoderTouesOccurrences(sRetour, "=50", "P");
	sRetour=fTranscoderTouesOccurrences(sRetour, "=51", "Q");
	sRetour=fTranscoderTouesOccurrences(sRetour, "=52", "R");
	sRetour=fTranscoderTouesOccurrences(sRetour, "=53", "S");
	sRetour=fTranscoderTouesOccurrences(sRetour, "=54", "T");
	sRetour=fTranscoderTouesOccurrences(sRetour, "=55", "U");
	sRetour=fTranscoderTouesOccurrences(sRetour, "=56", "V");
	sRetour=fTranscoderTouesOccurrences(sRetour, "=57", "W");
	sRetour=fTranscoderTouesOccurrences(sRetour, "=58", "X");
	sRetour=fTranscoderTouesOccurrences(sRetour, "=59", "Y");
	sRetour=fTranscoderTouesOccurrences(sRetour, "=5A", "Z");

	sRetour=fTranscoderTouesOccurrences(sRetour, "=61", "a");
	sRetour=fTranscoderTouesOccurrences(sRetour, "=62", "b");
	sRetour=fTranscoderTouesOccurrences(sRetour, "=63", "c");
	sRetour=fTranscoderTouesOccurrences(sRetour, "=64", "d");
	sRetour=fTranscoderTouesOccurrences(sRetour, "=65", "e");
	sRetour=fTranscoderTouesOccurrences(sRetour, "=66", "f");
	sRetour=fTranscoderTouesOccurrences(sRetour, "=67", "g");
	sRetour=fTranscoderTouesOccurrences(sRetour, "=68", "h");
	sRetour=fTranscoderTouesOccurrences(sRetour, "=69", "i");
	sRetour=fTranscoderTouesOccurrences(sRetour, "=6A", "j");
	sRetour=fTranscoderTouesOccurrences(sRetour, "=6B", "k");
	sRetour=fTranscoderTouesOccurrences(sRetour, "=6C", "l");
	sRetour=fTranscoderTouesOccurrences(sRetour, "=6D", "m");
	sRetour=fTranscoderTouesOccurrences(sRetour, "=6E", "n");
	sRetour=fTranscoderTouesOccurrences(sRetour, "=6F", "o");

	sRetour=fTranscoderTouesOccurrences(sRetour, "=70", "p");
	sRetour=fTranscoderTouesOccurrences(sRetour, "=71", "q");
	sRetour=fTranscoderTouesOccurrences(sRetour, "=72", "r");
	sRetour=fTranscoderTouesOccurrences(sRetour, "=73", "s");
	sRetour=fTranscoderTouesOccurrences(sRetour, "=74", "t");
	sRetour=fTranscoderTouesOccurrences(sRetour, "=75", "u");
	sRetour=fTranscoderTouesOccurrences(sRetour, "=76", "v");
	sRetour=fTranscoderTouesOccurrences(sRetour, "=77", "w");
	sRetour=fTranscoderTouesOccurrences(sRetour, "=78", "x");
	sRetour=fTranscoderTouesOccurrences(sRetour, "=79", "y");
	sRetour=fTranscoderTouesOccurrences(sRetour, "=7A", "z");

	sRetour=fTranscoderTouesOccurrences(sRetour, "=A3", ":");

//	cout<<"fTranscoderTexte, out : " << sRetour << endl;
return sRetour;
}

//============================================================================
void fSeparerElements(string sousLigne) {
	//============================================================================
    sElement1 = "";
    sElement2 = "";
    sElement3 = "";
    sElement4 = "";
    sElement5 = "";
    sElement6 = "";
    sElement7 = "";

	size_t pos = 0;
	int numElement=0;
    
	sElement1 = sousLigne; //par défaut, il n'y a qu'un élément

	//plusieurs éléments ?
	while ((pos = sousLigne.find(separateurElements)) != std::string::npos) {
		cout << "fSeparerElements sousLigne<" << sousLigne << ">" << endl;
	    numElement+=1;
	    if (numElement==1) {
		    sElement1 = sousLigne.substr(0, pos);
		    sElement2 = sousLigne.substr(pos+ separateurElements.length(), sousLigne.length());
	    } else if (numElement==2) {
		    sElement2 = sousLigne.substr(0, pos);
		    sElement3 = sousLigne.substr(pos+ separateurElements.length(), sousLigne.length());
	    } else if (numElement==3) {
		    sElement3 = sousLigne.substr(0, pos);
		    sElement4 = sousLigne.substr(pos+ separateurElements.length(), sousLigne.length());
	    }else if (numElement==4) {
		    sElement4 = sousLigne.substr(0, pos);
		    sElement5 = sousLigne.substr(pos+ separateurElements.length(), sousLigne.length());
	    }else if (numElement==5) {
		    sElement5 = sousLigne.substr(0, pos);
		    sElement6 = sousLigne.substr(pos+ separateurElements.length(), sousLigne.length());
	    }else if (numElement==6) {
		    sElement6 = sousLigne.substr(0, pos);
		    sElement7 = sousLigne.substr(pos+ separateurElements.length(), sousLigne.length());
	    }else if (numElement==7) {
		    sElement7 = sousLigne;
	    }
	    sousLigne.erase(0, pos + separateurElements.length());
		cout << "fSeparerElements sElementx<" 
		<< sElement1 << ',' << sElement2 << ',' << sElement3 << ',' 
		<< sElement4 << ',' << sElement5 << ',' << sElement6 << ',' 
		<< sElement7 << ">" << endl;
	}
    
		cout << "fSeparerElements fin      <" 
		<< sElement1 << ',' << sElement2 << ',' << sElement3 << ',' 
		<< sElement4 << ',' << sElement5 << ',' << sElement6 << ',' 
		<< sElement7 << ">" << endl;
return;
}
//============================================================================
void fDecouperLigneVcf(string ligneEntree) {
	//============================================================================

	size_t pos = 0;
	std::string tabAttribut="";
	std::string tabValeur="";
	
	string attribut1="";
	string attribut2="";

	string valeur1="";
	string valeur2="";
	string valeur3="";
	string valeur4="";
	string valeur5="";
	string valeur6="";
	string valeur7="";

	// cas bizarres
	ligneEntree =fTranscoderDebutLigne(ligneEntree, "ADR;HOME;", "ADR;HOME:");
	ligneEntree =fTranscoderDebutLigne(ligneEntree, "ADR;WORK;", "ADR;WORK:");
	ligneEntree =fTranscoderDebutLigne(ligneEntree, "NOTE;", "NOTE:");
	ligneEntree =fTranscoderDebutLigne(ligneEntree, "TITLE;", "TITLE:");
	ligneEntree =fTranscoderDebutLigne(ligneEntree, "N;", "N:");

	// decoupage de la ligne: �l�ment 1
	pos = ligneEntree.find(separAttributValeur);
	tabAttribut = ligneEntree.substr(0, pos);

	// Majuscules
	for (auto & c: tabAttribut) c = toupper(c);

	// effacer les attributs dans "ligneEntree"
	ligneEntree.erase(0, pos + separAttributValeur.length());
	// dernier element=le reste de la ligne: �l�ment 2
	tabValeur= fTranscoderTexte(ligneEntree);

	//attribut de la ligne
	fSeparerElements(tabAttribut);
	attribut1=sElement1;
	attribut2=sElement2;

	//valeurs de la ligne
	fSeparerElements(tabValeur);
	valeur1=sElement1;
	valeur2=sElement2;
	valeur3=sElement3;
	valeur4=sElement4;
	valeur5=sElement5;
	valeur6=sElement6;
	valeur7=sElement7;

	//charger la bonne colonne
	if (attribut1.compare("N")==0) {
		sN1=valeur1;
		sN2=valeur2;
		sN3=valeur3;
		sN4=valeur4;

	} else if (attribut1.compare("TEL")==0){
		if (attribut2.compare("CELL")==0){
		       sTC=tabValeur;
	    } else if (attribut2.compare("HOME")==0){
	    	   sTH=tabValeur;
	    } else sTW=tabValeur;

	} else if (attribut1.compare("EMAIL")==0){
		if (attribut2.compare("HOME")==0){
		       sEH=tabValeur;
	    } else if (attribut2.compare("WORK")==0){
	    	   sEW=tabValeur;
	    } 

	} else if (attribut1.compare("ADR")==0){

		if (attribut2.compare("HOME")==0){
			sAH1=valeur1;
			sAH2=valeur2;
			sAH3=valeur3;
			sAH4=valeur4;
			sAH5=valeur5;
			if (valeur6.length()>0) {
			sAH6="'"+valeur6; //code postal
			}
			sAH7=valeur7;
	    }

		if (attribut2.compare("WORK")==0){
			sAW1=valeur1;
			sAW2=valeur2;
			sAW3=valeur3;
			sAW4=valeur4;
			sAW5=valeur5;
			if (valeur6.length()>0) {
			sAW6="'"+valeur6; //code postal
			}
			sAW7=valeur7;
	    }

	} else if (attribut1.compare("ORG")==0){
		sO1=valeur1;
		sO2=valeur2;
		sO3=valeur3;
	} else if (attribut1.compare("TITLE")==0){
		sTI=tabValeur;
	} else if (attribut1.compare("NOTE")==0){
		sNT=tabValeur;
	} else {
		//RAZ element2
		tabValeur="";
		if (tabAttribut.compare("BEGIN")==0) {
		   cout << "-----------------------------------------------" << endl;
 	    }
	}

	//display
	if (tabValeur.length()>0){
		  cout << " -> fDecouperLigneVcf: "
		  << "sN1:" << sN1
		  << ";sN2:" 		  << sN2
		  << ";sN3:" 		  << sN3
		  << ";sN4:" 		  << sN4
		  << ";sTC:" 		  << sTC
		  << ";sTH:" 		  << sTH
		  << ";sTW:" 		  << sTW
		  << ";sEH:"		  << sEH
		  << ";sEW:"		  << sEW
		  << ";sO1:"		<< sO1
		  << ";sO2:"		<< sO2
		  << ";sO3:"		<< sO3
		  << ";sTI:" 		  << sTI
		  << ";sNT:" 		  << sNT

		  << ";sAH1:"		<< sAH1
		  << ";sAH2:"		<< sAH2
		  << ";sAH3:"		<< sAH3
		  << ";sAH4:"		<< sAH4
		  << ";sAH5:"		<< sAH5
		  << ";sAH6:"		<< sAH6
		  << ";sAH7:"		<< sAH7

		  << ";sAW1:"		<< sAW1
		  << ";sAW2:"		<< sAW2
		  << ";sAW3:"		<< sAW3
		  << ";sAW4:"		<< sAW4
		  << ";sAW5:"		<< sAW5
		  << ";sAW6:"		<< sAW6
		  << ";sAW7:"		<< sAW7

		  << endl
		  ;
	}
}

//============================================================================
void fDecouperLigneCsv(string ligneEntree) {
	//============================================================================
	std::string separateurColonnes = "";
	separateurColonnes += '\t';
	
	size_t pos = 0;

	//chercher + charger + couper
	pos = ligneEntree.find(separateurColonnes);
	sN1 = ligneEntree.substr(0, pos);
	ligneEntree.erase(0, pos + separateurColonnes.length());

	//chercher + charger + couper
	pos = ligneEntree.find(separateurColonnes);
	sN2 = ligneEntree.substr(0, pos);
	ligneEntree.erase(0, pos + separateurColonnes.length());


	//chercher + charger + couper
	pos = ligneEntree.find(separateurColonnes);
	sN3 = ligneEntree.substr(0, pos);
	ligneEntree.erase(0, pos + separateurColonnes.length());


	//chercher + charger + couper
	pos = ligneEntree.find(separateurColonnes);
	sN4 = ligneEntree.substr(0, pos);
	ligneEntree.erase(0, pos + separateurColonnes.length());


	//chercher + charger + couper
	pos = ligneEntree.find(separateurColonnes);
	sTC = ligneEntree.substr(0, pos);
	sTC =fTranscoderDebutLigne(sTC, "'", "");

	ligneEntree.erase(0, pos + separateurColonnes.length());


	//chercher + charger + couper
	pos = ligneEntree.find(separateurColonnes);
	sTH = ligneEntree.substr(0, pos);
	sTH =fTranscoderDebutLigne(sTH, "'", "");
	ligneEntree.erase(0, pos + separateurColonnes.length());


	//chercher + charger + couper
	pos = ligneEntree.find(separateurColonnes);
	sTW = ligneEntree.substr(0, pos);
	sTW =fTranscoderDebutLigne(sTW, "'", "");
	ligneEntree.erase(0, pos + separateurColonnes.length());


	//chercher + charger + couper
	pos = ligneEntree.find(separateurColonnes);
	sEH = ligneEntree.substr(0, pos);
	ligneEntree.erase(0, pos + separateurColonnes.length());


	//chercher + charger + couper
	pos = ligneEntree.find(separateurColonnes);
	sEW = ligneEntree.substr(0, pos);
	ligneEntree.erase(0, pos + separateurColonnes.length());


	//chercher + charger + couper
	pos = ligneEntree.find(separateurColonnes);
	sO1 = ligneEntree.substr(0, pos);
	ligneEntree.erase(0, pos + separateurColonnes.length());


	//chercher + charger + couper
	pos = ligneEntree.find(separateurColonnes);
	sO2 = ligneEntree.substr(0, pos);
	ligneEntree.erase(0, pos + separateurColonnes.length());


	//chercher + charger + couper
	pos = ligneEntree.find(separateurColonnes);
	sO3 = ligneEntree.substr(0, pos);
	ligneEntree.erase(0, pos + separateurColonnes.length());


	//chercher + charger + couper
	pos = ligneEntree.find(separateurColonnes);
	sTI = ligneEntree.substr(0, pos);
	ligneEntree.erase(0, pos + separateurColonnes.length());

	//chercher + charger + couper
	pos = ligneEntree.find(separateurColonnes);
	sNT = ligneEntree.substr(0, pos);
	ligneEntree.erase(0, pos + separateurColonnes.length());


	//chercher + charger + couper
	pos = ligneEntree.find(separateurColonnes);
	sAH1 = ligneEntree.substr(0, pos);
	ligneEntree.erase(0, pos + separateurColonnes.length());


	//chercher + charger + couper
	pos = ligneEntree.find(separateurColonnes);
	sAH2 = ligneEntree.substr(0, pos);
	ligneEntree.erase(0, pos + separateurColonnes.length());


	//chercher + charger + couper
	pos = ligneEntree.find(separateurColonnes);
	sAH3 = ligneEntree.substr(0, pos);
	ligneEntree.erase(0, pos + separateurColonnes.length());


	//chercher + charger + couper
	pos = ligneEntree.find(separateurColonnes);
	sAH4 = ligneEntree.substr(0, pos);
	ligneEntree.erase(0, pos + separateurColonnes.length());


	//chercher + charger + couper
	pos = ligneEntree.find(separateurColonnes);
	sAH5 = ligneEntree.substr(0, pos);
	ligneEntree.erase(0, pos + separateurColonnes.length());


	//chercher + charger + couper
	pos = ligneEntree.find(separateurColonnes);
	sAH6 = ligneEntree.substr(0, pos);
	sAH6 =fTranscoderDebutLigne(sAH6, "'", "");
	ligneEntree.erase(0, pos + separateurColonnes.length());


	//chercher + charger + couper
	pos = ligneEntree.find(separateurColonnes);
	sAH7 = ligneEntree.substr(0, pos);
	ligneEntree.erase(0, pos + separateurColonnes.length());


	//chercher + charger + couper
	pos = ligneEntree.find(separateurColonnes);
	sAW1 = ligneEntree.substr(0, pos);
	ligneEntree.erase(0, pos + separateurColonnes.length());


	//chercher + charger + couper
	pos = ligneEntree.find(separateurColonnes);
	sAW2 = ligneEntree.substr(0, pos);
	ligneEntree.erase(0, pos + separateurColonnes.length());


	//chercher + charger + couper
	pos = ligneEntree.find(separateurColonnes);
	sAW3 = ligneEntree.substr(0, pos);
	ligneEntree.erase(0, pos + separateurColonnes.length());


	//chercher + charger + couper
	pos = ligneEntree.find(separateurColonnes);
	sAW4 = ligneEntree.substr(0, pos);
	ligneEntree.erase(0, pos + separateurColonnes.length());


	//chercher + charger + couper
	pos = ligneEntree.find(separateurColonnes);
	sAW5 = ligneEntree.substr(0, pos);
	ligneEntree.erase(0, pos + separateurColonnes.length());


	//chercher + charger + couper
	pos = ligneEntree.find(separateurColonnes);
	sAW6 = ligneEntree.substr(0, pos);
	sAW6 =fTranscoderDebutLigne(sAW6, "'", "");
	ligneEntree.erase(0, pos + separateurColonnes.length());


	//chercher + charger + couper
	pos = ligneEntree.find(separateurColonnes);
	sAW7 = ligneEntree.substr(0, pos);
	ligneEntree.erase(0, pos + separateurColonnes.length());

	cout << " -> fDecouperLigneCsv: "
	<< "sN1:" << sN1
	<< ";sN2:" 		  << sN2
	<< ";sN3:" 		  << sN3
	<< ";sN4:" 		  << sN4
	<< ";sTC:" 		  << sTC
	<< ";sTH:" 		  << sTH
	<< ";sTW:" 		  << sTW
	<< ";sEH:"		  << sEH
	<< ";sEW:"		  << sEW
	<< endl
	<< ";sO1:"		<< sO1
	<< ";sO2:"		<< sO2
	<< ";sO3:"		<< sO3
	<< ";sTI:" 		  << sTI
	<< ";sNT:" 		  << sNT
	<< endl

	<< ";sAH1:"		<< sAH1
	<< ";sAH2:"		<< sAH2
	<< ";sAH3:"		<< sAH3
	<< ";sAH4:"		<< sAH4
	<< ";sAH5:"		<< sAH5
	<< ";sAH6:"		<< sAH6
	<< ";sAH7:"		<< sAH7
	<< endl

	<< ";sAW1:"		<< sAW1
	<< ";sAW2:"		<< sAW2
	<< ";sAW3:"		<< sAW3
	<< ";sAW4:"		<< sAW4
	<< ";sAW5:"		<< sAW5
	<< ";sAW6:"		<< sAW6
	<< ";sAW7:"		<< sAW7

	<< endl;


}

//============================================================================
void fCsvVersVcf(void) {
	//============================================================================
  std::cout << "exec fCsvVersVcf" << endl;

  cout << "nomFicEntree=[" << nomFicEntree << "]" << endl;
  cout << "nomFicSortie=[" << nomFicSortie << "]"<< endl;

  std::ifstream ficEntree (nomFicEntree); // prendre un fichier ANSI (binary ne change pas le pb UTF8)
  std::ofstream ficSortie (nomFicSortie);

  //std::ifstream ficEntree (nomFicEntree, std::ios::binary); (binary ne change pas le pb UTF8)
  string ligneEntree="";

  if  (!ficEntree){
      cout << "ERREUR: Impossible d'ouvrir ficEntree " << nomFicEntree<< endl;
      return;
  }
  if  (!ficSortie){
      cout << "ERREUR: Impossible d'ouvrir ficSortie " << nomFicSortie<< endl;
      ficEntree.close();
      return;
  }

  getline(ficEntree, ligneEntree); //ne pas traiter la ligne d'entete

  while(getline(ficEntree, ligneEntree)) {
	  if (ligneEntree.length()>5) { // moins de 5 car <=> n'importe quoi dans la ligne!!
		  fDecouperLigneCsv(ligneEntree);
		  ficSortie	<< "BEGIN:VCARD"<< endl;
		  ficSortie	<< "VERSION:2.1"<< endl;
		  ficSortie	<< "N:" << sN1 << ";" << sN2 << ";;;"<< endl;
		  ficSortie	<< "TEL;CELL:" << sTC<< endl;
		  ficSortie	<< "TEL;HOME:" << sTH<< endl;
		  ficSortie	<< "TEL;WORK:" << sTW<< endl;
		  ficSortie	<< "EMAIL;HOME:" << sEH<< endl;
		  ficSortie	<< "EMAIL;WORK:" << sEW<< endl;
		  ficSortie	<< "ADR;HOME:" << ";" << sAH1 << ";" << sAH2  << ";" << sAH3  << ";" << sAH4  << ";" << sAH5  << ";" << sAH6 << ";" << sAH7 << endl;
		  ficSortie	<< "ADR;WORK:" << ";" << sAW1 << ";" << sAW2  << ";" << sAW3  << ";" << sAW4  << ";" << sAW5  << ";" << sAW6 << ";" << sAW7 << endl;
		  ficSortie	<< "ORG:" << sO1 << ";" << sO2<< ";" << sO2<< endl;
		  ficSortie	<< "TITLE:" << sTI<< endl;
		  ficSortie	<< "NOTE:" << sNT<< endl;
		  ficSortie	<< "END:VCARD"<< endl;

	  }
      cout << "fCsvVersVcf, nomFicEntree=" << nomFicEntree << " nomFicSortie=" << nomFicSortie << " : OK !!!!!!!!!" << endl;

  }

  ficEntree.close();
  ficSortie.close();
  return;
}

//============================================================================
void fVcfVersCsv(void) {
	//============================================================================
  std::cout << "exec fVcfVersCsv" << endl;

  cout << "nomFicEntree=[" << nomFicEntree << "]" << endl;
  cout << "nomFicSortie=[" << nomFicSortie << "]"<< endl;


  std::ifstream ficEntree (nomFicEntree); // prendre un fichier ANSI (binary ne change pas le pb UTF8)
  std::ofstream ficSortie (nomFicSortie);

  //std::ifstream ficEntree (nomFicEntree, std::ios::binary); (binary ne change pas le pb UTF8)



// traitement
  if  (ficSortie){
	  ficSortie
	  << "N1" << '\t'
	  << "N2" << '\t'
	  << "N3" << '\t'
	  << "N4" << '\t'

	  << "TEL_CELL"<< '\t'
	  << "TEL_HOME"<< '\t'
	  << "TEL_WORK"<< '\t'

	  << "EMAIL_H"<< '\t'
	  << "EMAIL_W"<< '\t'

	  << "ORG1"<< '\t'
	  << "ORG2"<< '\t'
	  << "ORG3"<< '\t'

	  << "TIT"<< '\t'
	  << "NOTE"<< '\t'

	  << "ADH1"<< '\t'
	  << "ADH2"<< '\t'
	  << "ADH3"<< '\t'
	  << "ADH4"<< '\t'
	  << "ADH5"<< '\t'
	  << "ADH6"<< '\t'
	  << "ADH7"<< '\t'

	  << "ADW1"<< '\t'
	  << "ADW2"<< '\t'
	  << "ADW3"<< '\t'
	  << "ADW4"<< '\t'
	  << "ADW5"<< '\t'
	  << "ADW6"<< '\t'
	  << "ADW7"<< '\t'
	  << endl
	  ;

	  if  (ficEntree){
	      cout << "d�but>>>>>>>>>>>>>>>>>>>" << endl;
		  string ligneEntree; //Une variable pour stocker les lignes lues
		  int nLigne=0;
		  //Tant qu'on n'est pas � la fin, on lit
		  // while(getline(ficEntree, ligneEntree, '\r'))
		  while(getline(ficEntree, ligneEntree)) {
			  nLigne+=1;
			  cout << "getligne " << nLigne << "=" << ligneEntree<< endl;
			  fDecouperLigneVcf(ligneEntree);

			  // en fin de card on ecrit
			  // Majuscule
			  for (auto & c: ligneEntree) c = toupper(c);

			  if (  ligneEntree.compare("END:VCARD")==0   )
			  {
				ficSortie
				<< sN1 << '\t'
				<< sN2 << '\t'
				<< sN3 << '\t'
				<< sN4 << '\t'
				<< "'" << sTC<< '\t'
				<< "'" << sTH<< '\t'
				<< "'" << sTW<< '\t'
				<< sEH<< '\t'
				<< sEW<< '\t'
				<< sO1<< '\t'
				<< sO2<< '\t'
				<< sO3<< '\t'
				<< sTI<< '\t'
				<< sNT<< '\t'

				<< sAH1<< '\t'
				<< sAH2<< '\t'
				<< sAH3<< '\t'
				<< sAH4<< '\t'
				<< sAH5<< '\t'
				<< sAH6<< '\t'
				<< sAH7<< '\t'

				<< sAW1<< '\t'
				<< sAW2<< '\t'
				<< sAW3<< '\t'
				<< sAW4<< '\t'
				<< sAW5<< '\t'
				<< sAW6<< '\t'
				<< sAW7<< '\t'

				<< endl
				;

				sN1="";
				sN2="";
				sN3="";
				sN4="";
				sTC="";
				sTH="";
				sTW="";
				sEH="";
				sEW="";
				sO1="";
				sO2="";
				sO3="";
				sAH1="";
				sAH2="";
				sAH3="";
				sAH4="";
				sAH5="";
				sAH6="";
				sAH7="";

				sAW1="";
				sAW2="";
				sAW3="";
				sAW4="";
				sAW5="";
				sAW6="";
				sAW7="";

				sTI="";
				sNT="";

			  }

		  }
	      cout << "fVcfVersCsv, nomFicEntree=" << nomFicEntree << " nomFicSortie=" << nomFicSortie << " : OK !!!!!!!!!" << endl;
	  }
	  else {
	      cout << "ERREUR: Impossible d'ouvrir " << nomFicEntree<< endl;
	  }
  }
  else {
      cout << "ERREUR: Impossible d'ouvrir " << nomFicSortie << endl;
  }
  ficEntree.close();
  return;
}

//============================================================================
string fChoixNomFic() {
//============================================================================
    int val=0;
    string sNomFic="";

    cout << "choix du nom des fichiers vcf et csv'" << std::endl
			<< "1 : '" << nom1 << ".*'" << std::endl
			<< "2.: '" << nom2 << ".*'" << std::endl
			<< "3.: '" << nom3 << ".*'" << std::endl
			<< "4.autre nom " << std::endl
			<< "9.sortie " << std::endl
			;

    cin >> val;

    	if (val == 1) {
    		sNomFic=nom1;
    	} else if (val == 2) {
        	sNomFic=nom2;
    	} else if (val == 3) {
        	sNomFic=nom3;
    	} else if (val == 4) {
    	    cout << "quels autres fichiers ? " << std::endl;
    		cin >> sNomFic;
    	} else if (val == 9) {
        	sNomFic="";
    	}

	return sNomFic;

}

//============================================================================
int main(void) {
//============================================================================
    std::cout << "SALUT FRED (2024 12 12)"
			  << std::endl;

    string sNomFic = "";

    int val=0;

    while (val<9) {

    	sNomFic = fChoixNomFic();

    	if (sNomFic.length()>0) {
			cout << "1 vcf->csv " << sNomFic << std::endl
				 << "2.csv->vcf " << sNomFic << std::endl
				 << "9.sortie" << std::endl
				 ;
			cin >> val;
    	}
    	else { // sortir
			val=9;
    	}

    	if (val == 1) {
        	nomFicEntree= sNomFic+".vcf";
        	nomFicSortie= sNomFic+".fVcfVersCsv.csv";
        	fVcfVersCsv();
    	} else if (val == 2) {
        	nomFicEntree= sNomFic+".csv";
        	nomFicSortie= sNomFic+".fCsvVersVcf.vcf";
        	fCsvVersVcf();
    	}
    }

    cout << "CIAO FRED" << endl;

    return EXIT_SUCCESS;
}
