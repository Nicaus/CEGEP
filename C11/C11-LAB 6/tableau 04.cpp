#include <iostream>
#include <conio.h>
#include <string>
#include <iomanip>

using namespace std;


// LABORATOIRE 5: REVISITÉ AVEC LES TABLEAUX

int main()
{
	// EXEMPLE : LAB 5 avant les tableaux -- RAPPEL

	// data
	int freq1, freq2, freq3, freq4, freq5, freq6;

	// ...

	// init
	freq1 = freq2 = freq3 = freq4 = freq5 = freq6 = 0;

	// lancer
	for (int l = 1; l <= 100; ++l)
	{
		switch (rand() % 6 + 1)
		{
			case 1: ++freq1; break;
			case 2: ++freq2; break;
			case 3: ++freq3; break;
			case 4: ++freq4; break;
			case 5: ++freq5; break;
			case 6: ++freq6; break;
		}
	}

	// ...


	// EXEMPLE -- LAB 5 avec les tableaux

	const int FACES = 6;						// dé à 6 faces
	int freq[FACES];							// 6 variables

	// init
	for (int i = 0; i < FACES; ++i)
		freq[i] = 0;

	// lancer
	for (int l = 1; l <= 100; ++l)
		freq [ rand() % FACES ] ++;



	_getch();
}