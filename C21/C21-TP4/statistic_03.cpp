#include "sondage.h"

double stat_03(Protection& pro, Repondant rep[])
{
	size_t i;
	double j = 0, k = 0;
	double moyenne;

	for (i = 0; i < nb_repondants; ++i)
	{
		if (rep[i].age > 29 && rep[i].age < 40)
		{
			j++;
			k += pro.r2[i];
		}
	}
	if (k != 0 || j != 0)
		moyenne = k / j;
	else
		moyenne = 0.0;

	return moyenne;
}