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
// void fDecoupeLigneCsv(string ligne)
// void fDecoupeLigneVcf(string ligne)
// void fDecoupeSousLigne(string sousLigne)
// string fTranscodeTexte(string sTexte)
// string fTranscodeTexte1(string sTexte, string sCode, string sDecode)
//============================================================================

#include <iostream>     // std::cout
#include <fstream>      // std::ifstream

using namespace std;

string sElement1="";
string sElement2="";
string sElement3="";
string sElement4="";
string sElement5="";

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

string sT="";
string sNT="";
string nomFicEntree="";
string nomFicSortie="";
string nom1="vcard";
string nom2="test";
string nom3="adr_col";


//============================================================================
string fTranscodeTexte1(string sTexte, string sCode, string sDecode) {
// objectif: trouver la chaine "sCode" dans le texte "sTexte" et le remplacer par "sDecode"
//============================================================================

	//	cout<<"fTranscodeTexte1, in  : " << sTexte << "," << sCode << "," << sDecode << "," << endl;
	std::string sRetour=sTexte;
	std::size_t found =sRetour.find(sCode);
	while(found!=std::string::npos) {
		sRetour.replace(found, sCode.length(), sDecode);
		found =sRetour.find(sCode);
	}
//	cout<<"fTranscodeTexte, out : " << sRetour << endl;
return sRetour;
}


