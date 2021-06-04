#include "sondage.h"

double stat_05(Protection& pro, Repondant rep[])
{
	size_t i;
	double pourcentage;
	double k = 0, j = 0;

	for (i = 0; i < nb_repondants; ++i)
	{
		if (rep[i].ville == "Vaudreuil")
			k++;
		if (rep[i].ville == "Vaudreuil" && pro.r2[i] > 1)
			j++;
	}

	if (j != 0 || k != 0)
		return pourcentage = ((j / k) * 100);
	else
		return pourcentage = 0.0;
}