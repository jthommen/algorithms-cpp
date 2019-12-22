/*
###
Program 11.3: Batcher's odd-even merge (array, nonrecursive version)

Description:
This implementation of Batcher's odd-even merge (which assumes that the
file size N is a power of 2), is compact but mysterious. We can understand 
how it accomplishes the merge by examining how it corresponds to the 
recursive version. It accomplishes the merge in lg N passes consisting of
uniform and independent compare-exchange instructions.


Properties:
- Batcher's odd-even sorting networks have about N(lg N)^2/4 comparators
and can run in (lg N)^2/2 parallel steps.

*/

// Switch items
template<typename Item>
void exch(Item& A, Item& B)
{
  Item t = A; A = B; B = t;
}

// Switch items after comparison
template<typename Item>
void compexch(Item& A, Item& B)
{
  if(B < A) exch(A, B);
}

template<typename Item>
void merge(Item a[], int l, int m, int r)
{
    int N = r-1+1; // assuming N/2 is m-l+1
    for(int k = N/2; k > 0; k /= 2)
        for(int j = k % (N/2); j+k < N; j += k+k)
            for(int i = 0; i < k; i++)
                compexch(a[l+j+i], a[l+j+i+k]);
}
