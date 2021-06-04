#include <iomanip>
#include <iostream>
#include "console(v1.9).h"
#include <string>
#include <conio.h>

using namespace std;

int main()
{
	//setw
	int u = 51, v = 35, w = 11, x = 8, y = 37, z = 23;

	//variables etape 1
	char formatPapier, typeImpression;
	int nbOri, nbExe, nbImpR, nbImpRV, document, reste;

	//constantes et variables etape 2
	const double PRIX_8x11R = 31, PRIX_8x11RV = 60, PRIX_11x17R = 61, PRIX_11x17RV = 100;
	double coutR = 0, coutRV = 0;

	//const et var etape 3
	char typePapier;
	const double PRIX_PAPIER_1 = 20.50, PRIX_PAPIER_2 = 67.34, PRIX_PAPIER_3 = 122.94;
	double coutPapier = 0;

	//const et var etape 4
	char aPerforer, typeFaconnage;
	const double PRIX_BROCHE = 0.03, PRIX_ENCOLLER = 0.6, PRIX_TABLETTE = 0.35, PRIX_DOSCHEVAL = 0.10, PRIX_PERFORER = 3;
	double coutFaconnage = 0;

	//const et var etape 5
	const double TPS = 0.05, TVQ = 0.09975;
	double coutProduction, coutTotal;

	//lire
	cout << left;
	cout << setw(v) << "Nombres d'originaux" << " : ";
	cin >> nbOri;
	cout << setw(v) << "Nombre d'examplaires \205 reproduire" << " : ";
	cin >> nbExe;
	cout << endl << endl;
	//e1
	cout << "Format du papier :" << endl << setw(x) << " "
		<< setw(y) << "1. 8\253x11" << endl << setw(x) << " "
		<< setw(y) << "2. 8\253x14" << endl << setw(x) << " "
		<< setw(y) << "3. 11x17   " << setw(x) << "Votre choix : ";
	formatPapier = _getch();
	formatPapier = toupper(formatPapier);
	cout << formatPapier;
	cout << endl << endl;
	//e1
	cout << "Type d'impression :" << endl << setw(x) << " "
		<< setw(y) << "R. recto" << endl << setw(x) << " "
		<< setw(y) << "V. recto - verso" << setw(x) << "Votre choix : ";
	typeImpression = _getch();
	typeImpression = toupper(typeImpression);
	cout << typeImpression;
	cout << endl << endl;
	//e3
	cout << "Type de papier :" << endl << setw(x) << " "
		<< setw(y) << "1. Repro + gris" << endl << setw(x) << " "
		<< setw(y) << "2. Rolland \202volution glacier" << endl << setw(x) << " "
		<< setw(y) << "3. Wassau royal, fribre texte \202tain" << setw(x) << "Votre choix : ";
	typePapier = _getch();
	typePapier = toupper(typePapier);
	cout << typePapier;
	cout << endl << endl;
	//e4
	cout << setw(45) << "Voulez-vous des documents perfor\202s ? (O/N)" << "Votre choix : ";
	aPerforer = _getch();
	aPerforer = toupper(aPerforer);
	cout << aPerforer;
	cout << endl << endl;
	//e4
	cout << "Type de faconnage :" << endl << setw(x) << " "
		<< setw(y) << "1. Broche en coin" << endl << setw(x) << " "
		<< setw(y) << "2. Encoller avec ruban" << endl << setw(x) << " "
		<< setw(y) << "3. Tablettes" << endl << setw(x) << " "
		<< setw(y) << "4. Broche \205 dos de cheval" << endl << setw(x) << " "
		<< setw(y) << "5. Aucun" << setw(x) << "Votre choix : ";
	typeFaconnage = _getch();
	typeFaconnage = toupper(typeFaconnage);
	cout << typeFaconnage;
	cout << endl << endl << endl;

	cout << "Appuyez sur une touche pour continuer ...";

	_getch();
	clrscr();
	 //etape 1
	switch (typeImpression) {
	case 'R':
		if (formatPapier == '1' || formatPapier == '2') {
			nbImpR = nbOri * nbExe;
			nbImpRV = 0;
		}
		else if (formatPapier == '3') {
			if (nbOri % 2 == 1)
				nbOri += 1;
			else {
				nbImpR = (nbOri * nbExe) / 2;
				nbImpRV = 0;
			}
		}
		break;
	case 'V':
		if (formatPapier == '1' || formatPapier == '2') {
			if (nbOri % 2 == 1) {
				nbImpR = nbExe;
				nbImpRV = ((nbOri - 1) * nbExe) / 2;
			}
			else {
				nbImpR = 0;
				nbImpRV = (nbOri * nbExe) / 2;
			}
		}
		else if (formatPapier == '3') {
			reste = nbOri % 4;
			if (reste == 0) {
				nbImpR = 0;
				nbImpRV = (nbOri * nbExe) / 4;
			}
			else if (reste == 1 || reste == 2) {
				nbImpR = nbExe;
				nbImpRV = ((nbOri - reste) * nbExe) / 4;
			}
			else if (reste == 3) {
				nbImpR = 0;
				nbImpRV = ((nbOri + 1) * nbExe) / 4;
			}
		}
		break;
	}

	//etape 2
	if (formatPapier == '1' || formatPapier == '2') {
		coutR = nbImpR * (PRIX_8x11R / 1000);
		coutRV = nbImpRV * (PRIX_8x11RV / 1000);
	}
	else if (formatPapier == '3') {
		coutR = nbImpR * (PRIX_11x17R / 1000);
		coutRV = nbImpRV * (PRIX_11x17RV / 1000);
	}

	//etape 3 
	document = nbImpR + nbImpRV; //nombres d'impressions total
	if (typePapier == '1')
		coutPapier = (document * (PRIX_PAPIER_1 / 1000)) / 2;
	else if (typePapier == '2')
		coutPapier = document * (PRIX_PAPIER_2 / 1000);
	else if (typePapier == '3')
		coutPapier = document * (PRIX_PAPIER_3 / 1000);

	//etape 4
	if (typeFaconnage == '1')
		coutFaconnage = PRIX_BROCHE * nbExe;
	else if (typeFaconnage == '2')
		if (formatPapier == '1' || formatPapier == '2')
			coutFaconnage = PRIX_ENCOLLER * nbExe;
		else
			coutFaconnage = 0;
	else if (typeFaconnage == '3')
		coutFaconnage = PRIX_TABLETTE * nbExe;
	else if (typeFaconnage == '4')
		if (formatPapier == '3')
			coutFaconnage = PRIX_DOSCHEVAL * nbExe;
		else
			coutFaconnage = 0;
	else if (typeFaconnage == '5')
		coutFaconnage = 0;
	if (aPerforer == 'O')
		coutFaconnage += (document * (PRIX_PERFORER / 1000));

	//etape 5
	coutProduction = coutR + coutRV + coutPapier + coutFaconnage;
	coutTotal = coutProduction + (coutProduction * TPS) + (coutProduction * TVQ);

	//affichage de resultat
	cout << "\n\n\n\n";
	cout << fixed << setprecision(2);
	cout << "FACTURE" << endl << endl << endl
		<< setw(y) << "  Cout des impressions recto :" << setw(z) << right << coutR << " $" << left << endl
		<< setw(y) << "  Cout des impressions recto-verso :" << setw(z) << right << coutRV << " $" << left << endl << endl
		<< setw(y) << "  Cout du papier :" << setw(z) << right << coutPapier << " $" << left <<endl
		<< setw(y) << "  Cout du faconnage :" << setw(z) << right << coutFaconnage << " $" << left << endl
		<< setw(u) << " " << setw(12) << right << setfill('-') << " " << setfill(' ') << left << endl << endl
		<< setw(y) << "  Cout de production :" << setw(z) << right << coutProduction << " $" << left << endl
		<< setw(u) << " " << setw(12) << right << setfill('=') << " " << setfill(' ') << left << endl << endl
		<< setw(y) << "Cout total :" << setw(z) << right << coutTotal << " $" << endl;

	_getch();
}