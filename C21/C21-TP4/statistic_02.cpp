#include "sondage.h"
#include "statistic_02.h"

int stat_02(Protection& pro)
{
	size_t i; int j = 0;

	for (i = 0; i < nb_repondants; ++i)
		if (pro.r3[i] == 'O')
			j++;

	return j;
}