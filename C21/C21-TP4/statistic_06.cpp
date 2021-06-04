#include "sondage.h"

double stat_06(Infection inf[])
{
	size_t i;
	double pourcentage = 0.0;
	double j = 0;

	for (i = 0; i < nb_repondants; ++i)
	{
		if (inf[i].r7 == true)
			j++;
	}

	if (j != 0)
		return pourcentage = ((j / nb_repondants) * 100);
	else
		return pourcentage = 0.0;
}