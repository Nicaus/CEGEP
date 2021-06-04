#include <iostream>
#include <iomanip>
#include <conio.h>
#include <string>
#include <ctime>
#include "console(v1.9).h"

using namespace std;

int main() {
	string titre = "JEU DES COULEURS", 
		reglage = "R\220GLAGES DE LA PARTIE", 
		colors = "(R)ouge, (V)ert, (B)leu, (J)aune, (M)auve, (C)yan", 
		question = "Activer le mode en d\202bogage ? (O/N) : ";
	size_t l_titre = titre.size(), l_reglage = reglage.size();
	char debogage, evaluer, couleur[6] = { 'R', 'V', 'B', 'J', 'M', 'C' }, s, entre, essais[4] = {}, jeu[4] = {};
	int yy = 10, bienplace, malplace, y = 0, invalide = 0;
	srand(int(time(0)));

	//demande si on veut le jeu en mode debug
	cout << endl << setw((120 - l_titre) / 2 + l_titre) << titre << endl
		<< "\n\n" << setw((120 - l_reglage) / 2 + l_reglage) << reglage;
	y = wherey(); gotoxy(9, y + 3);
	cout << question;
	do {
		clreoscr();
		debogage = _getch(); debogage = toupper(debogage);
		if (debogage != 'O' && debogage != 'N')
			gotoxy(question.size() + 9, y + 3);
		else
			cout << debogage;
	} while (debogage != 'O' && debogage != 'N');

	//affichage du tableau
	gotoxy(0, 2); clreoscr(); gotoxy(9, 5); cout << colors; gotoxy(9, 8); 
	cout << "#" << setw(10) << "Essais" << setw(22) << "Bien plac\202e(s)" << setw(17) << "Mal plac\202e(s)" << endl;
	gotoxy(0, 10);
	for (int i = 0; i < 11; i++) {
		if (i > 10)
			cout << setw(9) << i << ")" << endl;
		cout << setw(10) << i << ")" << endl;
	}

	//code secret
	int cc = 55, l = 25, ccc = 2; string jj = "\0";
	gotoxy(cc, l);
	for (int f = 0; f < 4; f++) 
	{
		s = rand() % 6;
		jeu[f] = couleur[s];
		jj += jeu[f];jj += " ";
	}

	//affichage du code secret
	if (debogage == 'O' && debogage != 'N') 
	{
		cout << "Code Secret :";
		for (int code = 0; code < 4; code++ )
			cout << setw(ccc) << jeu[code]; ccc++;
	}
	//essais
	int x = 10, w = 14;
	gotoxy(w, x);
	do 
	{
		do //si on presse N, le code ne continue pas et ne compte pas (évaluation)
		{
			x++;
			for (int i = 0; i < 4; ++i)
			{
				do
				{
					entre = toupper(_getch());
				} 
				while (entre != 'R' && entre != 'V' && entre != 'B' && entre != 'J' && entre != 'M' && entre != 'C');

				essais[i] = entre;
				cout << essais[i] << setw(2);
			}

			//vérifie la réponse
			gotoxy(2, 24); cout << "\220valuer ? (O/N) : ";

			do
			{
				evaluer = toupper(_getch());
			}
			while (evaluer != 'N' && evaluer != 'O');

			cout << evaluer;
			bienplace = 0; malplace = 0;
			switch (evaluer)
			{
			case 'O':
			{
				int i = 0;
				do
				{
					int k = 0;
					if (essais[i] == jeu[i])								//vérifie le nombre de lettres à la bonne place
						++bienplace;
					else if (essais[i] == jeu[0] && essais[0] != jeu[0])	//vérifie le nombre de lettres à la mauvaise place
						++k;
					else if (essais[i] == jeu[1] && essais[1] != jeu[1])
						++k;
					else if (essais[i] == jeu[2] && essais[2] != jeu[2])
						++k;
					else if (essais[i] == jeu[3] && essais[3] != jeu[3])
						++k;
					if (k > 0)
						++malplace;
					++i;
				} 
				while (i < 4);

				//affiche le nb de lettres
				gotoxy(35, yy); cout << bienplace;
				gotoxy(50, yy); cout << malplace;
				gotoxy(w, x);
			}
			break;
			case 'N':
				gotoxy(w, --x);
				clreol();
				break;
			}
		}
		while (evaluer != 'O');
		
		//affichage de la réponse
		if (bienplace == 4) 
		{
			gotoxy(cc, l); cout << "Code Secret : " << jj;
			gotoxy(0, 24); cout << " Bravo, vous avez gagn\202 ! :) ";
		}
		else if (invalide >= 10) 
		{
			gotoxy(cc, l); cout << "Code Secret : " << jj;
			gotoxy(0, 24); cout << " Vous avez perdu !  :( ";
		}

		invalide++;
		++yy;
	} 
	while (bienplace != 4 && invalide <= 10);
	

    _getch();
}