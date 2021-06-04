/*

AUTEUR: Lemar Andar

DESCRIPTION: Systeme de banque en C++

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

const double MARGE_CREDIT_MAX = 10000;		// marge de crédit maximun d'un compte du client
const double SOLDE_COMPTE_MAX = 1000000;	// maximun à ne pas dépasser dans un compte d'un client

/* -------------------------------------- */
/* LES STRUCTURES DE DONNÉES DU PROGRAMME */
/* -------------------------------------- */

enum Commandes { ajouter, depot, retrait, virement, infos, liste, supprimer, quitter };		// À COMPLÉTER AVEC LES AUTRES COMMANDES ...

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

struct Client								// informations relatives à un client
{
	Personne	info;
	Compte		comptes[COMPTES_MAX];
	time_t		ouverture;					// date d'ouverture
};

struct Banque								// La banque de clients
{
	int cpt;
	Client clients[CLIENTS_MAX];
};

/* ---------------------------- */
/* LES PROTOTYPES DES FONCTIONS */
/* ---------------------------- */

void ui_flushAll();
void ui_bip();
double arrondir(double v, int p);
void tableauCompte(Banque& bq);

/* ----------------------------------------- */
/* LES FONCTIONS TRÈS GÉNÉRALES DU PROGRAMME */
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
/* FONCTIONS GÉNÉRALES POUR L'INTERFACE USAGER (UI) EN LECTURE OU ÉCRITURE */
/* ----------------------------------------------------------------------- */

void ui_afficherMenuPrincipal()
{
	int x = 16, y = 0;
	gotoxy(x, y);  cout << "BANQUE CVM - Succ C21";
	gotoxy(x, 4);  cout << "1. Ajouter un client";
	gotoxy(x, 6);  cout << "2. Dépôt";
	gotoxy(x, 8);  cout << "3. Retrait";
	gotoxy(x, 10); cout << "4. Virement";
	gotoxy(x, 12); cout << "5. Afficher les informations d'un client";
	gotoxy(x, 14); cout << "6. Lister les clients et leur crédit actuel";
	gotoxy(x, 16); cout << "7. Supprimer un client";
	gotoxy(x, 18); cout << "8. Quitter";
	gotoxy(x, 24); cout << "Entrez votre choix: ";

	x = wherex(); y = wherey();
	gotoxy(x, y);
}

Commandes ui_lireUnChoixValideDuMenuPrincipal()
{ 
	Commandes cmd = quitter; // commande par défaut
	bool valide = false;
	
	do {
		int c = _getch();
		switch (c) {
			case 49: cmd = ajouter;		break;
			case 50: cmd = depot;		break;
			case 51: cmd = retrait;		break;
			case 52: cmd = virement;	break;
			case 53: cmd = infos;		break;
			case 54: cmd = liste;		break;
			case 55: cmd = supprimer;	break;
			case 56: cmd = quitter;		break;
		}
		if (c < 49 || c > 56)
			ui_bip();
		else 
			valide = true;
	}
	while (!valide);
	return cmd;
}


// Suggestion de prototypes de fonctions

int ui_lireUnNoDeClient(int max);
void ui_lireUnNoDeCompteValide(int cmp, Banque& bq);
double ui_lireUnMontantValide(double max);
void ui_afficherLesInformationsDuClient(Client client);
Client ui_lireLesInfosNouveauClient();

string afficheNomComplet(int noClient, Banque& bq) 
{
	string s;
	s = bq.clients[noClient].info.nom.prenom;
	s += " ";
	s += bq.clients[noClient].info.nom.nom;
	return s;
}

int ui_lireUnNoDeClient(int max)
{
	//validation de l'entrée du numero de client
	gotoxy(0, 14);
	int noClient;
	bool valide = false;
	int x = wherex(), y = wherey();
	do
	{
		cin.ignore(cin.rdbuf()->in_avail());
		cout << "Numéro du client  : ";
		cin >> noClient;
		if (cin.fail())
			cin.clear();
		else if (noClient > max)
		{
			gotoxy(x, y); clreol(); ui_flushAll();
		}
		else if (noClient == 0)
		{
			ui_bip(); clrscr();
		}
		else
			valide = true;
	}
	while (!valide);
	gotoxy(0, 3);
	return noClient;
}

