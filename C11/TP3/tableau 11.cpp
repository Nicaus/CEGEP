#include <iostream>
#include <conio.h>
#include <iomanip>

using namespace std;


// GYMNASTIQUE DE PROGRAMMATION AVEC LES TABLEAUX

int main()
{
	int i;

	// EXEMPLE #0 -- RECHERCHER LA VALEUR MAXIMUM DU TABLEAU T
	{
		const int S = 7;
		const int T[S] = { -1, 40, 2000, -55, 5, 12, -9 };
		int imax; // indice du maximum

		imax = 0; // hypothèse: le max est en indice 0
		for (i = 0; i < S; i++)
			if (T[imax] < T[i])
				imax = i;

		// Afficher le maximum
		cout << "0) La valeur maximum du tableau est " << T[imax] << " et se trouve \x85 l'indice " << imax << "\n\n";
	}


	// EXEMPLE #1 -- VÉRIFIER SI LE TABLEAU T EST UN PALINDROME
	{
		const int S = 7;
		const int T[S] = { 4, 2, 5, 7, 5, 2, 4 };
		bool estUnPalindrome;

		estUnPalindrome = true; // hypothèse
		for (i = 0; i < (S / 2); i++)
			if (T[i] != T[(S - 1) - i])
			{
				estUnPalindrome = false;
				break; // rien ne sert d'aller plus loin !
			}

		// Afficher le verdict
		cout << "1) Est-ce un palindrome : " << (estUnPalindrome ? "OUI" : "NON") << " !" << "\n\n";
	}


	// EXEMPLE #2 -- INVERSER LE TABLEAU T SANS l'USAGE D'UN AUTRE TABLEAU (IN SITU)
	{
		const int S = 12;
		char T[S] = { 'e',  'u',  'q',  'i',  't',  'a',  'm',  'r',  'o',  'f',  'n',  'i' };
		char c;

		// Afficher le tableau T
		cout << "2)" << setw(23) << "Soit le tableau T : [";
		for (i = 0; i < S; i++) cout << " '" << T[i] << "',";
		cout << "\b\b ]" << endl;

		// Inverser le tableau
		for (i = 0; i < (S / 2); i++)
		{
			c = T[i];
			T[i] = T[(S - 1) - i];
			T[(S - 1) - i] = c;
		}

		// Afficher le tableau T inversé
		cout << setw(25) << "et son inverse : [";
		for (i = 0; i < S; i++) cout << " '" << T[i] << "',";
		cout << "\b\b ]" << "\n\n";
	}


	// EXEMPLE #3 -- VÉRIFIER SI LE TABLEAU EST TRIÉ
	{
		const int S = 7;
		int T[S] = { 1, 2, 3, 4, 5, 6, 7 };
		bool trié;

		trié = true;  // hypothèse
		for (int i = 1; i < S; i++)
			if (T[i - 1] > T[i])
			{
				trié = false;
				break;  // rien ne sert d'aller plus loin !
			}

		cout << "3) Est-ce un tableau tri\x82 ? " << (trié ? "OUI" : "NON") << " !" << "\n\n";
	}


	// EXEMPLE #4 -- DÉPLACER D'UNE CASE VERS LA GAUCHE LES ÉLÉMENTS DU TABLEAU T
	{
		const int S = 7;
		int T[S] = { 99, 10, 20, 30, 40, 50, 60 }, temp;

		temp = T[0];
		for (int i = 0; i < S - 1; i++)
			T[i] = T[i + 1];
		T[S - 1] = temp;

		// Afficher le tableau T
		cout << "4) Le tableau T d\202cal\202 d'une position vers la gauche : [";
		for (i = 0; i < S; i++) cout << " '" << T[i] << "',";
		cout << "\b\b ]" << "\n\n";
	}

	_getch();
}