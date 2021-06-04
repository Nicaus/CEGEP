#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>
#include <iomanip>

#include "../../Travaux/console(v1.9).h"

using namespace std;

/*

	CIN -- FONCTIONNEMENT G�N�RAL

	- Tous les caract�res �mis par le clavier sont conserv�s, en ordre d'arriv�e, dans une m�moire tampon qui appartient � la console de Windows.
	  Ce processus est automatiquement g�r� par l'OS. Les fonctions _getch(), _getche() et _kbhit() interagissent avec ce tampon.

	- Le cin poss�de son propre tampon d'input et se sert du tampon de la console pour s'approvisonner en caract�res.
	  Il y a donc deux tampons qui peuvent �tre manipul�s par votre programme, celui de la console et celui du cin.

	- Le CIN extrait les caract�res, un � un de son tampon, pour extraire la prochaine information � mettre dans une variable.
	  Le type de la variable V ( ex: cin >> V ) influance l'extraction attentue


	A) L'approvisionnement en caract�res

		- Le CIN inspect toujours en premier son propre tampon � la recherche des caract�res � extraire.
	
		- Si celui-ci est vide, il ira s'approvisionner dans le tampon de la console, en retirant, dans l'ordre,
		   tous les caract�res disponibles jusqu'au premier caract�re de fin de ligne rencontr� ('\n').
		   
		- Sans ce caract�re de fin de ligne, ce processus restera en attente de l'avoir.

				si ( tampon_cin est vide )

					faire

						c = _getch()		// extraction dans le tampon de la console Windows
						tampon_cin += c		// concat�nation dans le tampon du cin

						// ... tel que l'affichage de c

					tant que ( c != '\n' )

		- Une fois les caract�res transf�r�s d'un tampon � l'autre, le CIN peut poursuivre son traitement d'extraction B).

		- Par contre, d�s que le CIN aura besoin de nouveaux caract�res pour son tampon, ce processus d'approvisionnement recommencera jusqu'au prochain ('\n')
		

	B) Extraction des caract�res utiles du tampon du CIN

		- L'extraction des caract�res utiles est gouvern�e par le TYPE d'information qui doit �tre obtenue

			double V;

			cin >> V;
			
			- ici, le TYPE d'information � extraire, � partir du d�but du tampon du CIN, doit �tre une suite de caract�res qui exprime un r�el (double)
			
				ex: 234
				ex: -45.567

		- L'extaction se termine sur le premier caract�re rencontr� non admissible, lequel restera dans le tampon


		NOTES:

		1) L'extraction ignorera tous les caract�res ( ' ' , '\t' , '\n' ) qui se pr�senteraient, dans le tampon, d�s le d�but, en les retirant

		2) Si le tampon est vide � nouveau, l'approvisionnement recommence

		3) Si le premier caract�re rencontr� est inadmissible, au regard du TYPE de V, le CIN �choue et V est reinitialis�e � z�ro ou l'�quivalent.

		4) Si le CIN �choue, il faut le remettre en marche:  cin.fail() permet de savoir s'il a �chou�, et cin.clear() de le remettre en marche

*/




int main()
{
	// EXEMPLE #1 -- INPUT NORMAL SANS ERREUR

	int entier;

	cout << "un entier ? : ";

	cin >> entier;				// hypoth�se: l'usager tape: "123.45ABC\n" qui se retrouve dans le tampon du cin

	// constat 1) : le cin a extrait "123" du tampon et affect� le nombre 123 � la variable entier
	// constat 2) : il reste dans le tampon du cin ".45ABC\n" qui servira au prochain cin, s'il y a lieu
	
	

	// EXEMPLE #2 -- VIDER LE TAMPON DU CIN AU BESOIN

	cin.ignore(cin.rdbuf()->in_avail());	// sans commentaire !

	// constat 1) : le tampon du cin est maintenant vide ==> ""
	// constat 2) : le prochain cin devra s'approvisionner dans le tampon de la console



	// EXEMPLE #3 -- NPUT NORMAL SANS ERREUR -- LIRE DEUX NOMBRES AVEC UNE CASCADE DE CIN 

	double n, m;

	cout << "deux nombres ? : ";

	cin >> n >> m;		// note 1: idem que: cin >> n; cin >> m;    note 2: hypoth�se: l'usager tape "12 78 \n" qui se retrouve dans le tampon du cin

	// constat 1) : le cin a extrait "12" ==> n, et le tampon == " 78 \n"
	// constat 2) : le cin a extrait "78" ==> m, et le tampon == " \n"



	// EXEMPLE #4 -- V�RIFIER QUE LE CIN N'A PAS �CHOU� � FAIRE L'EXTRACTION AVEC LA FONCTION: cin.fail()

	double reel;

	cout << "un reel ? : ";

	cin >> reel;				// hypoth�se: l'usager tape par erreur: "  \t  A45.34\n" qui se retrouve dans le tampon du cin


	// constat 1) : les caract�res ( ' ' , '\t' , '\n' ) seront ignor�s de sorte que l'extraction du double aura d�but� vraiment � partir de "A45.34\n"

	if (cin.fail())
	{
		// constat 2) : le cin a �chou� � extraire un double, car le caract�re 'A' au d�but du tampon est inadmissible pour un double
		
		// constat 3) : la variable reel est reintialis�e � 0
		
		// constat 4) : le tampon du cin est maintenant "A45.34\n"

		// constat 5) : le cin doit �tre remis en marche avec la fonction cin.clear()

		cin.clear();	// note: n'a rien � voir avec vider le tampon
	}
	else
	{
		cout << reel; // ici, si l'extraction avait r�ussi, ce qui n'est pas le cas
	}



	// EXEMPLE #5 -- LIRE UNE NOTE JUSQU'� TEMPS QU'ELLE SOIT VALIDE

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

		// nettoyer l'�cran
		gotoxy(x, y); clreoscr();


		// Validations des 3 erreurs possibles

		gotoxy(10, 29); // zone du message d'erreur

		if (cin.fail()) // ATTENTION: v�rifier d'abord si le "cin" n'a pas �t� en mesure d'extraire une note, i.e. un "double" ici
		{
			cout << "ERREUR: Vous devez entrer un nombre seulement !";
			cin.clear(); // ATTENTION: ici le cin est dans l'�tat "fail == true", il faut obligatoirement le remettre en �tat de marche avec cin.clear()
		}
		else if (note < 0) // � partir d'ici la variable note est consultable car le cin a fonctionn�: cin.fail() == false
		{
			cout << "ERREUR: Vous devez entrer un nombre >= 0 !";
		}
		else if (note > 100) // autre cas possible d'erreur
		{
			cout << "ERREUR: Vous devez entrer un nombre <= 100 !";
		}
		else // pas d'erreur
			valide = true;
			
		gotoxy(0, 0); // astuce: replacer la fen�tre

	} while (!valide);

	gotoxy(10, 20); cout << "la note est " << note << "  BRAVO !"; _getch();	
}