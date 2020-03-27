#ifndef MERGESORT_HH
#define MERGESORT_HH


#include <iostream>


template<typename TYPE>
void merge(TYPE *tab, int s, int m, int e)
{
	int  i, j, k , nl, nr;
	nl = m-s+1;
	nr = e - m;
	TYPE *ltab = new TYPE[nl];
	TYPE *rtab = new TYPE[nr];

	for (i=0; i < nl; i++)
	{
		ltab[i] = tab[s+i];
	}
	for (j=0; j < nr; j++)
	{
		rtab[j] = tab[m+1+j];
	}

	i = 0;
	j = 0;
	k = s;

	while(i < nl && j < nr)
	{
		if (ltab[i] <= rtab[j])
		{
			tab[k] = ltab[i];
			i++;
		} else {
			tab[k] = rtab[j];
			j++;
		}
		k++;
	}

	while (i < nl)
	{
		tab[k] = ltab[i];
		i++;
		k++;
	}
	while (j < nr)
	{
		tab[k] = rtab[j];
		j++;
		k++;
	}
	delete [] ltab;
	delete [] rtab;
}



template<typename TYPE>
void mergesort(TYPE *tab,int s, int e)
{
	if (s < e)
	{
		int m = (s+e)/2;
		mergesort(tab, s, m);
		mergesort(tab,m+1, e);
		merge(tab, s, m, e);
	}

}



#endif


