#ifndef QUICKSORT_HH
#define QUICKSORT_HH

#include <iostream>



template <typename TYPE>
int part(TYPE *tab,int s, int e)
{
	TYPE h;
	TYPE pivot;

	int rnd = s + std::rand() % (e-s);
	h = tab[rnd];
	tab[rnd] = tab[s];
	tab[s] = h;

	pivot =tab[e];
	int i = (s - 1);
	for(int j = s; j < e; j++)
	{
		if (tab[j] <= pivot)
		{
			i++;
			h = tab[j];
			tab[j] = tab[i];
			tab[i] = h;
		}
	}
	h = tab[i+1];
	tab[i+1] = tab[e];
	tab[e] = h;
	return (i+1);

}


template <typename TYPE>
void quicksort(TYPE *tab, int s, int e)
{
	int p;
	if (s < e)
	{
		p = part(tab, s, e);
		quicksort(tab, s, p-1);
		quicksort(tab, p+1, e);

	}
}


#endif
