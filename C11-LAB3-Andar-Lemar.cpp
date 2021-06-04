#include <iostream>
#include <iomanip>
#include <conio.h>
#include <string>
#include "console(v1.9).h"

using namespace std;

int main()
{
	//constant
	const int LARG = 120;
	const string TITRE = "HYDRO-QU\220BEC";
	const double TPS = 0.05;
	const double TVQ = 0.09975;
	const double TARIFPARJOUR = 0.4064;
	const double TARIF_1 = 0.0608;
	const double TARIF_2 = 0.0938;

	//variables
	int x = 41;
	int y = 61;
	int xx = 31;
	int yy = 14;
	int zz = 5;
	unsigned int nbKwHres;
	unsigned int nbJour;
	double prix_1, prix_2;
	double tps, tvq, redevance, totalFacture;
	size_t larg_titre = TITRE.size();
	string nom, prenom;

	//action
	cout << right << setw((LARG - larg_titre) / 2 + larg_titre) << TITRE << endl << endl << endl;
	cout << left << setw(x) << "Quel est votre pr\202nom" << ": ";
	getline(cin, prenom);

	cout << "\n";
	cout << setw(x) << "Quel est votre nom" << ": ";
	getline(cin, nom);

	cout << "\n\n";
	cout << setw(x) << "Quelle est votre consommation en kWh" << ": ";
	cin >> nbKwHres;

	cout << "\n";
	cout << setw(x) << "Sur combien de jours" << ": ";
	cin >> nbJour;

	cout << "\n\n\n";
	cout << right << setw(y) << "Appuyer sur une touche pour continuer";

	if (nbKwHres > (40 * nbJour)) {
		prix_1 = TARIF_1 * (40 * nbJour);
		prix_2 = TARIF_2 * (nbKwHres - (40 * nbJour));
	}
	else {
		prix_1 = TARIF_1 * nbKwHres;
		prix_2 = 0;
	}

	redevance = nbJour * TARIFPARJOUR;
	tps = (prix_1 + prix_2 + redevance) * TPS;
	tvq = (prix_1 + prix_2 + redevance) * TVQ;
	totalFacture = prix_1 + prix_2 + redevance + tps + tvq;

	_getch();
	clrscr();

	cout << setw((LARG - larg_titre) / 2 + larg_titre) << TITRE << endl << endl << endl;
	cout << "FACTURE D'\220LECTRICIT\220 DE : " << prenom << " " << nom;

	cout << fixed << setprecision(2);

	cout << "\n\n\n";
	cout << left << setw(xx) << "REDEVANCE D'ABONNEMENT: " << right << setw(yy) << redevance << " $" << " " << setw(zz) << nbJour << " jour(s) x " << "0.4064" << " $";

	cout << "\n\n\n"; 
	cout << left << setw(xx) << "CONSOMMATION: " << right << setw(zz + yy + 5) << nbKwHres << " kWh";

	cout << "\n\n";
	cout << left << setw(xx) << "  Les 40 premiers kWh\\jour: " << right << setw(yy) << prix_1 << " $" << "   " << setw(zz) << 40 * nbJour << " kWh x " << "0.0608" << " $";
	
	cout << "\n\n";
	cout << left << setw(xx) << "  Le reste de la consommation: " << right << setw(yy) << prix_2 << " $" << "   " << setw(zz) << nbKwHres - (40 * nbJour) << " kWh x " << "0.9338" << " $";

	cout << "\n\n\n";
	cout << left << setw(xx) << "TPS: " << setw(yy) << right << tps << " $" << "  " << setw(zz) << "5 %";

	cout << "\n\n";
	cout << left << setw(xx) << "TVQ: " << setw(yy) << right << tvq << " $" << "    " << setw(zz) << "9.975 %";

	cout << "\n\n";
	cout << left << setw(xx) << " " << setfill('-') << setw(yy + 2) << " " << setfill(' ');

	cout << "\n";
	cout << left << setw(xx) << "TOTAL: " << right << setw(yy) << totalFacture << " $";

	_getch();
}