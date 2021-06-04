#include <iostream>
#include <conio.h>
#include <string>
#include <iomanip>

#include "../../Travaux/console(v1.9).h"

using namespace std;

// À METTRE DANS VISUAL STUDIO ET EXÉCUTER POUR FAIRE LE TEST

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

	const unsigned int réponses = 0x2CA;

	// VARIABLES

	bool réponses_lues[Q] = {};
	char réponse; int x, y, résultat;

	// 1) Poser les questions et obtenir les réponses

	cout << endl << setw((120 - titre.size()) / 2 + titre.size()) << titre << endl;

	for (int q = 0; q < Q; ++q)
	{
		// afficher la question
		cout << endl << endl << setw(2) << q+1 << ") " << questions[q] << " ? (V/F) : ";

		// lire un choix (O/N) valide
		x = wherex(); y = wherey();
		do { cout << (réponse = toupper(_getch())); gotoxy(x, y); } while (réponse != 'V' && réponse != 'F');

		réponses_lues[q] = réponse == 'V';
	}

	// 2) Comptabiliser les bonnes réponses

	résultat = 0;
	for (int q = 0, t = 1<<Q; q < Q; ++q)
		if (réponses_lues[q] == bool(réponses & (t >>= 1)))  //  ">>="  On a évidemment pas vu ça au cours !!!
			résultat++;

	// 3) Afficher les résultats

	string s = (résultat > 1 ? "s" : "");
	cout << "\n\n\n" << "Vous avez " << résultat << " bonne" << s << " r\202ponse" << s << " sur " << Q << " ==> " << résultat * 100.0 / Q << " %";

	_getch();
}