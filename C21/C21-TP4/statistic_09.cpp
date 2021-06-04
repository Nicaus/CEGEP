#include "sondage.h"

double stat_09(Protection& pro, Infection inf[], Repondant rep[])
{
	double moyenne;
	double j = 0, k = 0;
	size_t i;

	for (i = 0; i < nb_repondants; ++i)
	{
		if (inf[i].r9 == 1)
		{
			if (pro.r2[i] < 1 || inf[i].r7 == false)
			{
				j++;
				k += rep[i].scolarite;
			}
		}
	}

	if (j != 0 || k != 0)
		return moyenne = k / j;
	else
		return moyenne = 0.0;
}