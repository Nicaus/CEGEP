#include <iostream>
#include <conio.h>
#include <iomanip>

using namespace std;


// GYMNASTIQUE DE PROGRAMMATION AVEC LES TABLEAUX -- SUITE

int main()
{
	// EXEMPLE #1 -- RECHERCHE DICHOTOMIQUE -- VERIFIER L'EXISTENCE D'UNE VALEUR v DANS UN TABLEAU TRIÉ T
	{
		const int S = 7;
		int T[S] = { 10, 20, 30, 40, 50, 60, 100 }, iMin, iMax, iMil;
		bool existe;

		int v = 60; // la valeur v à trouver

		existe = false;
		iMin = 0, iMax = S - 1;

		while (iMin <= iMax)
		{
			iMil = (iMin + iMax) / 2; // le milieu
			if (v == T[iMil])
			{
				existe = true;
				break;
			}
			else if (v < T[iMil])
				iMax = iMil - 1;
			else
				iMin = iMil + 1;
		}

		// Afficher le verdict
		cout << "1) Est-ce que la valeur " << v << " existe dans le tableau : " << (existe ? "OUI" : "NON") << " !" << "\n\n";
	}


	// EXEMPLE #2 -- ALGORITHME DE TRI PAR SELECTION
	{
		int iMin, temp;

		const int S = 7;
		int T[S] = { 100, 30, 50, 40, 20, 60, 10 };

		for (int i = 0; i < S; i++)
		{
			// rechercher le minimum dans le sous tableau [ i .. S-1 ]
			iMin = i;
			for (int j = i; j < S; j++)
				if (T[j] < T[iMin])
					iMin = j;

			// interchanger le minimum avec le début du sous tableau i.e. min <==> i
			temp = T[i];
			T[i] = T[iMin];
			T[iMin] = temp;
		}

		// Afficher le tableau T trié
		cout << "2) Le tableau T tri\202 : [";
		for (int i = 0; i < S; i++) cout << " " << T[i] << ",";
		cout << "\b ]" << "\n\n";
	}


	// EXEMPLE #3 -- ÉVALUATION DU PRODUIT SCALAIRE DE DEUX VECTEURS A ET B
	{
		const int S = 3;
		int A[S] = { 2, 4, 3 }, B[S] = { 5, 3, 6 }, produitScalaire = 0;

		for (int i = 0; i < S; i++)
			produitScalaire += A[i] * B[i];

		cout << "3) A . B = " << produitScalaire << "\n\n";
	}


	// EXEMPLE #4 -- ÉVALUATION D'UN POLYNÔME P(x)
	{
		const int S = 4;
		double P[S] = { 2.0, 4.0, 0, 3.0 };  // P(x) = 2.0 (x)3 + 4.0 (x)2 + 3.0

		double x, x_pow, Px;

		x = 3;

		Px = 0; x_pow = 1;
		for (int i = S - 1; i >= 0; --i)
		{
			Px += P[i] * x_pow;
			x_pow *= x;
		}

		cout << "4) P(x) = " << Px << "\n\n";
	}

	_getch();
}