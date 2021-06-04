#include "sondage.h"

string stat_07(Infection inf[])
{
	size_t i;
	int j = 1, k = 0;
	int type = inf->r8;
	string repandu;

	for (i = 0; i < nb_repondants; ++i)
	{
		if (inf[i].r8 == inf[i - 1].r8)
			k++;
		else if (k > j)
		{
			j = k;
			type = inf[i - 1].r8;
		}
		else
			k = 1;
	}

	if (k > j)
	{
		j = k;
		type = inf[nb_repondants - 1].r8;
	}

	switch (type) {
		case 1: repandu = "Aucun"; break;
		case 2: repandu = "Savon à vasisselle"; break;
		case 3: repandu = "Purell"; break;
		case 4: repandu = "Eau de javel"; break;
		case 5: repandu = "Alcool à friction"; break;
	}

	return repandu;
}