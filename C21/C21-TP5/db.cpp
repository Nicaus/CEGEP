#include <string>
#include <fstream>
#include "db.h"

/* creer et lie le fichier db*/

using namespace std;

const string fichier = "repartiteur.db";
static fstream f;

void db_create()
{
	if (f.is_open())
		f.close();
	f.open(fichier, ios::in | ios::out | ios::binary | ios::trunc);
}

void db_open()
{
	f.open(fichier, ios::in | ios::out | ios::binary);
	if (!f.is_open())
		db_create();
}

void db_close() 
{ 
	f.close(); 
}

int db_size()
{
	f.seekg(0, ios::end);
	return (int)f.tellg() / sizeof(Participant);
}

void db_read(size_t no, Participant* p)
{
	f.seekg((no - 1) * size_t(sizeof(Participant)), ios::beg);
	f.read((char*)p, sizeof(Participant));
}

void db_write(size_t no, Participant* p){
	f.seekg((no - 1) * size_t(sizeof(Participant)), ios::beg);
	f.write((char*)p, sizeof(Participant));
}