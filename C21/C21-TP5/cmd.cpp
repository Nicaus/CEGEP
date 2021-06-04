#include <iostream>
#include <iomanip>
#include <conio.h>
#include "console(v1.9).h"
#include "cmd.h"
#include "db.h"
#include "io.h"
#include "cin.h"

/* affiche les menus et fait la math */

using namespace std;


/*fonctions*/

bool ouinon()
{
	int choixb = 0, choix = 0;
	io_clean();
	while (true) {
		switch (choix = toupper(_getch()))
		{
			case 0:	case -32:
			if (_kbhit()) _getch();	break;

			case 13:
			if (choixb == 'O' || choixb == 'N')
				return choixb == 'O';
			break;

			case 'O': case 'N':
			cout << char(choixb = choix) << "\b"; break;
		}
	}
}

template <typename Type>
void permuter(Type& a, Type& b)
{
	Type temp = a;
	a = b;
	b = temp;
}

string nomComplet(Participant& p)
{
	string s;
	s = p.prenom;
	s += " ";
	s += p.nom;
	return s;
}

double montantTotalparP(Participant& p)
{
	double total = 0;

	for (int i = 0; i < p.nbDep; i++)
		total += p.liste[i].montant;

	p.montantTotal = total;
	return total;
}

double grandTotal(Participant& p, int no)
{
	double allMontant = 0;

	for (int i = 1; i < no + 1; i++)
	{
		db_read(i, &p);
		allMontant += montantTotalparP(p);
	}
	return allMontant;
}

double quotePart()
{
	Participant p;
	int no = db_size();
	double gt = grandTotal(p, no);

	if (no > 1)
	{
		return gt / no;
	}
	else
		return 0;
}

void afficherInfo(Participant& p, int no)
{
	int x = MARG, a = MARG + 5, s = 12;
	clrscr(); io_clean(); io_titre();
	db_read(no, &p);

	gotoxy(x, 4); cout << "Informations personnelles " << "(#" << no << ")";
	gotoxy(a, 6); cout << setw(s) << left << "Nom" << ": " << p.prenom << " " << p.nom;
	gotoxy(a, 8); cout << setw(s) << "Adresse" << ": " << p.addresse.noCiv << " " << p.addresse.rue << ", " << p.addresse.ville << ", " << p.addresse.codePostal;
	gotoxy(a, 9); cout << setw(s) << "Téléphone" << ": " << p.addresse.telephone;
	gotoxy(x, 12); cout << "Listes des dépenses (max 10)";

	int nbdep = p.nbDep;
	if (nbdep < 1)
	{
		gotoxy(x, 14); cout << "Aucune dépense";
	}
	else
	{
		gotoxy(0, 14); int j = 0;
		for (int i = 0; i < nbdep; i++)
		{
			cout << setw(10) << right << j + 1 << ". " <<
				setw(22) << io_dateHeure(p.liste[i].date) <<
				setw(10) << fixed << setprecision(2) << p.liste[i].montant << " $  " <<
				left << p.liste[i].description << endl;
			j++;
		}
		double total = montantTotalparP(p);

		gotoxy(0, nbdep + 14); cout << right << setw(46) << "-----------" << left;
		gotoxy(0, nbdep + 15); cout << right << setw(44) << total << left << " $";
	}
}

void ajouterDep(int no, Participant& p)
{
	int x = 4;

	db_read(no, &p);
	io_clean(); cvmResetColor();
	gotoxy(x, 28); clreol();
	montantValide(p); cvmResetColor();

	io_clean();
	gotoxy(x, 26); io_texteCouleur(cvmColor::JAUNE, "Description: ");
	io_lireString(s_desc, p.liste[p.nbDep].description); cvmResetColor();

	io_clean(); time_t date = time(NULL);
	p.liste[p.nbDep].date = date;

	p.nbDep += 1;
	db_write(no, &p);
	afficherInfo(p, no);
}

void ajouterDepEncore(int no, Participant& p)
{
	int x = 4;
	gotoxy(x, 28); io_texteCouleur(cvmColor::JAUNE, "Désirez-vous ajouter une autre dépense (O / N) : ");
	while (ouinon())
	{
		ajouterDep(no, p);
		if (p.nbDep == s_nbDep) { io_clean(); break; }
		gotoxy(x, 28); io_texteCouleur(cvmColor::JAUNE, "Désirez-vous ajouter une autre dépense (O / N) : ");
	}
	gotoxy(x, 28); clreoscr();

	io_texteCouleur(cvmColor::JAUNE, "Dépenses enregistrées !"); _getch();
}