//============================================================================
string fTranscodeTexte(string sTexte) {
	//============================================================================
//	cout<<"fTranscodeTexte, in  : " << sTexte << endl;
	string sRetour=sTexte;

// d'abord les "=C3"

//accent des majuscules
	sRetour=fTranscodeTexte1(sRetour, "=C3=89", "É");

//accent du a
	sRetour=fTranscodeTexte1(sRetour, "=C3=A0", "à");
	sRetour=fTranscodeTexte1(sRetour, "=C3=A2", "â");

//accent du c
	sRetour=fTranscodeTexte1(sRetour, "=C3=A7", "ç");

//accent du e
	sRetour=fTranscodeTexte1(sRetour, "=C3=A8", "è");
	sRetour=fTranscodeTexte1(sRetour, "=C3=A9", "é");
	sRetour=fTranscodeTexte1(sRetour, "=C3=AA", "ê");
	sRetour=fTranscodeTexte1(sRetour, "=C3=AB", "ë");

//accent du i
	sRetour=fTranscodeTexte1(sRetour, "=C3=AE", "î");
	sRetour=fTranscodeTexte1(sRetour, "=C3=AF", "ï");

//accent du o
	sRetour=fTranscodeTexte1(sRetour, "=C3=B4", "ô");

//accent du u
	sRetour=fTranscodeTexte1(sRetour, "=C3=B9", "ù");
	sRetour=fTranscodeTexte1(sRetour, "=C3=BB", "û");

// ensuite les <> "=C3"

	sRetour=fTranscodeTexte1(sRetour, "=20", " ");
	sRetour=fTranscodeTexte1(sRetour, "=26", "&");
	sRetour=fTranscodeTexte1(sRetour, "=28", "(");
	sRetour=fTranscodeTexte1(sRetour, "=29", ")");
	sRetour=fTranscodeTexte1(sRetour, "=2E", ".");

	sRetour=fTranscodeTexte1(sRetour, "=30", "0");
	sRetour=fTranscodeTexte1(sRetour, "=31", "1");
	sRetour=fTranscodeTexte1(sRetour, "=32", "2");
	sRetour=fTranscodeTexte1(sRetour, "=33", "3");
	sRetour=fTranscodeTexte1(sRetour, "=34", "4");
	sRetour=fTranscodeTexte1(sRetour, "=35", "5");
	sRetour=fTranscodeTexte1(sRetour, "=36", "6");
	sRetour=fTranscodeTexte1(sRetour, "=37", "7");
	sRetour=fTranscodeTexte1(sRetour, "=38", "8");
	sRetour=fTranscodeTexte1(sRetour, "=39", "9");

	sRetour=fTranscodeTexte1(sRetour, "=41", "A");
	sRetour=fTranscodeTexte1(sRetour, "=42", "B");
	sRetour=fTranscodeTexte1(sRetour, "=43", "C");
	sRetour=fTranscodeTexte1(sRetour, "=44", "D");
	sRetour=fTranscodeTexte1(sRetour, "=45", "E");
	sRetour=fTranscodeTexte1(sRetour, "=46", "F");
	sRetour=fTranscodeTexte1(sRetour, "=47", "G");
	sRetour=fTranscodeTexte1(sRetour, "=48", "H");
	sRetour=fTranscodeTexte1(sRetour, "=49", "I");
	sRetour=fTranscodeTexte1(sRetour, "=4A", "J");
	sRetour=fTranscodeTexte1(sRetour, "=4B", "K");
	sRetour=fTranscodeTexte1(sRetour, "=4C", "L");
	sRetour=fTranscodeTexte1(sRetour, "=4D", "M");
	sRetour=fTranscodeTexte1(sRetour, "=4E", "N");
	sRetour=fTranscodeTexte1(sRetour, "=4F", "O");

	sRetour=fTranscodeTexte1(sRetour, "=50", "P");
	sRetour=fTranscodeTexte1(sRetour, "=51", "Q");
	sRetour=fTranscodeTexte1(sRetour, "=52", "R");
	sRetour=fTranscodeTexte1(sRetour, "=53", "S");
	sRetour=fTranscodeTexte1(sRetour, "=54", "T");
	sRetour=fTranscodeTexte1(sRetour, "=55", "U");
	sRetour=fTranscodeTexte1(sRetour, "=56", "V");
	sRetour=fTranscodeTexte1(sRetour, "=57", "W");
	sRetour=fTranscodeTexte1(sRetour, "=58", "X");
	sRetour=fTranscodeTexte1(sRetour, "=59", "Y");
	sRetour=fTranscodeTexte1(sRetour, "=5A", "Z");

	sRetour=fTranscodeTexte1(sRetour, "=61", "a");
	sRetour=fTranscodeTexte1(sRetour, "=62", "b");
	sRetour=fTranscodeTexte1(sRetour, "=63", "c");
	sRetour=fTranscodeTexte1(sRetour, "=64", "d");
	sRetour=fTranscodeTexte1(sRetour, "=65", "e");
	sRetour=fTranscodeTexte1(sRetour, "=66", "f");
	sRetour=fTranscodeTexte1(sRetour, "=67", "g");
	sRetour=fTranscodeTexte1(sRetour, "=68", "h");
	sRetour=fTranscodeTexte1(sRetour, "=69", "i");
	sRetour=fTranscodeTexte1(sRetour, "=6A", "j");
	sRetour=fTranscodeTexte1(sRetour, "=6B", "k");
	sRetour=fTranscodeTexte1(sRetour, "=6C", "l");
	sRetour=fTranscodeTexte1(sRetour, "=6D", "m");
	sRetour=fTranscodeTexte1(sRetour, "=6E", "n");
	sRetour=fTranscodeTexte1(sRetour, "=6F", "o");

	sRetour=fTranscodeTexte1(sRetour, "=70", "p");
	sRetour=fTranscodeTexte1(sRetour, "=71", "q");
	sRetour=fTranscodeTexte1(sRetour, "=72", "r");
	sRetour=fTranscodeTexte1(sRetour, "=73", "s");
	sRetour=fTranscodeTexte1(sRetour, "=74", "t");
	sRetour=fTranscodeTexte1(sRetour, "=75", "u");
	sRetour=fTranscodeTexte1(sRetour, "=76", "v");
	sRetour=fTranscodeTexte1(sRetour, "=77", "w");
	sRetour=fTranscodeTexte1(sRetour, "=78", "x");
	sRetour=fTranscodeTexte1(sRetour, "=79", "y");
	sRetour=fTranscodeTexte1(sRetour, "=7A", "z");

	sRetour=fTranscodeTexte1(sRetour, "=A3", ":");

//	cout<<"fTranscodeTexte, out : " << sRetour << endl;
return sRetour;
}


