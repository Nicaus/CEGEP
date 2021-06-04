#include <iostream>
#include <conio.h>
#include <string>
#include <iomanip>

using namespace std;

// LES TABLEAUX DE CARACT�RES ("char") ET LE CARACT�RE SP�CIAL DE TERMINAISON '\x0'

int main()
{
	// EXEMPLE #1 -- D�finition du tableau constant "voyelles", une s�rie de 6 caract�res ("char")

	const int VOYS = 6;
	const char voyelles[VOYS] = { 'a', 'e', 'i', 'o', 'u', 'y' };



	// EXEMPLE #2 -- D�finition du tableau "consonnes", une s�rie de 20 caract�res ("char")

	char consonnes[] = { 'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n' , 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'z' };

	// note 1: Il est possible de ne pas sp�cifi�e la taille, elle sera donc d�duite, � la compilation, avec le nombre de valeurs d'initialisation.

	// note 2: Cette fa�on de faire n'est pas tr�s pratique, car la taille de ce tableau n'est sp�cifi�e nulle part.



	// EXEMPLE #3 -- D�finition du tableau "alphabet", une s�rie de 26 caract�res ("char") PLUS un caract�re de terminaison sp�cial.

	const int ALPHA = 26;
	const char alphabet[ALPHA + 1] = "abcdefghijklmnopqrstuvwxyz";

	// note 1: La chaine "abcdefghijklmnopqrstuvwxyz" est un tableau constant de 27 "char" en C++, o� le dernier caract�re, qui n'est pas visible,
	//         est un caract�re dit de terminaison (ou butoire) automatiquement ajout� et qui �quivaut � '\x0'

	// note 2: La taille du tableau "alphabet" doit �tre �gale ou sup�rieure � la chaine d'initialisation "abcdefghijklmnopqrstuvwxyz"

	// note 3: Dans la derni�re case du tableau "alphabet", il y aura donc le caract�re sp�cial: alphabet[26] == '\x0' ou simplement l'entier 0



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

	//	2) ce tableau poss�de le caract�re butoire '\x0' quelque part ce qui permet au cout de s'arr�ter � cet endroit
	

	_getch();
}