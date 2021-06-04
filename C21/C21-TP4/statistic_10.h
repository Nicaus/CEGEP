#pragma once 

string stat_10(Infection inf[], Repondant rep[]);

struct Data
{
	string liste;
	int nbTest;
};

struct Item
{
	Data data;
	Item* next;
};

struct List
{
	Item* deb;
	Item* fin;
	size_t size;
};