void ui_lireUnNoDeCompteValide(int cmp, Banque& bq)
{
	//valdation de la marge de credit
	int i = bq.cpt;
	int x = wherex(), y = wherey();
	bool valide = false;
	do {
		cin.ignore(cin.rdbuf()->in_avail());
		cin >> bq.clients[i].comptes[cmp].margeCredit;
		if (cin.fail())
			cin.clear();
		else if (bq.clients[i].comptes[cmp].margeCredit > MARGE_CREDIT_MAX)
		{
			gotoxy(x, y); clreol();
		}
		else
			valide = true;
	}
	while (!valide);
	
	bq.clients[i].comptes[cmp].solde = 0;
}

double ui_lireUnMontantValide(double max) 
{
	bool valide = false;
	int i = 0;
	double montant = 0;
	int x = wherex(), y = wherey();
	do 
	{
		cin.ignore(cin.rdbuf()->in_avail());
		cout << "Montant : ";
		cin >> montant;
		if (cin.fail())
			cin.clear();
		else if (montant > max)
		{
			gotoxy(x, y); clreol();
		}
		else
			valide = true;
	}
	while (!valide);
	return montant;
}

void afficherTableauCompte(int cl, Banque& bq)
{
	cout << "Nom :  " << afficheNomComplet(cl - 1, bq) << "\n\n";
	cout << " # Comptes          Solde     Marge de crédit" << "\n\n";
	for (int i = 0; i < 3; ++i)
		cout << right << setw(6) << i + 1 << setw(19) << bq.clients[cl - 1].comptes[i].solde << " $" <<
		setw(18) << bq.clients[cl - 1].comptes[i].margeCredit << setw(2) << " $" << endl;
}

int compteValide()
{
	int cmp;
	bool valide = false;
	int x = wherex(), y = wherey();
	do
	{
		cin.ignore(cin.rdbuf()->in_avail());
		cmp = _getche();
		if (cin.fail())
			cin.clear();
		else if (cmp > '3')
		{
			gotoxy(x, y); clreol(); ui_flushAll();
		}
		else
			valide = true;
	}
	while (!valide);
	return cmp;
}
/* ------------------------------------------------------------ */
/* LES FONCTIONS OBLIGATOIRES POUR CHAQUE COMMANDE DU PROGRAMME */
/* ------------------------------------------------------------ */

void cmd_ajouterUnNouveauClient( Banque& bq )
{
	clrscr(); 
	time_t secondes = time(NULL); tm date; localtime_s(&date, &secondes);
	int i = bq.cpt;
	bq.clients[i];
	cout << "1. Transaction - ajouter un client"<< "\n\n";
	if (bq.cpt < CLIENTS_MAX)
	{ 
		cout << left << "Création du client #" << bq.cpt + 1 << "\n\n";
		cout << setw(22) << "Prénom"						<< ": ";
		getline(cin, bq.clients[i].info.nom.prenom);							  
		cout << setw(22) << "Nom"							<< ": ";
		getline(cin, bq.clients[i].info.nom.nom);
		cout << endl;					  
		cout << setw(22) << "Numéro civique"				<< ": ";
		getline(cin, bq.clients[i].info.adresse.noCivique);							  
		cout << setw(22) << "Rue"							<< ": ";
		getline(cin, bq.clients[i].info.adresse.rue);
		cout << setw(22) << "Ville"							<< ": ";
		getline(cin, bq.clients[i].info.adresse.ville);
		cout << setw(22) << "Code postal"					<< ": ";
		getline(cin, bq.clients[i].info.adresse.codePostal);								  
		cout << setw(22) << "Téléphone"						<< ": ";
		getline(cin, bq.clients[i].info.telephone);
		cout << endl;
		cout << setw(28) << "Numéro d'assurance sociale"	<< ": ";
		getline(cin, bq.clients[i].info.nas);
		cout << endl;

		cout << "Marge de crédit du compte #1 (Max de 10000 $) : ";
		ui_lireUnNoDeCompteValide(0, bq);
		cout << "Marge de crédit du compte #2 (Max de 10000 $) : ";
		ui_lireUnNoDeCompteValide(1, bq);
		cout << "Marge de crédit du compte #3 (Max de 10000 $) : ";
		ui_lireUnNoDeCompteValide(2, bq);
		cout << endl;
		bq.clients[i].ouverture = secondes;
		cout << "Date de création de ce dossier: " << date.tm_mday << "/" << date.tm_mon + 1 << "/" << date.tm_year + 1900 << "\n\n";
		++bq.cpt;
		cout << "Appuyez sur une touche pour continuer"; _getch();
	}
	else
	{
		gotoxy(0, 6);
		cout << "La banque n'acceuille plus de nouveaux clients, désolé...";
	}
	clrscr(); ui_flushAll();
}