void supprimerDep(int no, Participant& p)
{
	int x = 4, dep;
	db_read(no, &p); cvmResetColor();

	gotoxy(x, 28); clreol();
	dep = depValide(p); cvmResetColor(); io_clean();

	/* efface la depense choisi */
	p.liste[dep].montant = 0;
	for (int i = 0; i < s_desc; i++)
		p.liste[dep].description[i] = '\0';
	p.liste[dep].date = '\0';

	/* permute les autres choix pour les replacer */
	for (int i = dep; i < p.nbDep; i++)
	{
		permuter(p.liste[i + 1].montant, p.liste[i].montant);
		for (int j = 0; j < s_desc; j++)
			permuter(p.liste[i + 1].description[j], p.liste[i].description[j]);
		permuter<time_t>(p.liste[i + 1].date, p.liste[i].date);
	}

	p.nbDep -= 1;
	db_write(no, &p); afficherInfo(p, no);

	gotoxy(x, 28); clreoscr(); io_texteCouleur(cvmColor::JAUNE, "Dépenses enregistrées !"); _getch();
	cvmResetColor();
}

void supprimerDepEncore(int no, Participant& p)
{
	int x = 4;
	gotoxy(x, 28); io_texteCouleur(cvmColor::JAUNE, "Désirez-vous supprimmer une autre dépense (O / N) : ");
	while (ouinon())
	{
		supprimerDep(no, p);
		if (p.nbDep == 0) { io_clean(); break; }
		gotoxy(x, 28); io_texteCouleur(cvmColor::JAUNE, "Désirez-vous supprimer une autre dépense (O / N) : ");
	}
	gotoxy(x, 28); clreoscr();

	io_texteCouleur(cvmColor::JAUNE, "Dépenses supprimées enregistrées !"); _getch();
}


/*commandes*/

void CMD_AjouterUnParticipant()
{
	clrscr(); io_clean(); io_titre();
	int noPart = 1, s = 22, x = MARG;
	int no = db_size() + 1;
	string info = "Informations personnelles", adresse = "Adresse";

	Participant participant = {};

	gotoxy(x, 4);	cout << "Création du participant #" << no;
	gotoxy(x, 7);	cout << info;
	gotoxy(x, 8);	cout << setfill('-') << setw(info.size()) << "" << setfill(' ');
	gotoxy(x, 10);	cout << setw(s) << left << "Prénom" << ": "; io_lireString(s_prenom, participant.prenom);
	gotoxy(x, 11);	cout << setw(s) << "Nom" << ": "; io_lireString(s_nom, participant.nom);
	gotoxy(x, 13);	cout << adresse;
	gotoxy(x, 14);	cout << setfill('-') << setw(adresse.size()) << "" << setfill(' ');
	gotoxy(x, 16);	cout << setw(s) << "Numéro civique" << ": "; io_lireString(s_noCiv, participant.addresse.noCiv);
	gotoxy(x, 17);	cout << setw(s) << "Rue" << ": "; io_lireString(s_rue, participant.addresse.rue);
	gotoxy(x, 18);	cout << setw(s) << "Ville" << ": "; io_lireString(s_ville, participant.addresse.ville);
	gotoxy(x, 19);	cout << setw(s) << "Code Postal" << ": "; io_lireString(s_codeP, participant.addresse.codePostal);
	gotoxy(x, 20);	cout << setw(s) << "Numéro de téléphone" << ": "; io_lireString(s_tel, participant.addresse.telephone);
	participant.nbDep = 0;

	db_write(no, &participant);
}

void CMD_AfficherUnParticipant()
{
	io_clean();
	int x = MARG, no;
	Participant p;

	no = partValide(p);

	afficherInfo(p, no);
	gotoxy(x, 28); io_texteCouleur(cvmColor::JAUNE, "Appuyer sur une touche pour continuer ... "); _getch();
	cvmResetColor();
}

void CMD_AjouterDesDepenses()
{
	int x = MARG, no, i = 0;
	io_clean();
	Participant p;

	no = partValide(p);
	afficherInfo(p, no);

	if (p.nbDep != s_nbDep)
	{
		gotoxy(x, 28); io_texteCouleur(cvmColor::JAUNE, "Désirez-vous ajouter une dépense (O / N) : ");
	
		switch (bool temp = ouinon())
		{
			case true: 
				ajouterDep(no, p);
				ajouterDepEncore(no, p);
				break;

			case false: 
				break;
		}
	}
	else
	{
		gotoxy(x, 28); io_texteCouleur(cvmColor::JAUNE, "Le maximun de 10 dépenses est déjà atteint ! ");
		_getch();
	}

	gotoxy(x, 28); clreol();
	i++;
}

void CMD_SupprimerDesDepenses()
{
	int x = MARG, no;
	io_clean();
	Participant p;

	no = partValide(p);
	afficherInfo(p, no);

	if (p.nbDep > 1)
	{
		gotoxy(x, 28); io_texteCouleur(cvmColor::JAUNE, "Désirez-vous supprimer une dépense (O / N) : ");

		switch (bool temp = ouinon())
		{
			case true:
			supprimerDep(no, p);
			supprimerDepEncore(no, p);
			break;

			case false:
			break;
		}
	}
	else
	{
		gotoxy(x, 28); io_texteCouleur(cvmColor::JAUNE, "Ce participant n'a pas de dépense à son dossier!");
		_getch();
	}
}

