#include "sondage.h"
#include "statistic_10.h"

string stat_10(Infection inf[], Repondant rep[])
{
	List list = {};
	Data info = {};
	Item* ville = new Item{ info, nullptr };

	string rependu;

	for (size_t i = 0; i < nb_repondants; ++i)
	{
		info = { rep[i].ville, inf[i].r10 };
		Item* ville = new Item{ info, nullptr };

		if (list.fin)
			list.fin->next = ville;
		else
			list.deb = ville;

		list.fin = ville;
		list.size++;
	}

	//compte les test par ville
	Item* exist = list.deb;
	for (size_t j = 0; j < nb_repondants; ++j)
	{
		info = { rep[j].ville, inf[j].r10 };
		int nbtestparville = 0;
		while (exist)
		{
			if (rep[j].ville == exist->data.liste)
				nbtestparville += exist->data.nbTest;
			exist = exist->next;
		}
		exist = list.deb;
		exist->data.nbTest = nbtestparville;
		j++;
	}

	rependu = exist->data.liste;

	return rependu;
}