#include "sondage.h"

int stat_08(Protection& pro, Infection inf[])
{
	size_t i;
	int compte = 0;

	for (i = 0; i < nb_repondants; ++i)
	{
		if (pro.r4[i] == 'N' && inf[i].r7 == false && inf[i].r10 > 1)
			compte++;
	}
	if (compte != 0)
		return compte;
	else
		return compte = 0;
}