//============================================================================
void fDecoupeSousLigne(string sousLigne) {
	//============================================================================
	std::string separateur = ";";
	string sRetour="";
    sElement1 = "";
    sElement2 = "";
    sElement3 = "";
    sElement4 = "";
    sElement5 = "";


	size_t pos = 0;
	int numElement=0;
	while ((pos = sousLigne.find(separateur)) != std::string::npos) {
	    numElement+=1;
	    if (numElement==1) {
		    sElement1 = sousLigne.substr(0, pos);
	    } else if (numElement==2) {
		    sElement2 = sousLigne.substr(0, pos);
	    } else if (numElement==3) {
		    sElement3 = sousLigne.substr(0, pos);
	    }else if (numElement==4) {
		    sElement4 = sousLigne.substr(0, pos);
	    }
	    sousLigne.erase(0, pos + separateur.length());
		//std::cout << "=" << sousLigne << "=" ;
	}
    sElement5 = sousLigne;

    // Compacter
	if (sElement1.length()<1) { sElement1=sElement5;
	} else if (sElement2.length()<1) {sElement2=sElement5;
    } else if (sElement3.length()<1) {sElement3=sElement5;
    } else if (sElement4.length()<1) {sElement4=sElement5;
    }
	cout<<"fDecoupeSousLigne: " << sElement1 <<',' << sElement2 <<',' << sElement3 <<',' << sElement4 <<',' << endl;
return;
}
//============================================================================
void fDecoupeLigneVcf(string ligne) {
	//============================================================================
	std::string separateur = ":";

	size_t pos = 0;
	std::string tabAttribut="";
	std::string tabValeur="";
	
	string attribut1="";
	string attribut2="";

	string valeur1="";
	string valeur2="";
	string valeur3="";
	string valeur4="";

	// decoupage de la ligne: �l�ment 1
	pos = ligne.find(separateur);
	tabAttribut = ligne.substr(0, pos);
	// Majuscule
	for (auto & c: tabAttribut) c = toupper(c);

	// couper la ligne
	ligne.erase(0, pos + separateur.length());
	// dernier element=le reste de la ligne: �l�ment 2
	tabValeur= ligne;

	//attribut de la ligne
	fDecoupeSousLigne(tabAttribut);
	attribut1=sElement1;
	attribut2=sElement2;


	//valeurs de la ligne
	if ((attribut1.compare("N")==0)
	||  (attribut1.compare("ORG")==0)
			)
	{
		fDecoupeSousLigne(tabValeur);
		valeur1=sElement1;
		valeur2=sElement2;
		valeur3=sElement3;
		valeur4=sElement4;
	}

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
	} else if (attribut1.compare("ORG")==0){
		sO1=valeur1;
		sO2=valeur2;
		sO3=valeur3;

	} else if (attribut1.compare("TITLE")==0){
		sT=tabValeur;
	} else if (attribut1.compare("NOTE")==0){
		sNT=tabValeur;
	} else {
		//RAZ element2
		tabValeur="";
		if (tabAttribut.compare("BEGIN")==0) {
		   cout << "-----------------------------------------------" << endl;
 	    }
	}

	sN1=fTranscodeTexte(sN1);
	sN2=fTranscodeTexte(sN2);
	sN3=fTranscodeTexte(sN3);
	sN4=fTranscodeTexte(sN4);
	//display
	if (tabValeur.length()>0){
		  cout << " -> fDecoupeLigneVcf: "
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
		  << ";sT:" 		  << sT
		  << ";sNT:" 		  << sNT
		  << endl
		  ;
	}
}

//============================================================================
void fDecoupeLigneCsv(string ligne) {
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
		  fDecoupeLigneCsv(ligne);
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
		  ficSortie	<< "TITLE:" << sT<< endl;
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
			  fDecoupeLigneVcf(ligne);

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
				<< sT<< '\t'
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
				sT="";
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
