/*
###
Program 11.4: Batcher's odd-even sort (array, nonrecursive version)

Description:
This implementation of Batcher's odd-even sort corresponds directly
to the network representation. It divides into phases, indexed by the
variable p. The last phase, when p is N, is Batcher's odd-even merge.
The next-to-last phase, when p is N/2, is the odd-even merge with the 
first stage and all comparators that cross N/2 eliminated; the
third-to-last phase, when p is N/4, is the odd-even merge with the first
two stages and all comparators that cross any multiple of N/4 eliminated
and so forth.


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
void merge(Item a[], int l, int r)
{
    int N = r-1+1; // assuming N/2 is m-l+1
    for(int p = 1; p < N; p += p)
        for(int k = p; k > 0; k /= 2)
            for(int j = k%p; j+k < N; j += (k+k))
                for(int i = 0; i < N-j-k; i++)
                    compexch(a[l+j+i], a[l+j+i+k]);
}
