/*
	AUTEUR:

	DESCRIPTION:
*/

#include <iostream>
#include <iomanip>
#include <conio.h>
#include <string>
#include <fstream>
#include <windows.h>

using namespace std;

// LA CONSTANTE DU PROGRAMME

const size_t REPONDANTS_MAX = 500; // nombre maximun de répondants du sondage


// LES STRUCTURES DE DONNÉES IMPOSÉES

struct Protection
{
	int  r2[REPONDANTS_MAX];
	char r3[REPONDANTS_MAX];
	char r4[REPONDANTS_MAX];
	char r5[REPONDANTS_MAX];
	char r6[REPONDANTS_MAX];
};

struct Infection
{
	bool r7;
	int	r8, r9, r10;
};

struct Repondant
{
	string ville;
	int age;
	int scolarite;
};


// L'UNIQUE VARIABLE GLOBALE

size_t nb_repondants;	// le nombre réel de répondants: nb_repondants = lireLesDonnéesDuSondage(...)


// DÉCALRATIONS DES FONCTIONS  -- écrire vos déclarations ici ...

size_t lireLesDonnéesDuSondage(bool r1[], Protection& pro, Infection inf[], Repondant rep[]);



// DÉFINITIONS DES FONCTIONS  --  écrire vos définitions ici ...




size_t lireLesDonnéesDuSondage(bool r1[], Protection& pro, Infection inf[], Repondant rep[])
{
	string name = "C21-TP3-Sondage.txt";
	fstream f(name, ios::in);

	if (f.fail()) // fichier ouvert ?
	{
		MessageBoxA(NULL, "Impossible d'ouvrir le fichier, Fin du programme", "Erreur", MB_OK | MB_ICONSTOP);
		exit(EXIT_FAILURE); // fin abrupte
	}

	char c;
	size_t r;
	for (r = 0; r < REPONDANTS_MAX; ++r)									// lire les réponses de chaque répondant
	{
		f >> c;	if (c == 'O') r1[r] = true; else r1[r] = false;				// r1
		f >> pro.r2[r] >> pro.r3[r] >> pro.r4[r] >> pro.r5[r] >> pro.r6[r];	// r2 à r6
		f >> c; if (c == 'O') inf[r].r7 = true; else inf[r].r7 = false;		// r7
		f >> inf[r].r8 >> inf[r].r9 >> inf[r].r10;							// r8 à r10
		f >> rep[r].ville >> rep[r].age >> rep[r].scolarite;				// ville, age, scolarité
		if (f.fail()) { f.clear(); break; }
	}
	f.close();
	return r; // r = le nombre de répondants lus
}


int main()
{
	SetConsoleCP(1252);
	SetConsoleOutputCP(1252);

	// Pour recevoir les données du sondage
	bool r1[REPONDANTS_MAX] = {};				// pour la  réponse  1
	Protection pro = {};						// pour les réponses 2-3-4-5-6
	Infection inf[REPONDANTS_MAX] = {};			// pour les réponses 7-8-9-10
	Repondant rep[REPONDANTS_MAX] = {};			// pour les réponses ville, age, scolarité

	// A - Charger les données du sondage
	
	nb_repondants = lireLesDonnéesDuSondage(r1,pro,inf,rep);

	// B - Écrire votre code ici ...


	_getch();
}