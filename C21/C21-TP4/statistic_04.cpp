#include "sondage.h"

double stat_04(Protection& pro, Repondant rep[])
{
	size_t i;
	double moyenne, j = 0, k = 0;

	for (i = 0; i < nb_repondants; ++i)
	{
		if (pro.r5[i] == 'O' || pro.r6[i] == 'O')
		{
			j++;
			k += rep[i].age;
		}
	}

	if (j != 0 || k != 0)
		return moyenne = k / j;
	else
		return moyenne = 0.0;
}