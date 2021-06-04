#pragma once
#pragma warning ( disable : 6031 )
#include <string>
#include <Windows.h>

using namespace std;

const size_t REPONDANTS_MAX = 500;

struct Protection
{
	int  r2[REPONDANTS_MAX];
	char r3[REPONDANTS_MAX];
	char r4[REPONDANTS_MAX];
	char r5[REPONDANTS_MAX];
	char r6[REPONDANTS_MAX];
};

struct Infection
{
	bool r7;
	int	r8, r9, r10;
};

struct Repondant
{
	string ville;
	int age{};
	int scolarite{};
};

extern size_t nb_repondants;
size_t lireLesDonnéesDuSondage(bool r1[], Protection& pro, Infection inf[], Repondant rep[], string& name);
