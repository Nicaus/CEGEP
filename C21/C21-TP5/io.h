#pragma once
#include <string>
#include "db.h"

using namespace std;

void io_titre();
double io_arrondir(double valeur);

string& io_textCleaner(string& texte);
void io_clean();
void io_copyStringTo(const string& s, const unsigned int size, char to[]);
void io_lireString(const int size, char to[]);

string io_dateHeure(time_t t);
void io_texteCouleur(cvmColor c, string message);