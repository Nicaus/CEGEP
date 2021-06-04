#include <iostream>
#include <iomanip>
#include <conio.h>
#include <string>
#include <ctime>
#include "console(v1.9).h"

using namespace std;

int main() {
	
	const string jM = ("Di        Lu        Ma        Me        Je        Ve        Sa"),
		line = ("______________________________________________________________"),
		REVOIR = "A U   R E V O I R !";
	string jS[7] = { "Dimanche", "Lundi", "Mardi", "Mercredi", "Jeudi", "Vendredi", "Samedi" }, 
		mois[12] = { "Janvier", "Fevrier", "Mars", "Avril", "Mai", "Juin", "Juillet", "Aout", "Septembre", "Octobre", "Novembre", "Decembre" };
	int jourSemaine, nbTotalJoursEcoules, jourSemainePremierMois, JJ, MM, AAAA, nbJoursDansCeMois[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	char separateur, on, recommancer;
	bool valide;
	size_t larg_revoir = REVOIR.size(), larg_jM = jM.size();

	valide = false;
	do {
		int x = 9, y = 29;
		do {
			cin.ignore(cin.rdbuf()->in_avail());
			gotoxy(8, 1);
			cout << "Entrez une date (JJ/MM/AAAA) : ";
			cin >> JJ >> separateur >> MM >> separateur >> AAAA;
			x = wherex(); gotoxy(x, y); clrscr();

			if (cin.fail()) {
				gotoxy(x, y);
				cout << "Vous devez entrer des nombres seulement";
				cin.clear();
			}
			else if (separateur != '/' && separateur != '-') {
				gotoxy(x, y);
				cout << "Vous devez utiliser le s\202parateur '/' ou '-' seulement";				
			}
			else if (JJ > 31 || JJ < 01) {
				gotoxy(x, y);
				cout << "Le jour doit \210tre entre 1 et 31 inclusivement";				
			}
			else if (MM > 12 || MM < 01) {
				gotoxy(x, y);
				cout << "Le mois est erron\202 (doit \210tre entre 1 et 12 inclusivement)";				
			}
			else if (AAAA > 2099 || AAAA < 1901) {
				gotoxy(x, y);
				cout << "L'ann\202e est erron\202e (de 1901 \205 2099 seulement)";
			}
			else
				valide = true;
		} while (!valide);
		size_t larg_mm_aaaa = mois[MM].size(); 
		gotoxy(8, 4);

		//annee bissextile
		if ((AAAA % 4 == 0 && AAAA % 100 != 0) || (AAAA % 400 == 0 && AAAA % 100 == 0) || (AAAA % 400 == 0))
			nbJoursDansCeMois[1] = 29;

		//nb de jour depuis le debut de l'annee
		int date = 0;
		for (int i = 0; i < MM - 1; i++)
			date += nbJoursDansCeMois[i];
		nbTotalJoursEcoules = date + JJ;

		//nom de jour correspondant  a jourSemaine
		jourSemaine = (nbTotalJoursEcoules + (AAAA - 1900) + (AAAA - 1901) / 4) % 7 + 1;
		clrscr();
		gotoxy(8, 3);
		cout << "Le " << JJ << separateur << MM << separateur << AAAA << " est un : " << jS[jourSemaine - 1] << endl;

		//jourSemainePremierMois
		gotoxy(8, 6);
		jourSemainePremierMois = (date + (AAAA - 1900) + (AAAA - 1901) / 4) % 7 + 1;

		//calendrier (O/N)
		cout << "Voulez-vous voir le calendrier complet du mois (O/N) ? ";
		do {
			clreoscr();
			cin.ignore(cin.rdbuf()->in_avail()); char l = wherex();
			on = _getch(); on = toupper(on); cout << on; gotoxy(l, 6);
		} while (on != 'O' && on != 'N');

		switch (on) {
		case 'O' :
			//calendrier
			clrscr(); gotoxy(0, 3); cout << setw((120 - larg_mm_aaaa) / 2 + larg_mm_aaaa) << mois[MM - 1] << " " << AAAA;
			gotoxy(0, 6); cout << setw((120 - larg_jM) / 2 + larg_jM) << jM << endl;
			gotoxy(29, 7); cout << line ;

			//cout << calendrier;
			gotoxy(30, 9);
			for (JJ = 1; JJ <= nbJoursDansCeMois[MM - 1]; JJ++) {
				if (((JJ + jourSemainePremierMois - 1) % 7 == 0) && (JJ != 1))
					cout << "\n\n" << setw(31); 
				cout << JJ << setw(10);
			} 
			gotoxy(x, y); cout << "Voulez-vous traiter une autre date (O/N) ? "; recommancer = _getch(); recommancer = toupper(recommancer); cout << recommancer;
			if (recommancer == 'O')
				break;
			else
				recommancer != 'O';
			break;
		case 'N': gotoxy(x, y); cout << "Voulez-vous traiter une autre date (O/N) ? "; recommancer = _getch(); recommancer = toupper(recommancer); cout << recommancer;
			if (recommancer == 'O')
				break;
			else
				recommancer != 'O';
		}
		clrscr();
	} while (recommancer == 'O');
	
	gotoxy(0, 15);
	cout << setw((120 - larg_revoir) / 2 + larg_revoir) << REVOIR;
	Sleep(250);
}
