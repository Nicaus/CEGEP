#include <iostream>
#include <conio.h>
#include <string>
#include <iomanip>

using namespace std;

/*

INITIALISATION DES TABLEAUX LORD DE LA DÉFINITION

	Syntaxe particulière

		1) type nom[n];							// toutes les valeurs sont indéfinies

		2) type nom[n] = {};					// toutes les valeurs sont initilisées à zéro, ou l'équivalent en fonction du type (ex: string ==> "")

		3) type nom[n] = { V1, V2, ..., Vn };	// possibilité de spécifier explicitement les premières valeurs, le reste est initialisée à zéro, ou l'équivalent.

		note: si la valeur Vn est donnée alors la valeur Vn-1 aussi.


	Attention: cette syntaxe  " = {...} "  est disponible seulement lors de la définition du tableau

		nom = {...};	// ==> erreur de compilation

*/

int main()
{
	// EXEMPLES:  (idem si les tableaux sont constants: "const")

	int T[5] = { 10, 20 };										// le reste à 0

	bool réponses[20] = { true, false, true };					// le reste à false

	double temperature[6] = { 0, 22.5, 0, -15.7 };				// le reste à 0

	string salutations[4] = { "bonjour", "salut" , "allo" };	// le reste à chaine vide ""

	// ...

	// salutations = { "bonjour", "salut" , "allo" };  ==> interdit

	_getch();
}