#include <iostream>
#include <iomanip>
#include <string>
#include <conio.h>
#include <sstream>
#include "console(v1.9).h"
#include "io.h"

/* Petit fonction input output */

using namespace std;

void io_titre()
{
	int x = MARG;
	string titre = "LE RÉPARTITEUR DE DÉPENSES ";

	gotoxy(x, 0);	io_texteCouleur(cvmColor::VERT, titre);
	gotoxy(x, 1);	cout << setfill('-') << setw(titre.size()) << " " << setfill(' ');
	cvmResetColor();
}

double io_arrondir(double valeur)
{
	double pow10 = pow(10, 2);
	return round(valeur * pow10) / pow10;
}

string& io_textCleaner(string& texte) 
{
	string mot;
	stringstream ss(texte);
	texte = "";
	while (ss >> mot)
		if (texte.size()) texte += " " + mot; else texte = mot;
	return texte;
}

string io_dateHeure(time_t t)
{
	string ft;
	stringstream ss;
	tm d;

	localtime_s(&d, &t);
	ss << right << setw(2) << setfill('0') << d.tm_mday << "/" << setw(2) << d.tm_mon + 1 << "/" << d.tm_year + 1900 << " - " <<
		setw(2) << d.tm_hour << ":" << setw(2) << d.tm_min << ":" << setw(2) << d.tm_sec;
	ft = ss.str();
	return ft;
}

void io_copyStringTo(const string& s, const unsigned int size, char to[]) 
{
	unsigned int i;
	for (i = 0; (i < size - 1) && (i < s.size()); ++i)
		to[i] = s[i];
	to[i] = 0;
}

void io_lireString(const int size, char to[])
{
	string texte;
	getline(cin, texte);
	io_textCleaner(texte);
	io_copyStringTo(texte, size, to);
}

void io_texteCouleur(cvmColor c, string message)
{
	cvmSetColor(c);
	cout << message;
}

void io_clean()
{
	if (cin.fail()) cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());
	while (_kbhit()) _getch();
}
