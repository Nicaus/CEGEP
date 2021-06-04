#include <iostream>
#include <iomanip>
#include <conio.h>
#include <string>
#include <ctime>
#include "console(v1.9).h"

using namespace std;

int main() {
	const string SAISIEMDP1 = "Entrer votre mot de passe (4 caracteres) :", SAISIEMDP2 = "Taper votre mot de passe encore une fois :", ERREUR = "Recommencez, vous devez entrer le m\210me mot deux fois :",
	MESSAGE = "\220 C R A N  V E R R O U L L \220", MDP = "Mot de passe :", REVOIR = "A U   R E V O I R";
	const int PAD = 4; const char BOX = '#';
	string mdp1, mdp2, mdp3, pass;
	size_t larg_titre1 = SAISIEMDP1.size(), larg_titre2 = SAISIEMDP2.size(), larg_erreur = ERREUR.size(), larg_pass = pass.size(), larg_mdp = MDP.size(), larg_revoir = REVOIR.size();

	pass = "x";
	const int tailleMDP = 4, LARG = 120;
	char mddp1, mddp2, mddp3;
	int c, l, x, y;
	srand(int(time(0)));
	
	//etape 1
	do {
		gotoxy(0, 15);
		if (mdp1!= mdp2)
			cout << setw((LARG - larg_erreur) / 2 + larg_erreur) << ERREUR << "\n\n";
		else 
			cout << setw((LARG - larg_titre1) / 2 + larg_titre1) << SAISIEMDP1 << "\n\n";
		mdp1 = '\0', mdp2 = '\0';
		c = 57; l = 17;
		do {
			gotoxy(c, l);
			cout << pass;
			c++;
		} while (c < 61);
		c = 57; l = 17;
		gotoxy(c, l);
		for (int i = 1; i <= tailleMDP; ++i) {
			mddp1 = _getch();
			cout << "*";
			mdp1 += mddp1;
		}
		clrscr();

		gotoxy(0, 15);
		cout << setw((LARG - larg_titre2) / 2 + larg_titre2) << SAISIEMDP2 << "\n\n";
		c = 57; l = 17;
		do {
			gotoxy(c, l);
			cout << pass;
			c++;
		} while (c < 61);
		c = 57; l = 17;
		gotoxy(c, l);
		for (int i = 1; i <= tailleMDP; ++i) {
			mddp2 = _getch();
			cout << "*";
			mdp2 += mddp2;
		}
		clrscr();
	} while (mdp1 != mdp2);
	
	//etape 2
	while (!_kbhit()) {
		x = rand() % (120 - MESSAGE.size());
		y = rand() % 30;
		gotoxy(x, y);
		cout << MESSAGE;
		Sleep(750);
		gotoxy(x, y);
		clreol();
	}
	while (_kbhit())
		_getch();

	//etape 3
	do {
		gotoxy(0, 15);
		cout << setw((LARG - larg_mdp) / 2 + larg_mdp) << MDP << "\n\n";
		mdp3 = '\0';
		c = 57; l = 17;
		do {
			gotoxy(c, l);
			cout << pass;
			c++;
		} while (c < 61);
		c = 57; l = 17;
		gotoxy(c, l);
		for (int i = 1; i <= tailleMDP; ++i) {
			mddp3 = _getch();
			cout << "*";
			mdp3 += mddp3;
		}

	} while (mdp3 != mdp2);

	gotoxy(0, l + 4);
	cout << setw((LARG - larg_revoir) / 2 + larg_revoir) << REVOIR;

	Sleep(500);
}