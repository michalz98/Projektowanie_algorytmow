#ifndef INTROSORT_HH
#define INTROSORT_HH

#include <cmath>
#include "quicksort.hh"
#include "heapsort.hh"

template<typename TYPE>
void insertion(TYPE *tab, int s, int e)
{
	int i, j, h, val;

	for(i = s; i < e; i++)
	{
		val = tab[i+1];
		j = i;
		while(j >= s)
		{
			if (tab[j] > val)
			{
				h = tab[j+1];
				tab[j+1] = tab[j];
				tab[j] = h;
			}
			j--;
		}
	}
}


template<typename TYPE>
void introsort(TYPE *tab, int s, int e)
{
	int size = e-s;
	int depth = 2*log(size);

	if (size < 16)
	{
		insertion<TYPE>(tab, s, e);
	}
	else if (depth == 0)
	{
		heapsort<TYPE>(tab, size);
	}
	else
	{
		quicksort<TYPE>(tab, s, e);
	}

}


#endif
