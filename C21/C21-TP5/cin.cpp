#include <iostream>
#include <iomanip>
#include <conio.h>
#include "console(v1.9).h"
#include "cin.h"
#include "cmd.h"
#include "io.h"

/* validation des cins */

using namespace std;

int partValide(Participant& p)
{
	int no, x = MARG;
	bool valide = false;

	do {
		cin.ignore(cin.rdbuf()->in_avail());
		gotoxy(x, 28); io_texteCouleur(cvmColor::JAUNE, "Numéro du participant : ");
		cin >> no;
		if (cin.fail())
		{
			io_clean(); gotoxy(x, 28); clreol(); cin.clear();
		}
		else if (no > db_size() || no < 1)
		{
			gotoxy(x, 28); clreol();
		}
		else
			valide = true;
	}
	while (!valide);
	
	return no;
}

void montantValide(Participant& p)
{
	int x = MARG, i = p.nbDep;
	bool valide = false;
	double montant = 0;

	do {
		cin.ignore(cin.rdbuf()->in_avail());
		gotoxy(x, 25); io_texteCouleur(cvmColor::JAUNE, "Montant: ");
		cin >> montant;
		if (cin.fail()) 
		{ 
			io_clean(); gotoxy(x, 25); clreol(); cin.clear(); 
		}
		else if (montant > MAX || montant < 0)
		{
			gotoxy(x, 25); clreol();
		}
		else
			valide = true;
	}
	while (!valide);
	p.liste[i].montant = montant;

	gotoxy(x + 9, 25); clreol();
	cout << fixed << setprecision(2) << io_arrondir(montant);
}

int depValide(Participant& p)
{
	int dep, x = MARG;
	bool valide = false;

	do {
		cin.ignore(cin.rdbuf()->in_avail());
		gotoxy(x, 28); io_texteCouleur(cvmColor::JAUNE, "Dépenses no (0 pour annuler) : ");
		cin >> dep;
		if (cin.fail())
		{
			io_clean(); gotoxy(x, 28); clreol(); cin.clear();
		}
		else if (dep > p.nbDep || dep < 0)
		{
			gotoxy(x, 28); clreol();
		}
		else
			valide = true;
	}
	while (!valide);

	return dep - 1;
}