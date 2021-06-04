/*
	AUTEUR: Lemar Andar

	DESCRIPTION: Analyse de resultat
*/

#include <iostream>
#include <iomanip>
#include <conio.h>
#include <string>
#include <fstream>
#include <windows.h>
#include "console(v1.9).h"

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

struct Data
{
	string liste;
	int nbTest;
};

struct Item
{
	Data data;
	Item* next;
};

struct List
{
	Item* deb;
	Item* fin;
	size_t size;
};

// L'UNIQUE VARIABLE GLOBALE

size_t nb_repondants;	// le nombre réel de répondants: nb_repondants = lireLesDonnéesDuSondage(...)

// DÉCALRATIONS DES FONCTIONS  -- écrire vos déclarations ici ...

size_t lireLesDonnéesDuSondage(bool r1[], Protection& pro, Infection inf[], Repondant rep[]);
int stat_01(bool r1[]);
int stat_02(Protection& pro);
double stat_03(Protection& pro, Repondant rep[]);
double stat_04(Protection& pro, Repondant rep[]);
double stat_05(Protection& pro, Repondant rep[]);
double stat_06(Infection inf[]);
string stat_07(Infection inf[]);
int stat_08(Protection& pro, Infection inf[]);
double stat_09(Protection& pro, Infection inf[], Repondant rep[]);
string stat_10(Infection inf[], Repondant rep[]);

// DÉFINITIONS DES FONCTIONS  --  écrire vos définitions ici ...

int stat_01(bool r1[])
{
	size_t i; int j = 0;

	for (i = 0; i < nb_repondants; ++i)
		if (r1[i] == true)
			j++;

	return j;
}

int stat_02(Protection& pro)
{
	size_t i; int j = 0;

	for (i = 0; i < nb_repondants; ++i)
		if (pro.r3[i] == 'O')
			j++;

	return j;
}

double stat_03(Protection& pro, Repondant rep[])
{
	size_t i; 
	double j = 0, k = 0;
	double moyenne; 

	for (i = 0; i < nb_repondants; ++i)
	{
		if (rep[i].age > 29 && rep[i].age < 40)
		{
			j++;
			k += pro.r2[i];
		}
	}
	if (k != 0 || j != 0)
		moyenne = k / j;
	else
		moyenne = 0.0;

	return moyenne;
}

double stat_04(Protection& pro, Repondant rep[])
{
	size_t i; 
	double moyenne, j = 0, k = 0;

	for (i = 0; i < nb_repondants; ++i)
	{
		if (pro.r5[i] == 'O' || pro.r6[i] == 'O')
		{
			j++;
			k += rep[i].age;
		}
	}

	if (j != 0 || k != 0)
		return moyenne = k / j;
	else
		return moyenne = 0.0;
}

double stat_05(Protection& pro, Repondant rep[])
{
	size_t i;
	double pourcentage;
	double k = 0, j = 0;

	for (i = 0; i < nb_repondants; ++i) 
	{
		if (rep[i].ville == "Vaudreuil")
			k++;
		if (rep[i].ville == "Vaudreuil" && pro.r2[i] > 1)
			j++;
	}
	
	if (j != 0 || k != 0)
		return pourcentage = ((j / k) * 100);
	else
		return pourcentage = 0.0;
}

double stat_06(Infection inf[])
{
	size_t i;
	double pourcentage = 0.0;
	double j = 0;

	for (i = 0; i < nb_repondants; ++i)
	{
		if (inf[i].r7 == true)
			j++;
	}
	
	if (j != 0)
		return pourcentage = ((j / nb_repondants) * 100);
	else
		return pourcentage = 0.0;
}

string stat_07(Infection inf[])
{
	size_t i;
	int j = 1, k = 0;
	int type = inf->r8;
	string repandu;

	for (i = 0; i < nb_repondants; ++i)
	{
		if (inf[i].r8 == inf[i - 1].r8)
			k++;
		else if (k > j)
		{
			j = k;
			type = inf[i - 1].r8;
		}
		else 
			k = 1;
	}

	if (k > j)
	{
		j = k;
		type = inf[nb_repondants - 1].r8;
	}

	switch (type) {
		case 1: repandu = "Aucun"; break;
		case 2: repandu = "Savon à vasisselle"; break;
		case 3: repandu = "Purell"; break;
		case 4: repandu = "Eau de javel"; break;
		case 5: repandu = "Alcool à friction"; break;
	}

	return repandu;
}

