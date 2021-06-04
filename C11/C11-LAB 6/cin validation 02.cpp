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
	double nombre_1, nombre_2, résultat;
	char opérateur;

	// EXEMPLE DE LECTURE D'UNE EXPRESSION SIMPLE ET SA VALIDATION

	valide = false;
	do
	{
		// vider le tampon du cin
		cin.ignore(cin.rdbuf()->in_avail());

		// lire une expression simple
		gotoxy(10, 10); cout << "Entrez une expression simple (ex: n + m) ? : ";
		cin >> nombre_1 >> opérateur >> nombre_2;

		// Validations des erreurs possibles
		gotoxy(10, 29);
		if (cin.fail()) // vérifier d'abord si le "cin" n'a pas été en mesure de lire l'expression.
		{
			cout << "ERREUR: Vous devez entrer seulement des nombres !";
			cin.clear(); // obligatoire de remettre le cin en état de marche car fail()
		}
		else if (opérateur != '+' && opérateur != '-' && opérateur != '*' && opérateur != '/' ) // opérateur non admissible
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


	résultat = nombre_1;
	switch (opérateur)
	{
		case '+': résultat += nombre_2; break;
		case '-': résultat -= nombre_2; break;
		case '*': résultat *= nombre_2; break;
		case '/': résultat /= nombre_2; break;
	}

	gotoxy(10, 20); cout << nombre_1 << " " << opérateur << " " << nombre_2 << " = " << résultat;
	_getch();	
}