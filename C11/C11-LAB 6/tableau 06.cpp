#include <iostream>
#include <conio.h>
#include <string>
#include <iomanip>

using namespace std;

// LES TABLEAUX DE CARACTÈRES ("char") ET LE CARACTÈRE SPÉCIAL DE TERMINAISON '\x0'

int main()
{
	// EXEMPLE #1 -- Définition du tableau constant "voyelles", une série de 6 caractères ("char")

	const int VOYS = 6;
	const char voyelles[VOYS] = { 'a', 'e', 'i', 'o', 'u', 'y' };



	// EXEMPLE #2 -- Définition du tableau "consonnes", une série de 20 caractères ("char")

	char consonnes[] = { 'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n' , 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'z' };

	// note 1: Il est possible de ne pas spécifiée la taille, elle sera donc déduite, à la compilation, avec le nombre de valeurs d'initialisation.

	// note 2: Cette façon de faire n'est pas très pratique, car la taille de ce tableau n'est spécifiée nulle part.



	// EXEMPLE #3 -- Définition du tableau "alphabet", une série de 26 caractères ("char") PLUS un caractère de terminaison spécial.

	const int ALPHA = 26;
	const char alphabet[ALPHA + 1] = "abcdefghijklmnopqrstuvwxyz";

	// note 1: La chaine "abcdefghijklmnopqrstuvwxyz" est un tableau constant de 27 "char" en C++, où le dernier caractère, qui n'est pas visible,
	//         est un caractère dit de terminaison (ou butoire) automatiquement ajouté et qui équivaut à '\x0'

	// note 2: La taille du tableau "alphabet" doit être égale ou supérieure à la chaine d'initialisation "abcdefghijklmnopqrstuvwxyz"

	// note 3: Dans la dernière case du tableau "alphabet", il y aura donc le caractère spécial: alphabet[26] == '\x0' ou simplement l'entier 0



	// EXEMPLE #4 -- Afficher toutes les valeurs du tableau voyelles et consonnes

	for (int i = 0; i < VOYS; ++i)
		cout << voyelles[i] << " ";

	cout << endl;

	for (int i = 0; i < 20; ++i)
		cout << consonnes[i] << " ";

	cout << endl;

	// note 1: Il n'est pas possible d'afficher le tableau ainsi:  "cout << voyelles;"



	// EXEMPLE #5 -- Afficher toutes les valeurs du tableau alphabet avec cout <<

	cout << alphabet;

	// note 1: Il est possible d'afficher le tableau "alphabet" directement avec un cout car (1) ET (2)

	//	1) il s'agit d'un tableau de char, ET

	//	2) ce tableau possède le caractère butoire '\x0' quelque part ce qui permet au cout de s'arrêter à cet endroit
	

	_getch();
}