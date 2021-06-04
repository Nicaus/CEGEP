#include <iomanip>
#include <iostream>
#include "console(v1.9).h"
#include <string>
#include <conio.h>
#include <ctime>


using namespace std;

int main()
{
	//setw
	int a = 8, b = 13, c = 12, d = 4, f = 14, g = 9, i = 7;
	//variables
	int freq1, freq2, freq3, freq4, freq5, freq6, face, lancer, frequence = 1, nbtest, nb = 0, freqTotal;
	double dis1 = 0, dis2 = 0, dis3 = 0, dis4 = 0, dis5 = 0, dis6 = 0, disTotal = 0;
	srand(int(time(0)));
	cout << fixed << setprecision(2);

	//1 lancer
	for (nbtest = 1; nbtest < 8; ++nbtest) {
		cout << endl << "Exp\202rience al\202atoire avec " << frequence << " lancer"
			<< "\n\n\n" << left
			<< setw(a) << "Face" << setw(b) << "Fr\202quence" << setw(c) << "Distribution" << endl;
		freq1 = 0, freq2 = 0, freq3 = 0, freq4 = 0, freq5 = 0, freq6 = 0;
		for (lancer = 0; lancer < frequence; ++lancer) {
			face = rand() % 6 + 1;
			if (face == 1)
				freq1 += 1;
			else if (face == 2)
				freq2 += 1;
			else if (face == 3)
				freq3 += 1;
			else if (face == 4)
				freq4 += 1;
			else if (face == 5)
				freq5 += 1;
			else if (face == 6)
				freq6 += 1;
		}
		frequence *= 10;
		freqTotal = freq1 + freq2 + freq3 + freq4 + freq5 + freq6;
		disTotal = dis1 + dis2 + dis3 + dis4 + dis5 + dis6;
		dis1 = freq1 * 100.00 / freqTotal;
		dis2 = freq2 * 100.00 / freqTotal;
		dis3 = freq3 * 100.00 / freqTotal;
		dis4 = freq4 * 100.00 / freqTotal;
		dis5 = freq5 * 100.00 / freqTotal;
		dis6 = freq6 * 100.00 / freqTotal;
		
		cout << endl << right << fixed << setprecision(2)
			<< setw(d) << "1" << setw(b) << freq1 << setw(f) << dis1 << " %" << endl
			<< setw(d) << "2" << setw(b) << freq2 << setw(f) << dis2 << " %" << endl
			<< setw(d) << "3" << setw(b) << freq3 << setw(f) << dis3 << " %" << endl
			<< setw(d) << "4" << setw(b) << freq4 << setw(f) << dis4 << " %" << endl
			<< setw(d) << "5" << setw(b) << freq5 << setw(f) << dis5 << " %" << endl
			<< setw(d) << "6" << setw(b) << freq6 << setw(f) << dis6 << " %" << endl
			<< setw(g) << " " << setfill('-') << setw(g) << " " << setfill(' ')
			<< setw(i) << " " << setfill('-') << setw(g) << " " << setfill(' ') << "\n"
			<< setw(d) << " " << setw(b) << freqTotal << setw(f) << disTotal << " %" << endl
			<< "\n\n";
		nb += freqTotal;
		cout << "Statistiques cumulatives apr\212s " << nbtest << " exp\202riences" << "\n\n"
			<< " ==> " << nb << " lancers" << "\n\n\n\n\n\n";
	
		if (nbtest < 7)
			cout << "Appuyez sur une touche pour effectuer l'\202xperience suivante ...";
		else
			cout << "A U  R E V O I R  !";
		_getch();
		clrscr();
	}
		_getch();
}