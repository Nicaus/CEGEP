#include <iostream>
#include <iomanip>
#include <conio.h>
#include <string>
#include "console(v1.9).h"

using namespace std;

int main()
{
	//CONSTANTES
	const double DOLLAR = 1.33866;
	const double EURO = 1.55739;
	const double BAHT = 0.04230;
	const double ROUPIE = 0.01815;
	const double COURONNE = 0.20920;

	//VARIABLES
	char deviseInitiale;
	char deviseConversion;
	double montantInitial;
	double montantCanadien;
	double montantConverti;
	int w = 4, x = 20, y = 26, z = 10;
	int a = 17, b = 2, c = 14;

	//ecrit
	cout << "Entrez le montant \205 convertir  : ";
	cin >> montantInitial;

	cout << "\n\n";
	cout << "Entrez la devise de ce montant : ";

	cout << "\n\n" << left;
	cout << setw(w) << " " << setw(x) << "$ -> Dollar" << setw(y) << "(Canada)" << "\n";
	cout << setw(w) << " " << setw(x) << "D -> Dollar" << setw(y) << "(\220tats-unis)" << "\n";
	cout << setw(w) << " " << setw(x) << "E -> Euro" << setw(y) << "(Union Europ\202enne)" << "\n";
	cout << setw(w) << " " << setw(x) << "B -> Baht" << setw(y) << "(Tha\213lande)" << "\n";
	cout << setw(w) << " " << setw(x) << "R -> Roupie" << setw(y) << "(Inde)" << "\n";
	cout << setw(w) << " " << setw(x) << "C -> Couronne" << setw(y) << "(Danemark)"
		<< setw(z) << "Votre choix : ";
	deviseInitiale = _getch();
	deviseInitiale = toupper(deviseInitiale);
	cout << deviseInitiale;

	cout << "\n\n";
	cout << "Entrez la devise dans lequelle on fera la conversion :";

	cout << "\n\n";
	cout << setw(w) << " " << setw(x) << "$ -> Dollar" << setw(y) << "(Canada)" << "\n";
	cout << setw(w) << " " << setw(x) << "D -> Dollar" << setw(y) << "(\220tats-unis)" << "\n";
	cout << setw(w) << " " << setw(x) << "E -> Euro" << setw(y) << "(Union Europ\202enne)" << "\n";
	cout << setw(w) << " " << setw(x) << "B -> Baht" << setw(y) << "(Tha\213lande)" << "\n";
	cout << setw(w) << " " << setw(x) << "R -> Roupie" << setw(y) << "(Inde)" << "\n";
	cout << setw(w) << " " << setw(x) << "C -> Couronne" << setw(y) << "(Danemark)"
		<< setw(z) << "Votre choix : ";
	deviseConversion = _getch();
	deviseConversion = toupper(deviseConversion);
	cout << deviseConversion;

	// Conversion de montantInitial en dollars canadiens
	if (deviseInitiale == 'D')
		montantCanadien = montantInitial * DOLLAR;
	else if (deviseInitiale == 'E')
		montantCanadien = montantInitial * EURO;
	else if (deviseInitiale == 'B')
		montantCanadien = montantInitial * BAHT;
	else if (deviseInitiale == 'R')
		montantCanadien = montantInitial * ROUPIE;
	else if (deviseInitiale == 'C')
		montantCanadien = montantInitial * COURONNE;
	else
		montantCanadien = montantInitial;

	// Conversion de montantCanadien dans la devise voulue
	if (deviseConversion == 'D')
		montantConverti = montantCanadien / DOLLAR;
	else if (deviseConversion == 'E')
		montantConverti = montantCanadien / EURO;
	else if (deviseConversion == 'B')
		montantConverti = montantCanadien / BAHT;
	else if (deviseConversion == 'R')
		montantConverti = montantCanadien / ROUPIE;
	else if (deviseConversion == 'C')
		montantConverti = montantCanadien / COURONNE;
	else
		montantConverti = montantCanadien;

	cout << "\n\n\n";
	cout << setw(a) << "Montant initial" << setw(b) << ":" << setw(c) << right << montantInitial << " " << deviseInitiale;
	cout << "\n\n";
	cout << fixed << setprecision(2);
	cout << left << setw(a) << "Montant converti" << setw(b) << ":" << setw(c) << right << montantConverti << " " << deviseConversion;

	_getch();
}
