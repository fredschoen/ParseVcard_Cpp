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
// void fDecouperLigneCsv(string ligne)
// void fDecouperLigneVcf(string ligne)
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
string sNM="";
string sTC="";
string sTH="";
string sTW="";
string sE1="";
string sE2="";
string sE3="";

string sO1="";
string sO2="";
string sO3="";

string sA1="";
string sA2="";
string sA3="";
string sA4="";
string sA5="";
string sA6="";
string sA7="";

string sNT="";
string sTI="";

string nomFicEntree="";
string nomFicSortie="";

string nom1="vcard";
string nom2="test";
string nom3="adr_col";


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
	std::string separateur = ";";
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
	while ((pos = sousLigne.find(separateur)) != std::string::npos) {
		cout << "fSeparerElements sousLigne<" << sousLigne << ">" << endl;
	    numElement+=1;
	    if (numElement==1) {
		    sElement1 = sousLigne.substr(0, pos);
		    sElement2 = sousLigne.substr(pos+ separateur.length(), sousLigne.length());
	    } else if (numElement==2) {
		    sElement2 = sousLigne.substr(0, pos);
		    sElement3 = sousLigne.substr(pos+ separateur.length(), sousLigne.length());
	    } else if (numElement==3) {
		    sElement3 = sousLigne.substr(0, pos);
		    sElement4 = sousLigne.substr(pos+ separateur.length(), sousLigne.length());
	    }else if (numElement==4) {
		    sElement4 = sousLigne.substr(0, pos);
		    sElement5 = sousLigne.substr(pos+ separateur.length(), sousLigne.length());
	    }else if (numElement==5) {
		    sElement5 = sousLigne.substr(0, pos);
		    sElement6 = sousLigne.substr(pos+ separateur.length(), sousLigne.length());
	    }else if (numElement==6) {
		    sElement6 = sousLigne.substr(0, pos);
		    sElement7 = sousLigne.substr(pos+ separateur.length(), sousLigne.length());
	    }else if (numElement==7) {
		    sElement7 = sousLigne;
	    }
	    sousLigne.erase(0, pos + separateur.length());
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
void fDecouperLigneVcf(string ligne) {
	//============================================================================
	std::string separAttributValeur = ":";

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
	ligne =fTranscoderDebutLigne(ligne, "ADR;HOME;", "ADR;HOME:");
	ligne =fTranscoderDebutLigne(ligne, "NOTE;", "NOTE:");

	// decoupage de la ligne: �l�ment 1
	pos = ligne.find(separAttributValeur);
	tabAttribut = ligne.substr(0, pos);

	// Majuscules
	for (auto & c: tabAttribut) c = toupper(c);

	// effacer les attributs dans "ligne"
	ligne.erase(0, pos + separAttributValeur.length());
	// dernier element=le reste de la ligne: �l�ment 2
	tabValeur= fTranscoderTexte(ligne);

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
		if (sE1==""){
		       sE1=tabValeur;
	    } else if (sE2==""){
	    	   sE2=tabValeur;
	    } else sE3=tabValeur;
	} else if (attribut1.compare("ADR")==0){

		if (attribut2.compare("HOME")==0){
			sA1=valeur1;
			sA2=valeur2;
			sA3=valeur3;
			sA4=valeur4;
			sA5=valeur5;
			if (valeur6.length()>0) {
			sA6="'"+valeur6; //code postal
			}
			sA7=valeur7;
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
		  << ";sE1:"		  << sE1
		  << ";sE2:"		  << sE2
		  << ";sE3:"		  << sE3
		  << ";sO1:"		<< sO1
		  << ";sO2:"		<< sO2
		  << ";sO3:"		<< sO3
		  << ";sA1:"		<< sA1
		  << ";sA2:"		<< sA2
		  << ";sA3:"		<< sA3
		  << ";sA4:"		<< sA4
		  << ";sA5:"		<< sA5
		  << ";sA6:"		<< sA6
		  << ";sA7:"		<< sA7
		  << ";sTI:" 		  << sTI
		  << ";sNT:" 		  << sNT
		  << endl
		  ;
	}
}

//============================================================================
void fDecouperLigneCsv(string ligne) {
	//============================================================================
	std::string separateur = "";
	separateur += '\t';
	size_t pos = 0;

	//chercher + charger + couper
	pos = ligne.find(separateur);
	sN1 = ligne.substr(0, pos);
	ligne.erase(0, pos + separateur.length());

	//chercher + charger + couper
	pos = ligne.find(separateur);
	sN2 = ligne.substr(0, pos);
	ligne.erase(0, pos + separateur.length());

	  cout << "sN1:" << sN1
	  << endl
	  << "sN2:" << sN2
	  << endl
	  ;

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
  string ligne="";

  if  (!ficEntree){
      cout << "ERREUR: Impossible d'ouvrir ficEntree" << nomFicEntree<< endl;
      return;
  }
  if  (!ficSortie){
      cout << "ERREUR: Impossible d'ouvrir ficSortie" << nomFicSortie<< endl;
      ficEntree.close();
      return;
  }

  while(getline(ficEntree, ligne)) {
	  if (ligne.length()>5) { // moins de 5 car <=> n'importe quoi dans la ligne!!
		  fDecouperLigneCsv(ligne);
		  ficSortie	<< "BEGIN:VCARD"<< endl;
		  ficSortie	<< "VERSION:2.1"<< endl;
		  ficSortie	<< "N:" << sN1 << ";" << sN2 << ";;;"<< endl;
		  ficSortie	<< "TEL;CELL:" << sTC<< endl;
		  ficSortie	<< "TEL;HOME:" << sTH<< endl;
		  ficSortie	<< "TEL;WORK:" << sTW<< endl;
		  ficSortie	<< "EMAIL;HOME:" << "empers@fff.com"<< endl;
		  ficSortie	<< "EMAIL;WORK:" << "empri@fff.com"<< endl;
		  ficSortie	<< "ADR;HOME:" << ";" << "uuu" << ";" << "Rrr" << ";" << "Vvv" << ";" << "zz" << ";" << "67000" << ";" << "Pay"<< endl;
		  ficSortie	<< "ADR;WORK:" << ";" << "uuu" << ";" << "Rrr" << ";" << "Vvv" << ";" << "zz" << ";" << "67000" << ";" << "Pay"<< endl;
		  ficSortie	<< "ORG:" << sO1 << ";" << sO2<< endl;
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

	  << "EMAIL_1"<< '\t'
	  << "EMAIL_2"<< '\t'
	  << "EMAIL_3"<< '\t'

	  << "ORG1"<< '\t'
	  << "ORG2"<< '\t'
	  << "ORG3"<< '\t'

	  << "ADR1"<< '\t'
	  << "ADR2"<< '\t'
	  << "ADR3"<< '\t'
	  << "ADR4"<< '\t'
	  << "ADR5"<< '\t'
	  << "ADR6"<< '\t'
	  << "ADR7"<< '\t'

	  << "TITLE"<< '\t'
	  << "NOTE"
	  << endl
	  ;

	  if  (ficEntree){
	      cout << "d�but>>>>>>>>>>>>>>>>>>>" << endl;
		  string ligne; //Une variable pour stocker les lignes lues
		  int nLigne=0;
		  //Tant qu'on n'est pas � la fin, on lit
		  // while(getline(ficEntree, ligne, '\r'))
		  while(getline(ficEntree, ligne)) {
			  nLigne+=1;
			  cout << "getligne " << nLigne << "=" << ligne<< endl;
			  fDecouperLigneVcf(ligne);

			  // en fin de card on ecrit
			  // Majuscule
			  for (auto & c: ligne) c = toupper(c);

			  if (  ligne.compare("END:VCARD")==0   )
			  {
				ficSortie
				<< sN1 << '\t'
				<< sN2 << '\t'
				<< sN3 << '\t'
				<< sN4 << '\t'
				<< "'" << sTC<< '\t'
				<< "'" << sTH<< '\t'
				<< "'" << sTW<< '\t'
				<< sE1<< '\t'
				<< sE2<< '\t'
				<< sE3<< '\t'
				<< sO1<< '\t'
				<< sO2<< '\t'
				<< sO3<< '\t'
				<< sA1<< '\t'
				<< sA2<< '\t'
				<< sA3<< '\t'
				<< sA4<< '\t'
				<< sA5<< '\t'
				<< sA6<< '\t'
				<< sA7<< '\t'
				<< sTI<< '\t'
				<< sNT
				<< endl
				;

				sN1="";
				sN2="";
				sN3="";
				sN4="";
				sTC="";
				sTH="";
				sTW="";
				sE1="";
				sE2="";
				sE3="";
				sO1="";
				sO2="";
				sO3="";
				sA1="";
				sA2="";
				sA3="";
				sA4="";
				sA5="";
				sA6="";
				sA7="";

				sNT="";
				sTI="";

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
