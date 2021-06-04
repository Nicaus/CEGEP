#include <conio.h>
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	//LES CINs
	string prenom;
	string nom;
	string numeroGroupe;

	//VARIABLES
	char carac;
	int entier;
	short entierCourt;
	long entierLong;
	float reel;
	double reelDouble;
	unsigned int sansSigne;

	//TRAITEMENT
	carac = 'A';
	entier = 75000;
	entierCourt = -42;
	entierLong = 57000;
	reel = 123.456;
	reelDouble = 12.0123456789;
	sansSigne = 54321;

	//cout << "Cours 420-C11-VM -- Travail pratique"

	//INPUT
	cout << "Taper votre pr\202nom: ";
	cin >> prenom;
	cout << "Taper votre nom: ";
	cin >> nom;
	cout << "Taper votre num\202ro de groupe: ";
	cin >> numeroGroupe;
	cout << endl;

	int x = 8;
	cout << "Essai du cadrage \205 gauche et de la notation en virgule flottante: " << endl;
	cout << left << setw(x) << entier << setw(x) << entierCourt << setw(x) << entierLong << setw(x) << sansSigne << setw(x) << carac << endl;
	cout << fixed << setprecision(2) << setw(x) << reel << setw(x) << reelDouble << setw(x) << endl << endl;

	int y = 12; 
	int z = 15;
	cout << "Essai du cadrage \205 droite et de la notation scientifique: " << endl;
	cout << right << setw(y) << entier << setw(y) << entierCourt << setw(y) << entierLong << setw(y) << sansSigne << setw(y) << carac << endl;
	cout << scientific << setprecision(5) << setw(z) << reel << setw(z) << reelDouble << setw(z) << endl << endl;

	int zz = 8;
	int zzz = 16;
	cout << "Essai de mise en page: " << endl;
	cout << hex << left;
	cout << setw(zz) << "" << setw(zzz) << "entier"	     << "= " << entier	    << endl;
	cout << setw(zz) << "" << setw(zzz) << "entierCourt" << "= " << entierCourt << endl;
	cout << setw(zz) << "" << setw(zzz) << "entierLong"  << "= " << entierLong  << endl;
	cout << setw(zz) << "" << setw(zzz) << "sansSigne"   << "= " << sansSigne   << endl;
	cout << setw(zz) << "" << setw(zzz) << "carac"	     << "= " << carac	    << endl;
	cout << fixed << setprecision(3);
	cout << setw(zz) << "" << setw(zzz) << "reel"	     << "= " << setw(10) << right << reel		<< left << endl;
	cout << setw(zz) << "" << setw(zzz) << "reelDouble"  << "= " << setw(10) << right << reelDouble << left << endl;
	cout << endl;

	cout << "Salut " << prenom << " " << nom << " du groupe " << numeroGroupe << " !" << endl;

	_getch();
}