void cmd_faireUnDepot( Banque& bq )
{
	gotoxy(0, 0); clrscr();
	cout << "2. cmd - faire un dépôt dans un compte client";
	gotoxy(0, 14);
	int noClient, noCmp;
	double montant = 0;

	noClient = ui_lireUnNoDeClient(bq.cpt);
	afficherTableauCompte(noClient, bq);
	
	gotoxy(0, 17);
	cout << "Au compte (1 à 3) : ";
	noCmp = compteValide();
	cout << "\n\n\n\n";
	cout << "Dépôt maximum : $ " << MARGE_CREDIT_MAX - bq.clients[noClient - 1].comptes[noCmp - '1'].solde << "\n\n";

	montant = ui_lireUnMontantValide(SOLDE_COMPTE_MAX);
	bq.clients[noClient - 1].comptes[noCmp - '1'].solde += montant; //ajoute au solde

	clrscr(); ui_flushAll();
}

void cmd_faireUnRetrait( Banque& bq)
{
	gotoxy(0, 0); clrscr();
	cout << "3. cmd - faire un retrait dans un compte client";
	gotoxy(0, 14);
	int noClient, noCmp;
	double montant = 0;

	noClient = ui_lireUnNoDeClient(bq.cpt);
	afficherTableauCompte(noClient, bq);

	gotoxy(0, 17);
	cout << "Du compte (1 à 3) : ";
	noCmp = compteValide();
	cout << "\n\n\n\n";
	cout << "Retrait maximum : $ " << bq.clients[noClient - 1].comptes[noCmp - '1'].margeCredit + bq.clients[noClient - 1].comptes[noCmp - '1'].solde << "\n\n";

	montant = ui_lireUnMontantValide(SOLDE_COMPTE_MAX);
	bq.clients[noClient - 1].comptes[noCmp - '1'].solde -= montant; //enleve au solde

	clrscr(); ui_flushAll();
}

void cmd_faireUnVirement( Banque& bq )
{
	gotoxy(0, 0); clrscr();
	cout << "4. cmd - faire un virement dans les comptes d'un seul client";
	gotoxy(0, 14);
	int noClient, noCmp1, noCmp2;
	double montant = 0;

	noClient = ui_lireUnNoDeClient(bq.cpt);
	afficherTableauCompte(noClient, bq);

	gotoxy(0, 17);
	cout << "Du compte (1 à 3) : ";
	noCmp1 = compteValide();
	cout << "\n\n";
	cout << "Au compte (1 à 3) : ";
	noCmp2 = compteValide();
	cout << "\n\n\n\n";
	cout << "Virement maximum : $ " << bq.clients[noClient - 1].comptes[noCmp1 - '1'].margeCredit + bq.clients[noClient - 1].comptes[noCmp1 - '1'].solde << "\n\n";

	montant = ui_lireUnMontantValide(SOLDE_COMPTE_MAX);
	bq.clients[noClient - 1].comptes[noCmp1 - '1'].solde -= montant; //enleve au solde 1
	bq.clients[noClient - 1].comptes[noCmp2 - '1'].solde += montant; //ajoute au solde 2

	clrscr(); ui_flushAll();
}

