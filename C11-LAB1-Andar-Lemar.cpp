//	Auteur:			Lemar Andar
//	Description:	Enleve les taxes
//	Input:			Prix apres taxes au QC
//	Output:			Prix avant taxes au QC
//	Version:		1.0



#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
	//contantes
	const double TVQ = 0.09975, TPS = 0.05;

	//variables
	double totalAvantTaxes, tps, tvq, totalApresTaxes;

	//input
	totalApresTaxes = 114.975;

	//traitement 
	totalAvantTaxes = totalApresTaxes / (1 + TPS + TVQ);
	tvq = totalAvantTaxes * TVQ;
	tps = totalAvantTaxes * TPS;
	

	//output
	cout << endl;
	cout << "montent apres taxes : " << totalApresTaxes << " $";
	cout << endl << endl;
	cout << "   tps : " << tps << " $";
	cout << endl << endl;
	cout << "   tvq : " << tvq << " $";
	cout << endl << endl;
	cout << "montent avant taxes : " << totalAvantTaxes << " $";
	cout << endl;


	_getch();
}