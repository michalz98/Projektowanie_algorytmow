#ifndef HEAPSORT_HH
#define HEAPSORT_HH

template<typename TYPE>
void makeheap(TYPE *tab, int n, int i)
{
	int top, l, r, h;
	top = i;
	l = 2*i+1;
	r = 2*i+2;

	if (l < n && tab[l] > tab[top])
	{
		top = l;
	}
	if (r < n && tab[r] > tab[top])
	{
		top = r;
	}
	if (top != i)
	{
		h = tab[i];
		tab[i] = tab[top];
		tab[top] = h;

		makeheap<TYPE>(tab, n, top);
	}
}

template<typename TYPE>
void heapsort(TYPE *tab, int n)
{
	int i, h;
	for(i = n/2-1; i >= 0; i--)
	{
		makeheap<TYPE>(tab, n, i);
	}
	for(i = n-1; i >= 0; i--)
	{
		h = tab[0];
		tab[0] = tab[i];
		tab[i] = h;

		makeheap<TYPE>(tab, i, 0);
	}
}


#endif
