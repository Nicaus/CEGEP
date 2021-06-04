#include <iostream>
#include <conio.h>
#include <string>
#include <iomanip>

using namespace std;

/*

VARIABLE DIMENSIONNÉE: ( autres noms: "un Tableau", ou en anglais: "Array" )


	A) DÉFINITION: Il est possible de définir, en une seule instruction, une serie de N variables du même type.

		- Syntaxe de la définition:
	
			type nom [ N ] ;		// définition d'une variable dimentionnée


		- le "nom" est celui de la variable dimensionnée

		- N est la dimension (ou la taille) de la série et doit être un entier positif ( >= 1 )
	
		- la valeur de N doit être connu à la compilation (versus connu à l'exécution), il s'agit donc d'une constante entière.


	B) ACCÈS: Pour accéder à une des variables de la série, il faut utiliser un indice
		
		- la première variable de la série est à l'indice : 0

		- le dernière variable de la série est à l'indice : N-1


		- Syntaxe d'accès:

			nom [ 0 ] ;				// accès à la première variable de la série

			nom [ 1 ] ;				// accès à la deuxième variable de la série

			nom [ i ] ;				// accès à la variable en indice i

			nom [ N-1 ] ;			// accès à la dernière variable de la série

			nom [ expression ] ;	// la valeur de l'expression doit absolument être un entier entre [ 0 .. N-1 ]



		- l'indice peut être vu comme un déplacement (un delta) à partir du début de la série de variables

			série de 10 variables:	[ ][ ][ ][ ][ ][ ][ ][ ][ ][ ]		// ici N = 10  ==>  10 x [case]
						   indice:	 0  1  2  3  4  5  6  7  8  9

*/


// Pour la suite, le terme Tableau est utilisé

int main()
{
	// EXEMPLE #1 -- Définition du tableau "nombres" (une série) de 3 entiers

	// Définition
	int nombres[3];		// 3 est la taille du tableau


	// Affectation d'une valeur à chaque indice du tableau
	nombres[0] = 10;	// à l'indice 0
	nombres[1] = 15;	// à l'indice 1
	nombres[2] = 20;	// à l'indice 2

	// note 1: les indices débute à 0 jusqu'à (taille-1)
	// note 2: l'indice doit absolument être valide sinon une erreur grave se produira à l'exécution
	// note 3: l'indice n'est pas vérifié à la compilation

	// EXEMPLE #2 -- Afficher les 3 éléments du tableau "nombres"

	cout
		<< nombres[0] << endl
		<< nombres[1] << endl
		<< nombres[2] << endl;


	// EXEMPLE #3 --  Afficher les 3 éléments du tableau "nombres" en bloucle !!!

	for (int i = 0; i < 3; ++i)
		cout << nombres[i] << endl;


	// EXEMPLE #4 -- Augmenter de 100 chaque élément du tableau

	for (int i = 0; i < 3; ++i)		// i pour indice
		nombres[i] = nombres[i] + 100;


	// EXEMPLE #5 -- Tripler chaque élément du tableau en utilisant une bloucle

	for (int i = 0; i < 3; ++i)		// i pour indice
		nombres[i] *= 3;


	// EXEMPLE #6 -- Réinitialiser tous les éléments du tableau à zéro

	for (int i = 0; i < 3; ++i)
		nombres[i] = 0;


	// EXEMPLE #7 -- Incrémenter tous les éléments du tableau de 1

	for (int i = 0; i < 3; ++i)
	{
		nombres[i]++;

		// alternatives syntaxiques:

		//  ++nombres[i];

		//  nombres[i] += 1;

		//  nombres[i] = nombres[i] + 1;
	}

	_getch();
}