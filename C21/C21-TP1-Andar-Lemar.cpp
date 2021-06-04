#include <iostream>
#include <iomanip>
#include <conio.h>
#include <time.h>
#include "console(v1.9).h"

using namespace std;

// CONSTANTES
const int LIG = 8, COL = 12;	// #lignes et #colonnes du damier

// CONSTANTES POUR L'AFFICHAGE SEULEMENT
const int START_X = 10;	// x du coin supérieur gauche du damier dans la fenêtre
const int START_Y = 2;	// y du coin supérieur gauche du damier dans la fenêtre

const int DELTA_X = 5;	// saut sur l'axe des X d'une case à l'autre
const int DELTA_Y = 3;	// saut sur l'axe des Y d'une case à l'autre

// DEFINITIONS DES TYPES GLOBAUX

// énumération des touches fléchées du clavier et leur code décimal ascii respectif
// voir arrow-keys.cpp pour un exemple
enum Arrow_keys 
{
	key_up			= 72,
	key_up_left		= 71,
	key_up_right	= 73,

	key_left		= 75,
	key_right		= 77,

	key_down		= 80,
	key_down_left	= 79,
	key_down_right	= 81,
};

enum État { CO, CS, CD, CF, CV }; // les états possibles d'une case du damier

struct Jeu
{
	int ptsAccum;				// points accumulés
	État damier[LIG][COL];		// damier du jeu où chaque case possède un état
};

// une position {l,c} du curseur dans le tableau damier
struct Pos
{
	int lig;	// [0 .. LIG-1]
	int col;	// [0 .. COL-1]
	int x = START_X + (col * DELTA_X);
	int y = START_Y + (lig * DELTA_Y);
};

// le curseur dans le tableau damier
struct Curseur
{
	Pos dep; // la case de départ -- ex: {0,0}
	Pos arr; // la case d'arrivée -- ex: {0,1} après key_right
};