void cmd_afficherTouteslesInfosDuClient(Banque& bq )
{
	gotoxy(0, 0); clrscr();
	cout << "5. cmd - afficher toutes les informations d'un client";
	gotoxy(0, 14);
	int noClient;

	noClient = ui_lireUnNoDeClient(bq.cpt);
	afficherTableauCompte(noClient, bq);

	cout << endl << left << " Informations personnelles";
	gotoxy(0, 14);
	cout << setw(6) << " " << setw(17) << "#"		<< ": " << bq.clients[noClient - 1].info.adresse.noCivique << endl;
	cout << setw(6) << " " << setw(17) << "Rue"		<< ": " << bq.clients[noClient - 1].info.adresse.rue << endl;
	cout << setw(6) << " " << setw(17) << "Ville"	<< ": " << bq.clients[noClient - 1].info.adresse.ville << endl;
	cout << setw(6) << " " << setw(17) << "CP"		<< ": " << bq.clients[noClient - 1].info.adresse.codePostal << endl;
	cout << setw(6) << " " << setw(17) << "Tel"		<< ": " << bq.clients[noClient - 1].info.telephone << endl;
	cout << setw(6) << " " << setw(17) << "NAS"		<< ": " << bq.clients[noClient - 1].info.nas << "\n\n";
	cout << setw(6) << " " << setw(17) << "Membre"	<< ": " << bq.clients[noClient - 1].ouverture;

	gotoxy(1, 25);
	cout << "Appuyez sur une touche pour continuer"; _getch();
	clrscr(); ui_flushAll();
}

void cmd_listerLesClientsEtLeurCréditActuel( Banque& bq )
{
	clrscr(); gotoxy(0, 0);
	cout << "6. cmd - lister les clients et leur crédit actuel" << "\n\n";
	cout << "Rapport pour " << bq.cpt << " clients" << "\n\n";
	cout << "No    Nom                                     Limite de Retrait" << endl;
	cout << "--    ---                                     -----------------" << "\n\n";

	//affiche les infos de tout les clients
	for (int i = 0; i < bq.cpt; ++i)
	{
		cout << left << setw(6) << i + 1 << setw(40) << afficheNomComplet(i, bq) << right << setw(15) << 
			bq.clients[i].comptes[0].margeCredit + bq.clients[i].comptes[1].margeCredit + bq.clients[i].comptes[2].margeCredit +
			bq.clients[i].comptes[0].solde + bq.clients[i].comptes[1].solde + bq.clients[i].comptes[2].solde << left << " $" << endl; 
	}

	cout << endl << "Appuyez sur une touche pour continuer"; 
	_getch(); clrscr(); ui_flushAll();
}

void cmd_supprimerUnClient(Banque& bq)
{
	clrscr(); gotoxy(0, 0);
	cout << "7. cmd - Supprimer un client";
	gotoxy(0, 14);
	int noClient;

	noClient = ui_lireUnNoDeClient(bq.cpt);

	for (int i = noClient - 1; i < bq.cpt; ++i) //rewrites the "deleted" array with next one and keeps going until it hits the max
		bq.clients[i] = bq.clients[i + 1];

	bq.cpt--;
	clrscr(); ui_flushAll();
}

void cmd_quitter()
{
	clrscr();
	gotoxy(26, 13);
	cout << "A U      R  E  V  O  I  R";
	Sleep(500);
}

/* ---------------------- */
/* LA FONCTION PRINCIPALE */
/* ---------------------- */

int main()
{
	SetConsoleCP(1252);			// À FAIRE: dans les propriétés de la console, police(font) = LUCIDA CONSOLE
	SetConsoleOutputCP(1252);	// Permet d'écrire enfin vos string avec les accents !!!

	Banque bq;					// cette définition de variable DOIT RESTER ICI
	bq.cpt = 0;					// le nombre actuel de clients

	Commandes cmd;
	do
	{
		ui_afficherMenuPrincipal();
		cmd = ui_lireUnChoixValideDuMenuPrincipal();
		
		switch (cmd)
		{
			case ajouter:	cmd_ajouterUnNouveauClient(bq);				break;
			case depot:		cmd_faireUnDepot(bq);						break;
			case retrait:	cmd_faireUnRetrait(bq);						break;
			case virement:	cmd_faireUnVirement(bq);					break;
			case infos:		cmd_afficherTouteslesInfosDuClient(bq);		break;
			case liste:		cmd_listerLesClientsEtLeurCréditActuel(bq);	break;
			case supprimer: cmd_supprimerUnClient(bq);					break;
			case quitter:	cmd_quitter();								break;
		}

	} while(cmd != quitter );
	Sleep(500);
}