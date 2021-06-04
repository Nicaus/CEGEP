#pragma once
#include <ctime>

const int s_noCiv = 9;
const int s_rue = 31;
const int s_ville = 31;
const int s_codeP = 8;
const int s_tel = 17;
const int s_desc = 65;
const int s_prenom = 21;
const int s_nom = 21;
const int s_nbDep = 10;
const int s_liste = 10;
const double MAX = 99999.99;
const int MARG = 4;

struct Adresse
{
	char noCiv[s_noCiv];
	char rue[s_rue];
	char ville[s_ville];
	char codePostal[s_codeP];
	char telephone[s_tel];
};

struct Depense
{
	double montant;
	char description[s_desc];
	time_t date;
};

struct Participant
{
	char prenom[s_prenom];
	char nom[s_nom];
	Adresse addresse;
	int nbDep;
	Depense liste[s_liste];
	double montantTotal;
};

int db_size();
void db_create();
void db_open();
void db_close();

void db_read(size_t no, Participant* p);
void db_write(size_t no, Participant* p);