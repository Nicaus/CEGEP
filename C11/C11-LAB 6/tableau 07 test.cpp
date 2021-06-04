#include <iostream>
#include <conio.h>
#include <string>
#include <iomanip>

#include "../../Travaux/console(v1.9).h"

using namespace std;

// � METTRE DANS VISUAL STUDIO ET EX�CUTER POUR FAIRE LE TEST

int main()
{
	// CONSTANTES

	const int Q = 10;
	const string titre = "Questionnaire sur les tableaux en C++";
	const string questions[Q] =
	{
		"Un tableau, array ou variable dimensionn\202e d\202signent le m\210me concept",
		"Un tableau est une s\x82rie de variables pouvant \210tre de types diff\202rents",
		"La valeur du premier indice d'un tableau est z\202ro",
		"Un tableau peut \210tre d\202fini comme \202tant constant",
		"L'indice d'un tableau et sa taille peuvent \210tre \202gaux",
		"Lors de la d\202finition d'un tableau, sa taille peut \210tre sp\202cifi\202e par une variable",
		"La valeur de l'indice d'un tableau n'est pas v\202rifi\202e lors de la compilation",
		"Une valeur d'indice invalide provoquera toujours une violation d'acc\212s m\202moire lors de l'ex\202cution",
		"Un tableau peut \210tre initialis\202 avec des valeurs lors de sa d\202finition",
		"La taille d'un tableau est modifiable lors de l'ex\202cution"
	};

	const unsigned int r�ponses = 0x2CA;

	// VARIABLES

	bool r�ponses_lues[Q] = {};
	char r�ponse; int x, y, r�sultat;

	// 1) Poser les questions et obtenir les r�ponses

	cout << endl << setw((120 - titre.size()) / 2 + titre.size()) << titre << endl;

	for (int q = 0; q < Q; ++q)
	{
		// afficher la question
		cout << endl << endl << setw(2) << q+1 << ") " << questions[q] << " ? (V/F) : ";

		// lire un choix (O/N) valide
		x = wherex(); y = wherey();
		do { cout << (r�ponse = toupper(_getch())); gotoxy(x, y); } while (r�ponse != 'V' && r�ponse != 'F');

		r�ponses_lues[q] = r�ponse == 'V';
	}

	// 2) Comptabiliser les bonnes r�ponses

	r�sultat = 0;
	for (int q = 0, t = 1<<Q; q < Q; ++q)
		if (r�ponses_lues[q] == bool(r�ponses & (t >>= 1)))  //  ">>="  On a �videmment pas vu �a au cours !!!
			r�sultat++;

	// 3) Afficher les r�sultats

	string s = (r�sultat > 1 ? "s" : "");
	cout << "\n\n\n" << "Vous avez " << r�sultat << " bonne" << s << " r\202ponse" << s << " sur " << Q << " ==> " << r�sultat * 100.0 / Q << " %";

	_getch();
}