int stat_08(Protection& pro, Infection inf[])
{
	size_t i;
	int compte = 0;

	for (i = 0; i < nb_repondants; ++i)
	{
		if (pro.r4[i] == 'N' && inf[i].r7 == false && inf[i].r10 > 1)
			compte++;
	}
	if (compte != 0)
		return compte;
	else
		return compte = 0;
}

double stat_09(Protection& pro, Infection inf[], Repondant rep[])
{
	double moyenne;
	double j = 0, k = 0;
	size_t i;

	for (i = 0; i < nb_repondants; ++i)
	{
		if (inf[i].r9 == 1)
		{
			if (pro.r2[i] < 1 || inf[i].r7 == false)
			{
				j++;
				k += rep[i].scolarite;
			}
		}
	}

	if (j != 0 || k != 0)
		return moyenne = k / j;
	else
		return moyenne = 0.0;
}

string stat_10(Infection inf[], Repondant rep[])
{
	List list = {};
	Data info = {};
	Item* ville = new Item{ info, nullptr };

	string rependu;

	for (size_t i = 0; i < nb_repondants; ++i)
	{
		info = { rep[i].ville, inf[i].r10 };
		Item* ville = new Item{ info, nullptr };

		if (list.fin)
			list.fin->next = ville;
		else
			list.deb = ville;

		list.fin = ville;
		list.size++;
	}

	//compte les test par ville
	Item* exist = list.deb;
	for (size_t j = 0; j < nb_repondants; ++j)
	{
		info = { rep[j].ville, inf[j].r10 };
		int nbtestparville = 0;
		while (exist)
		{
			if (rep[j].ville == exist->data.liste)
				nbtestparville += exist->data.nbTest;
			exist = exist->next;
		}
		exist = list.deb;
		exist->data.nbTest = nbtestparville;
		j++;
	}

	rependu = exist->data.liste;

	return rependu;
}

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
	cout << "Résultats du sondage: ( " << nb_repondants << " répondants )" << "\n\n";
	cout << "Statistiques";

	//affichage questions
	gotoxy(0, 4);
	cout << "01) Combien de personnes toussent souvent ?" << endl;
	cout << "02) Combien de personnes veulent un masque dans leur auto ?" << endl;
	cout << "03) Combien de masques, en moyenne, ont les gens qui sont dans la trentaine ?" << endl;
	cout << "04) Quel est l'âge moyen des gens qui se serviraient d'un masque pour décorer ou pour dormir?" << endl;
	cout << "05) Quel pourcentage des gens de Vaudreuil possèdent plus d'un masque ?" << endl;
	cout << "06) Quel pourcentage de la population utilise du désinfectant  ?" << endl;
	cout << "07) Quel est le type de desinfectant le plus répandu ?" << endl;
	cout << "08) Combien de gens non testé et n'utilisent pas de désinfectant ont déjà emprunté un masque ?" << endl;
	cout << "09) Combien d'années de scolarité, en moyenne, ont les gens infectés de Montréal sans masque ou sans désinfectant ?" << endl;
	cout << "10) Quelle est la ville ayant fait subir le plus grand nombre de test ?" << endl;

	//affichage resultat
	gotoxy(0, 16);
	cout << "Résultats" << "\n\n";
	cout << "01) = " << stat_01(r1) << endl;
	cout << "02) = " << stat_02(pro) << endl;
	cout << "03) = " << stat_03(pro, rep) << endl;
	cout << "04) = " << setprecision(3) << stat_04(pro, rep) << endl;
	cout << "05) = " << setprecision(3) << stat_05(pro, rep) << " %" << endl;
	cout << "06) = " << setprecision(3) << stat_06(inf) << " %" << endl;
	cout << "07) = " << stat_07(inf) << endl;
	cout << "08) = " << stat_08(pro, inf) << endl;
	cout << "09) = " << stat_09(pro, inf, rep) << endl;
	cout << "10) = " << stat_10(inf, rep) << endl;
	
	_getch();
}