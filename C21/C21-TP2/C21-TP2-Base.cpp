/*

AUTEUR: 

DESCRIPTION: 

*/

#include <iostream>
#include <iomanip>
#include <conio.h>
#include <string>
#include <windows.h>

#include "console(v1.9).h"

using namespace std;

/* ------------------------------------ */
/* LES CONSTANTES GLOBALES DU PROGRAMME */
/* ------------------------------------ */

const int CLIENTS_MAX = 70;					// nombre maximal de clients
const int COMPTES_MAX = 3;					// nombre de comptes par client

const double MARGE_CREDIT_MAX = 10000;		// marge de cr�dit maximun d'un compte du client
const double SOLDE_COMPTE_MAX = 1000000;	// maximun � ne pas d�passer dans un compte d'un client


/* -------------------------------------- */
/* LES STRUCTURES DE DONN�ES DU PROGRAMME */
/* -------------------------------------- */

enum Commandes { ajouter, quitter };		// � COMPL�TER AVEC LES AUTRES COMMANDES ...

struct Nom									// nom d'un client
{
	string prenom;
	string nom;
};

struct Adresse								// adresse d'un client
{
	string noCivique;
	string rue;
	string ville;
	string codePostal;
};

struct Personne								// informations personnelles d'un client
{
	Nom		nom;
	Adresse	adresse;
	string	telephone;
	string	nas;
};

struct Compte								// un compte d'un client
{
	double solde;
	double margeCredit;
};

struct Client								// informations relatives � un client
{
	Personne	info;
	Compte		comptes[COMPTES_MAX];
	time_t		ouverture; // date d'ouverture
};

struct Banque								// La banque de clients
{
	int cpt;
	Client clients[CLIENTS_MAX];
};


/* ----------------------------------- */
/* LES VARIABLES GLOBALES DU PROGRAMME */
/* ----------------------------------- */

// Attention: les variables globales ne sont pas permises dans ce TP


/* ---------------------------- */
/* LES PROTOTYPES DES FONCTIONS */
/* ---------------------------- */

void ui_flushAll();
void ui_bip();
double arrondir(double v, int p);

// Attention : �crire les prototypes de toutes vos fonctions ici ...
// ...


/* ----------------------------------------- */
/* LES FONCTIONS TR�S G�N�RALES DU PROGRAMME */
/* ----------------------------------------- */

void ui_flushAll() // pour vider les 2 tampons 
{
	if (cin.fail()) cin.clear();			// s'assure que le cin est remis en marche
	cin.ignore(cin.rdbuf()->in_avail());	// vide le tampon du cin
	while (_kbhit()) _getch();				// vide le tampon de la console
}

void ui_bip() { Beep(200,300); }

double arrondir(double valeur, int precision)
{
	double pow10 = pow(10, precision);
	return round(valeur * pow10) / pow10;
}



/* ----------------------------------------------------------------------- */
/* FONCTIONS G�N�RALES POUR L'INTERFACE USAGER (UI) EN LECTURE OU �CRITURE */
/* ----------------------------------------------------------------------- */

void ui_afficherMenuPrincipal()
{
	// �crire le code ici ...
}

Commandes ui_lireUnChoixValideDuMenuPrincipal()
{ 
	Commandes cmd = quitter; // commande par d�faut

	// �crire le code ici ...

	return cmd;
}


// Suggestion de prototypes de fonctions

int ui_lireUnNoDeClient(int max);
int ui_lireUnNoDeCompteValide();
double ui_lireUnMontantValide(double max);
void ui_afficherLesInformationsDuClient(Client client);
Client ui_lireLesInfosNouveauClient();


/* ------------------------------------------------------------ */
/* LES FONCTIONS OBLIGATOIRES POUR CHAQUE COMMANDE DU PROGRAMME */
/* ------------------------------------------------------------ */

void cmd_ajouterUnNouveauClient( /* Param�tres ? indice: obtenir une r�f�rence sur la variable bk de main */ )
{
	// �crire le code ici ...
}

void cmd_faireUnDepot( /* Param�tres ? */ )
{
	// �crire le code ici ...
}

void cmd_faireUnRetrait( /* Param�tres ? */ )
{
	// �crire le code ici ...
}

void cmd_faireUnVirement( /* Param�tres ? */ )
{
	// �crire le code ici ...
}

void cmd_afficherTouteslesInfosDuClient( /* Param�tres ? */ )
{
	// �crire le code ici ...
}

void cmd_listerLesClientsEtLeurCr�ditActuel( /* Param�tres ? */ )
{
	// �crire le code ici ...
}

void cmd_supprimerUnClient( /* Param�tres ? */ )
{
	// �crire le code ici ...
}

void cmd_quitter( /* Param�tres ? */)
{
	// �crire le code ici ...
}

/* ---------------------- */
/* LA FONCTION PRINCIPALE */
/* ---------------------- */

int main()
{
	SetConsoleCP(1252);			// � FAIRE: dans les propri�t�s de la console, police(font) = LUCIDA CONSOLE
	SetConsoleOutputCP(1252);	// Permet d'�crire enfin vos string avec les accents !!!

	Banque bq;					// cette d�finition de variable DOIT RESTER ICI
	bq.cpt = 0;					// le nombre actuel de clients

	Commandes cmd;
	do
	{
		ui_afficherMenuPrincipal();
		cmd = ui_lireUnChoixValideDuMenuPrincipal();
		
		switch (cmd)
		{
			case ajouter: cmd_ajouterUnNouveauClient( /* cette fonction doit avoir acc�s la banque bq de main */ ); break;
			
			//...

			case quitter: cmd_quitter(); break;
		}

	} while(cmd != quitter );
}