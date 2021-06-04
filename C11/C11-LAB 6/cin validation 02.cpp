#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>
#include <iomanip>

#include "../../Travaux/console(v1.9).h"

using namespace std;


int main()
{
	bool valide;
	double nombre_1, nombre_2, r�sultat;
	char op�rateur;

	// EXEMPLE DE LECTURE D'UNE EXPRESSION SIMPLE ET SA VALIDATION

	valide = false;
	do
	{
		// vider le tampon du cin
		cin.ignore(cin.rdbuf()->in_avail());

		// lire une expression simple
		gotoxy(10, 10); cout << "Entrez une expression simple (ex: n + m) ? : ";
		cin >> nombre_1 >> op�rateur >> nombre_2;

		// Validations des erreurs possibles
		gotoxy(10, 29);
		if (cin.fail()) // v�rifier d'abord si le "cin" n'a pas �t� en mesure de lire l'expression.
		{
			cout << "ERREUR: Vous devez entrer seulement des nombres !";
			cin.clear(); // obligatoire de remettre le cin en �tat de marche car fail()
		}
		else if (op�rateur != '+' && op�rateur != '-' && op�rateur != '*' && op�rateur != '/' ) // op�rateur non admissible
		{
			cout << "ERREUR: Vous devez entrer un op\x82rateur valide ! ( + , - , * , / )";
		}
		else // pas d'erreur
			valide = true;

		if (!valide)
		{
			cout << " ... ";	_getch();
		}

		clrscr();
			
	} while (!valide);


	r�sultat = nombre_1;
	switch (op�rateur)
	{
		case '+': r�sultat += nombre_2; break;
		case '-': r�sultat -= nombre_2; break;
		case '*': r�sultat *= nombre_2; break;
		case '/': r�sultat /= nombre_2; break;
	}

	gotoxy(10, 20); cout << nombre_1 << " " << op�rateur << " " << nombre_2 << " = " << r�sultat;
	_getch();	
}