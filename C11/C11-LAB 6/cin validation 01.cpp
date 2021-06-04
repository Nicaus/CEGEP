#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>
#include <iomanip>

#include "../../Travaux/console(v1.9).h"

using namespace std;

/*

	CIN -- FONCTIONNEMENT GÉNÉRAL

	- Tous les caractères émis par le clavier sont conservés, en ordre d'arrivée, dans une mémoire tampon qui appartient à la console de Windows.
	  Ce processus est automatiquement géré par l'OS. Les fonctions _getch(), _getche() et _kbhit() interagissent avec ce tampon.

	- Le cin possède son propre tampon d'input et se sert du tampon de la console pour s'approvisonner en caractères.
	  Il y a donc deux tampons qui peuvent être manipulés par votre programme, celui de la console et celui du cin.

	- Le CIN extrait les caractères, un à un de son tampon, pour extraire la prochaine information à mettre dans une variable.
	  Le type de la variable V ( ex: cin >> V ) influance l'extraction attentue


	A) L'approvisionnement en caractères

		- Le CIN inspect toujours en premier son propre tampon à la recherche des caractères à extraire.
	
		- Si celui-ci est vide, il ira s'approvisionner dans le tampon de la console, en retirant, dans l'ordre,
		   tous les caractères disponibles jusqu'au premier caractère de fin de ligne rencontré ('\n').
		   
		- Sans ce caractère de fin de ligne, ce processus restera en attente de l'avoir.

				si ( tampon_cin est vide )

					faire

						c = _getch()		// extraction dans le tampon de la console Windows
						tampon_cin += c		// concaténation dans le tampon du cin

						// ... tel que l'affichage de c

					tant que ( c != '\n' )

		- Une fois les caractères transférés d'un tampon à l'autre, le CIN peut poursuivre son traitement d'extraction B).

		- Par contre, dès que le CIN aura besoin de nouveaux caractères pour son tampon, ce processus d'approvisionnement recommencera jusqu'au prochain ('\n')
		

	B) Extraction des caractères utiles du tampon du CIN

		- L'extraction des caractères utiles est gouvernée par le TYPE d'information qui doit être obtenue

			double V;

			cin >> V;
			
			- ici, le TYPE d'information à extraire, à partir du début du tampon du CIN, doit être une suite de caractères qui exprime un réel (double)
			
				ex: 234
				ex: -45.567

		- L'extaction se termine sur le premier caractère rencontré non admissible, lequel restera dans le tampon


		NOTES:

		1) L'extraction ignorera tous les caractères ( ' ' , '\t' , '\n' ) qui se présenteraient, dans le tampon, dès le début, en les retirant

		2) Si le tampon est vide à nouveau, l'approvisionnement recommence

		3) Si le premier caractère rencontré est inadmissible, au regard du TYPE de V, le CIN échoue et V est reinitialisée à zéro ou l'équivalent.

		4) Si le CIN échoue, il faut le remettre en marche:  cin.fail() permet de savoir s'il a échoué, et cin.clear() de le remettre en marche

*/




int main()
{
	// EXEMPLE #1 -- INPUT NORMAL SANS ERREUR

	int entier;

	cout << "un entier ? : ";

	cin >> entier;				// hypothèse: l'usager tape: "123.45ABC\n" qui se retrouve dans le tampon du cin

	// constat 1) : le cin a extrait "123" du tampon et affecté le nombre 123 à la variable entier
	// constat 2) : il reste dans le tampon du cin ".45ABC\n" qui servira au prochain cin, s'il y a lieu
	
	

	// EXEMPLE #2 -- VIDER LE TAMPON DU CIN AU BESOIN

	cin.ignore(cin.rdbuf()->in_avail());	// sans commentaire !

	// constat 1) : le tampon du cin est maintenant vide ==> ""
	// constat 2) : le prochain cin devra s'approvisionner dans le tampon de la console



	// EXEMPLE #3 -- NPUT NORMAL SANS ERREUR -- LIRE DEUX NOMBRES AVEC UNE CASCADE DE CIN 

	double n, m;

	cout << "deux nombres ? : ";

	cin >> n >> m;		// note 1: idem que: cin >> n; cin >> m;    note 2: hypothèse: l'usager tape "12 78 \n" qui se retrouve dans le tampon du cin

	// constat 1) : le cin a extrait "12" ==> n, et le tampon == " 78 \n"
	// constat 2) : le cin a extrait "78" ==> m, et le tampon == " \n"



	// EXEMPLE #4 -- VÉRIFIER QUE LE CIN N'A PAS ÉCHOUÉ À FAIRE L'EXTRACTION AVEC LA FONCTION: cin.fail()

	double reel;

	cout << "un reel ? : ";

	cin >> reel;				// hypothèse: l'usager tape par erreur: "  \t  A45.34\n" qui se retrouve dans le tampon du cin


	// constat 1) : les caractères ( ' ' , '\t' , '\n' ) seront ignorés de sorte que l'extraction du double aura débuté vraiment à partir de "A45.34\n"

	if (cin.fail())
	{
		// constat 2) : le cin a échoué à extraire un double, car le caractère 'A' au début du tampon est inadmissible pour un double
		
		// constat 3) : la variable reel est reintialisée à 0
		
		// constat 4) : le tampon du cin est maintenant "A45.34\n"

		// constat 5) : le cin doit être remis en marche avec la fonction cin.clear()

		cin.clear();	// note: n'a rien à voir avec vider le tampon
	}
	else
	{
		cout << reel; // ici, si l'extraction avait réussi, ce qui n'est pas le cas
	}



	// EXEMPLE #5 -- LIRE UNE NOTE JUSQU'À TEMPS QU'ELLE SOIT VALIDE

	bool valide;
	double note;

	int x = 10, y = 10;

	clrscr();
	gotoxy(x, y); cout << "Entrez une note ? : ";
	x = wherex();

	valide = false;
	do
	{
		// vider le tampon du cin
		cin.ignore(cin.rdbuf()->in_avail());

		// lire la note
		gotoxy(x, y); cin >> note;

		// nettoyer l'écran
		gotoxy(x, y); clreoscr();


		// Validations des 3 erreurs possibles

		gotoxy(10, 29); // zone du message d'erreur

		if (cin.fail()) // ATTENTION: vérifier d'abord si le "cin" n'a pas été en mesure d'extraire une note, i.e. un "double" ici
		{
			cout << "ERREUR: Vous devez entrer un nombre seulement !";
			cin.clear(); // ATTENTION: ici le cin est dans l'état "fail == true", il faut obligatoirement le remettre en état de marche avec cin.clear()
		}
		else if (note < 0) // à partir d'ici la variable note est consultable car le cin a fonctionné: cin.fail() == false
		{
			cout << "ERREUR: Vous devez entrer un nombre >= 0 !";
		}
		else if (note > 100) // autre cas possible d'erreur
		{
			cout << "ERREUR: Vous devez entrer un nombre <= 100 !";
		}
		else // pas d'erreur
			valide = true;
			
		gotoxy(0, 0); // astuce: replacer la fenêtre

	} while (!valide);

	gotoxy(10, 20); cout << "la note est " << note << "  BRAVO !"; _getch();	
}