void CMD_AfficherEtatDesComptes()
{
	int x = MARG, a = 6;

	clrscr(); io_clean(); io_titre();
	Participant p;
	int no = db_size();
	time_t date = time(NULL);

	gotoxy(x + 70, 0); cout << no << " " << "participants";
	gotoxy(x, 3); cout << "ÉTAT DES COMPTES  (date: " << io_dateHeure(date) << ") " 
		<< " quote-part : " << fixed << setprecision(2) << quotePart() << " $";

	for (int i = 1; i < no + 1; i++)
	{
		gotoxy(x + 4, a);
		cout << left;
		db_read(i, &p);
		cout << i << ") " << setw(37) << nomComplet(p);
		cout << setw(10) << " " << "Dépenses : " << setw(10) << right << fixed << setprecision(2) << montantTotalparP(p) << " $" ;
		if (montantTotalparP(p) > quotePart())
		{
			double avance = montantTotalparP(p) - quotePart();
			cout << setw(18); io_texteCouleur(cvmColor::CYAN, "En avance de :"); 
			cout << setw(10) << fixed << setprecision(2) << avance << " $"; cvmResetColor();
		}
		else if (montantTotalparP(p) < quotePart())
		{
			double retard = quotePart() - montantTotalparP(p);
			cout << setw(18); io_texteCouleur(cvmColor::ROUGE, "En retard de :");
			cout << setw(10) << fixed << setprecision(2) << retard << " $"; cvmResetColor();
		}
		cout << "\n\n";
		a += 2;
	}
	gotoxy(x + 4, a + 1); cout << left << setw(37) << " " << setw(10) << " " << "Grand Total : " << setw(10) << right << fixed << setprecision(2) << grandTotal(p, no) << " $";

	gotoxy(x, a + 3); io_texteCouleur(cvmColor::JAUNE, "Appuyer sur une touche pour continuer ... "); _getch();
	cvmResetColor();
}

void CMD_AfficherUnScenarioDeReglements()
{
	int x = MARG, y = 6;

	clrscr(); io_clean(); io_titre();
	time_t date = time(NULL);
	Participant p;
	Participant q;
	int no = db_size();

	gotoxy(x + 70, 0); cout << no << " " << "participants";
	gotoxy(x, 3); cout << "SCÉNARIO DE RÈGLEMENTS  (date: " << io_dateHeure(date) << ") "
		<< " quote-part : " << fixed << setprecision(2) << quotePart() << " $";
	
	for (int i = 1; i < no + 1; i++)
	{
		db_read(i, &p);
		if (montantTotalparP(p) > quotePart())
		{
			int j = 1;
			double avance = montantTotalparP(p) - quotePart();
			cout << left; io_texteCouleur(cvmColor::CYAN, "");
			gotoxy(x, y); cout << setw(48) << nomComplet(p) << "Dépenses : " << setw(13) << montantTotalparP(p) 
				<< "Total à recevoir : " << setw(30)<< fixed << setprecision(2) << avance; cvmResetColor();
			y += 2;

			for (int k = 1; k < no + 1; k++)
			{
				db_read(k, &q);
				if (montantTotalparP(q) < quotePart())
				{
					double retard = quotePart() - montantTotalparP(p);

					if (retard <= avance)
					{
						p.montantTotal -= retard;
						q.montantTotal += retard;
					}

					else if (retard > avance)
					{
						k--;
						p.montantTotal -= (retard - avance);
						q.montantTotal += (retard - avance);
					}

					gotoxy(x, y); cout << right << setw(15) << q.montantTotal 
						<< " $   de : " << nomComplet(q);
					y += 2;
				}
			}
		}
	}
	gotoxy(x, y); io_texteCouleur(cvmColor::JAUNE, "Appuyer sur une touche pour continuer ... "); _getch();
	cvmResetColor();
}

void CMD_SupprimerTousLesParticipants()
{
	int x = MARG;
	
	gotoxy(x, 26); io_texteCouleur(cvmColor::JAUNE, "Voulez-vous supprimer seulement les dépenses des participants (O / N) : ");

	if (ouinon())
	{
		io_clean(); Participant p = {};
		int no = db_size();

		for (int i = 1; i < no + 1; i++)
		{
			db_read(i, &p);
			p.nbDep = 0;
			db_write(i, &p);
		}
		gotoxy(x, 26); clreol();
	}
	else
	{
		gotoxy(x, 28); io_texteCouleur(cvmColor::JAUNE, "Voulez-vous supprimer tous les participants (O / N) : ");
		if (ouinon())
		{
			io_clean(); db_create();
			gotoxy(x, 26); clreoscr();
		}
	}
}