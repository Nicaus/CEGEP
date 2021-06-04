#include <iostream>
#include <conio.h>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
	// EXEMPLE #1 -- Définition du tableau "examen" (une série) de N notes (double)

	const int N = 10;
	
	double examen[N] = {};		// {} ==> permet d'initialiser tous les éléments à 0 dès la création du tableau


	// EXEMPLE #2 -- Simulation aléatoire des résultats de l'examen
	
	for (int i = 0; i < N; ++i)
		examen[i] = (rand() % 101);


	// EXEMPLE #3 -- Affichage des notes de l'examen

	cout << fixed << setprecision(1);

	for (int i = 0; i < N; ++i)
		cout << examen[i] << endl;


	// EXEMPLE #4 -- Calculer la moyenne des notes

	double somme = 0;

	for (int i = 0; i < N; ++i)
		somme += examen[i];

	cout << endl << "Moy : " << somme / N << endl;


	// EXEMPLE #5 -- Compter le nombre de réussite

	int reussites = 0;

	for (int i = 0; i < N; ++i)
		if (examen[i] >= 60)
			++reussites;

	cout << endl << "60+ : " << reussites << endl;


	// EXEMPLE #6 -- Trouver la plus petite et la plus grande note

	double min = examen[0], max = examen[0];

	for (int i = 0; i < N; ++i)
	{
		if (examen[i] > max) max = examen[i];

		if (examen[i] < min) min = examen[i];
	}

	cout << endl << "Min : " << min << endl << "Max : " << max << endl;


	_getch();
}