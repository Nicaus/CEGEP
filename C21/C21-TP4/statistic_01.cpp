#include "sondage.h"

int stat_01(bool r1[])
{
	size_t i; int j = 0;

	for (i = 0; i < nb_repondants; ++i)
		if (r1[i] == true)
			j++;

	return j;
}