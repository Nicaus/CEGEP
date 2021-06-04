#include <iostream>
#include <conio.h>
#include <iomanip>
#include "statistic_01.h"
#include "statistic_02.h"
#include "statistic_03.h"
#include "statistic_04.h"
#include "statistic_05.h"
#include "statistic_06.h"
#include "statistic_07.h"
#include "statistic_08.h"
#include "statistic_09.h"
#include "statistic_10.h"

using namespace std;

int main()
{
	SetConsoleCP(1252);
	SetConsoleOutputCP(1252);

	//Pour recevoir les donn�es du sondage
	bool r1[REPONDANTS_MAX] = {};				// pour la  r�ponse  1
	Protection pro = {};						// pour les r�ponses 2-3-4-5-6
	Infection inf[REPONDANTS_MAX] = {};			// pour les r�ponses 7-8-9-10
	Repondant rep[REPONDANTS_MAX] = {};			// pour les r�ponses ville, age, scolarit�

	// A - Charger les donn�es du sondage
	string name = "C21-TP3-Sondage.txt";
	nb_repondants = lireLesDonn�esDuSondage(r1, pro, inf, rep, name);

	//affichage questions
	cout << "R�sultats du sondage: ( " << nb_repondants << " r�pondants )" << "\n\n";
	cout << "Statistiques";
	cout << "\n\n";
	cout << "01) Combien de personnes toussent souvent ?" << endl;
	cout << "02) Combien de personnes veulent un masque dans leur auto ?" << endl;
	cout << "03) Combien de masques, en moyenne, ont les gens qui sont dans la trentaine ?" << endl;
	cout << "04) Quel est l'�ge moyen des gens qui se serviraient d'un masque pour d�corer ou pour dormir?" << endl;
	cout << "05) Quel pourcentage des gens de Vaudreuil poss�dent plus d'un masque ?" << endl;
	cout << "06) Quel pourcentage de la population utilise du d�sinfectant  ?" << endl;
	cout << "07) Quel est le type de desinfectant le plus r�pandu ?" << endl;
	cout << "08) Combien de gens non test� et n'utilisent pas de d�sinfectant ont d�j� emprunt� un masque ?" << endl;
	cout << "09) Combien d'ann�es de scolarit�, en moyenne, ont les gens infect�s de Montr�al sans masque ou sans d�sinfectant ?" << endl;
	cout << "10) Quelle est la ville ayant fait subir le plus grand nombre de test ?" << endl;

	//affichage resultat
	cout << "\n\n";
	cout << "R�sultats" << "\n\n";
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