int main()
{
	cout << setw(70) << left << "Decouvrez et amassez 15 cases $$$$";
	time_t debut, arret, diff;
	debut = time(NULL);

	// définition et init du jeu et de son damier
	Jeu jeu =
	{
		0, // ptsAccum

		{ // damier avec les états initiaux
			{ CO , CO , CO , CO , CO , CO , CO , CO , CV , CO , CO , CS },
			{ CO , CO , CV , CV , CO , CO , CO , CO , CO , CV , CO , CV },
			{ CO , CO , CV , CS , CV , CO , CO , CO , CO , CO , CV , CS },
			{ CO , CO , CV , CS , CV , CO , CO , CV , CV , CO , CV , CS },
			{ CS , CO , CV , CV , CV , CS , CV , CO , CV , CO , CV , CO },
			{ CS , CO , CS , CS , CO , CS , CV , CS , CV , CO , CV , CO },
			{ CS , CO , CS , CO , CO , CO , CV , CV , CV , CO , CV , CO },
			{ CS , CS , CO , CO , CO , CO , CO , CO , CO , CO , CO , CO }
		}
	};
	cout << "Points: 0";

	Curseur curs;
	curs.dep = { 0, 0 };

	//couleur des cases
	const char bleue = '\xB2', vert = '\x24', rose = '\xB0', noir = ' ';

	//affichage du damier avec les cases noirs
	cvmSetColor(cvmColor::BLEU);
	for (int i = 0; i < LIG; ++i)
	{
		for (int j = 0; j < COL; ++j)
		{
			Pos caseBleue = { i, j };
			if (jeu.damier[caseBleue.lig][caseBleue.col] == CO || CS)
			{
				for (int l = 0; l < 2; ++l)
				{
					gotoxy(caseBleue.x, caseBleue.y++);
					for (int c = 0; c < 4; ++c) 
						cout << bleue;
				}
			}

			Pos caseNoir = { i, j };
			if (jeu.damier[caseNoir.lig][caseNoir.col] == CV)
			{
				for (int l = 0; l < 2; ++l)
				{
					gotoxy(caseNoir.x, caseNoir.y++);
					for (int c = 0; c < 4; ++c)
						cout << noir;
				}
			}
		}
	}
	cvmResetColor();


	//pour le deplacement
	uint8_t c;

	//case curseur
	string cuH, cuB;
	cuH = '\xC9'; cuH += '\xCB'; cuH += '\xCB'; cuH += '\xBB';
	cuB = '\xC8'; cuB += '\xCA'; cuB += '\xCA'; cuB += '\xBC';

	//mouvement du curseur
	int x = START_X + (curs.dep.lig * DELTA_X);
	int y = START_Y + (curs.dep.col * DELTA_Y);

	curs.arr.lig = curs.dep.lig;
	curs.arr.col = curs.dep.col;

	//position de depart du curseur
	Pos caseCur = {0, 0};
	cvmSetColor(cvmColor::JAUNE);
	gotoxy(caseCur.x, caseCur.y++);
	cout << cuH;
	gotoxy(caseCur.x, caseCur.y++);
	cout << cuB;
	
	do
	{
		do
		{ 
			c = _getch();
			gotoxy(x, y);
			if (c == 0 || c == 224) // vérifier s'il s'agit d'un caractère spécial. Si oui, il faut lire le suivant
			{
				if (_kbhit())
				{
					c = _getch();
					switch (c) //mouvement du curseur
					{
						case key_up:			--curs.arr.lig;   curs.arr.col;  	break;
						case key_up_left:		--curs.arr.lig; --curs.arr.col;  	break;
						case key_up_right:		--curs.arr.lig; ++curs.arr.col;  	break;
						case key_left:			  curs.arr.lig; --curs.arr.col;  	break;
						case key_right:			  curs.arr.lig; ++curs.arr.col; 	break;
						case key_down:			++curs.arr.lig;   curs.arr.col;  	break;
						case key_down_left:		++curs.arr.lig; --curs.arr.col;  	break;
						case key_down_right:	++curs.arr.lig; ++curs.arr.col; 	break;
					}
				}
			}
		}
		while (curs.arr.lig < 0 || curs.arr.lig > 7 || curs.arr.col < 0 || curs.arr.col > 11);
				
		//changement d'etat
		if (jeu.damier[curs.arr.lig][curs.arr.col] == CO)
			jeu.damier[curs.arr.lig][curs.arr.col] = CF;
		else if (jeu.damier[curs.arr.lig][curs.arr.col] == CS)
			jeu.damier[curs.arr.lig][curs.arr.col] = CD;
		else if (jeu.damier[curs.arr.lig][curs.arr.col] == CD)
			jeu.damier[curs.arr.lig][curs.arr.col] = CF;
		else if (jeu.damier[curs.arr.lig][curs.arr.col] == CF)
			jeu.damier[curs.arr.lig][curs.arr.col] = CV;

		//affichage du curseur
		Pos caseCur = { curs.arr.lig, curs.arr.col };
		cvmSetColor(cvmColor::JAUNE);
		gotoxy(caseCur.x, caseCur.y++);
		cout << cuH;
		gotoxy(caseCur.x, caseCur.y++);
		cout << cuB;
		cvmResetColor();

		//changement de la case depart
		if (jeu.damier[curs.dep.lig][curs.dep.col] == CF)
		{
			//case fragile
			Pos caseRose = { curs.dep.lig, curs.dep.col };
			cvmSetColor(cvmColor::ROSE);
			for (int l = 0; l < 2; ++l)
			{
				gotoxy(caseRose.x, caseRose.y++);
				for (int c = 0; c < 4; ++c)
					cout << rose;
			};
			cvmResetColor();
		}

		else if (jeu.damier[curs.dep.lig][curs.dep.col] == CD)
		{
			//case dollar
			Pos caseDol = { curs.dep.lig, curs.dep.col };
			cvmSetColor(cvmColor::VERT);
			for (int l = 0; l < 2; ++l)
			{
				gotoxy(caseDol.x, caseDol.y++);
				for (int c = 0; c < 4; ++c)
					cout << vert;
			};
			cvmResetColor();
			
			gotoxy(0, 0); cout << setw(70) << left << "Decouvrez et amassez 15 cases $$$$";
			cout << "Points: " << jeu.ptsAccum++;
		}

		else if (jeu.damier[curs.dep.lig][curs.dep.col] == CO || jeu.damier[curs.dep.lig][curs.dep.col] == CS)
		{
			//case bleu
			Pos caseBleue = { curs.dep.lig, curs.dep.col };
			cvmSetColor(cvmColor::BLEU);
			for (int l = 0; l < 2; ++l)
			{
				gotoxy(caseBleue.x, caseBleue.y++);
				for (int c = 0; c < 4; ++c)
					cout << bleue;
			}
			cvmResetColor();
		}

		else if (jeu.damier[curs.dep.lig][curs.dep.col] == CV)
		{
			//case vide
			Pos caseNoir = { curs.dep.lig, curs.dep.col };
			cvmSetColor(cvmColor::NOIR);
			for (int l = 0; l < 2; ++l)
			{
				gotoxy(caseNoir.x, caseNoir.y++);
				for (int c = 0; c < 4; ++c)
					cout << noir;
			}
		}

		curs.dep.lig = curs.arr.lig;
		curs.dep.col = curs.arr.col;
	}
	while (jeu.ptsAccum < 16);

	arret = time(NULL); diff = arret - debut;

	clrscr();

	gotoxy(4, 3);
	cout << "Total des points :" << jeu.ptsAccum << "sur un objectif de 15";

	gotoxy(6, 3);
	cout << "Total des déplacements :" ;

	gotoxy(8, 3);
	cout << "Temps écoulé :" << diff << "secondes";
	//check surroundings

	_getch();
}