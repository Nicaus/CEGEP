#include <iostream>
#include <iomanip>
#include <conio.h>
#include <string>
#include "console(v1.9).h"
#include "db.h"
#include "cmd.h"
#include "io.h"
#pragma warning (disable:26812) //enum class unscoped pour aucune raison

using namespace std;

enum Commandes { ajouterpart, dossier, ajouterdep, supprimerdep, etat, scenario, supprimerpart, quitter, faux };

void iu_afficherMenu()
{
	int x = MARG;
	int no = db_size();

	clrscr();
	io_titre();

	gotoxy(x + 70, 0); cout << no << " " << "participants";

	gotoxy(x, 4);	cout << "1. Ajouter un participant";
	gotoxy(x, 6);	cout << "2. Afficher le dossier d'un participant";
	gotoxy(x, 8);	cout << "3. Ajouter des dépenses";
	gotoxy(x, 10);	cout << "4. Supprimer des dépenses";
	gotoxy(x, 12);	cout << "5. Afficher l'état des comptes";
	gotoxy(x, 14);	cout << "6. Afficher un scénario de règlements";
	gotoxy(x, 16);	cout << "D. Supprimer tous les participants";
	gotoxy(x, 18);	cout << "Q. Quitter";

	gotoxy(x, 24); io_texteCouleur(cvmColor::JAUNE, "Entrez votre choix : ");
}

Commandes ui_choix()
{
	char choix = NULL;
	Commandes cmd = faux;
	
	do
	{
		switch (choix = toupper(_getch()))
		{
			case '1': cmd = ajouterpart;	break;
			case '2': cmd = dossier;		break;
			case '3': cmd = ajouterdep;		break;
			case '4': cmd = supprimerdep;	break;
			case '5': cmd = etat;			break;
			case '6': cmd = scenario;		break;
			case 'D': cmd = supprimerpart;	break;
			case 'Q': cmd = quitter;		break;
		}
	}
	while (cmd == Commandes::faux);
	cout << choix;
	cvmResetColor();
	return cmd;
}

void main()
{
	SetConsoleCP(1252);
	SetConsoleOutputCP(1252);

	Commandes cmd = {};
	db_open();
	do {
		iu_afficherMenu();
		switch (cmd = ui_choix())
		{
			case ajouterpart:	CMD_AjouterUnParticipant();				break;
			case dossier:		CMD_AfficherUnParticipant();			break;
			case ajouterdep:	CMD_AjouterDesDepenses();				break;
			case supprimerdep:	CMD_SupprimerDesDepenses();				break;
			case etat:			CMD_AfficherEtatDesComptes();			break;
			case scenario:		CMD_AfficherUnScenarioDeReglements();	break;
			case supprimerpart: CMD_SupprimerTousLesParticipants();		break;
		}
	}
	while (cmd != quitter);
	db_close();

	clrscr(); cvmSetColor(cvmColor::ROUGE);
	string GOODBYE = ("A  U    R  E  V  O  I  R"), SEMESTRE = ("je pense...");
	size_t larg_good = GOODBYE.size(), larg_semes = SEMESTRE.size();
	gotoxy(0, 15); cout << setw((120 - larg_good) / 2 + larg_good) << GOODBYE;
	Sleep(1000);
	gotoxy(0, 17); cout << setw((120 - larg_semes) / 2 + larg_semes) << SEMESTRE;
	Sleep(350);
	cvmResetColor();
}
