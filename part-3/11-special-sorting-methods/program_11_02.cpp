/*
###
Program 11.1 & 11.2: Batcher's odd-even merge (array, recursive version)

Description:
shuffle/unshuffle: The shuffle function rearranges a subarray a[l], ...,
a[r] by splitting that subarray in half, then alternating elements from each
half: Elements in the first half go in the even-numbered positions in the result,
and elements in the second half go in the odd-numbered positions in the result.
The unshuffle function does the opposite: Elements in the even-numbered positions
go in the first half of the result and elements in the odd-numbered positions
go in the second half of the result

odd-even merge: Recursive program implementing an abstract inplace merge, using
the shuffle and unshuffle operations. Although they are not essential.
Primary interest here is that this implementation provides a compact
description of Batcher's algorithm, when the file size is a power of 2.


Properties:


*/

template<typename Item>
void shuffle(Item a[], int l, int r)
{
    int i, j, m = (l+r)/2;
    static Item aux[maxN];

    for(i = l, j = 0; i <= r; i += 2; j++)
    {
        aux[i] = a[l+j];
        aux[i+1] = a[m+1+j];
    }

    for(i = l; i <= r; i++)
        a[i] = aux[i];
}

template<typename Item>
void unshuffle(Item a[], int l, int r)
{
    int i, j, m = (l+r)/2;
    static Item aux[maxN];

    for(i = l, j = 0; i <= r; i += 2, j++)
    {
        aux[l+j] = a[i];
        aux[m+1+j] = a[i+1];
    }

    for(i = l; i <= r; i++)
        a[i] = aux[i];
}

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
    if(r == l+1) compexch(a[l], a[r]);
    if(r < l+2) return;
    unshuffle(a, l, r);
    merge(a, l, (1+m)/2, m);
    merge(a, m+1, (m+1+r)/2, r);
    shuffle(a, l, r);
    for(int i = l+1; i < r; i += 2)
        compexch(a[i], a[i+1]);
}
