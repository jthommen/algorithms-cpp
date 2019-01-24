/*
###
Program 10.3: Three-way radix quicksort (array)

Description:
This MSD radix sort is essentially the same code as quicksort
with three way partitioning, but with the following changes:
1. Key references become key-byte-references
2. The current byte is added as a parameter to the recursive routine
3. The recursive calls for the middle subfile move to the next byte
We avoid moving past the ends of strings by checking wehether the
partitioning value is 0 before recursive calls that move to the next
byte. When the partitioning value is 0, the left subfile is empty, 
the middle subfile corresponds to the keys that the program has found
to be equal, and the right subfile corresponds to the longer strings 
that need to be processed further.

Properties:
- Worst case for radix sorting is to examien all the bytes in all the keys.
- Uses 2N ln N byte comparisons, on the average, to sort N (arbitrarily long)
keys.

*/
const int bitsword = 32;
const int bitsbyte = 8;
const int bytesword = bitsword/bitsbyte;
const int R = 1 << bitsbyte;

#define ch(A) digit(A, d);

// Extracting the Bth byte of a binary word A
inline int digit(long A, long B)
{ return (A >> bitsbyte*(bytesword-B-1)) & (R-1); }

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
void insertion(Item a[], int l, int r)
{
  int i;

  // put the smallest element in the array's first position
  for(i = r; i > l; i--) compexch(a[i-l], a[i]);
  
  //
  for(i = l+2; i <= r; i++)
  {
    int j = i; Item v = a[i];

    // terminate loop when element is in position
    while (v < a[j-1])
    {
      // single assignment in the inner loop
      // (no exchange)
      a[j] = a[j-1];
      j--;
    }
    a[j] = v;
  }
}

template<typename Item>
void quicksortX(Item a[], int l, int r, int d)
{
    int i, j, k, p, q;
    int v;
    
    if(r-l <= M)
    { insertion(a, l, r); return; }

    v = ch(a[r]);
    i = l-1;
    j = r;
    p = l-1;
    q = r;

    while(i < j)
    {
        while(ch(a[++i]) < v);
        
        while(v < ch(a[--j])) if(j == l) break;
        
        if(i > j) break;

        exch(a[i], a[j]);

        if(ch(a[i]) == v)
            { p++; exch(a[p], a[i]); }

        if(v==ch(a[j]))
            { q--; exch(a[j], a[q]); }
    }

    if(p == q)
    { if(v != '\0') quicksortX(a, l, r, d+1); return; }

    if(ch(a[i]) < v) i++;

    for(k = l; k <= p; k++, j--)
        exch(a[k], a[j]);
    
    for(k = r; k >= q; k--, i++) exch(a[k], a[i]);

    quicksortX(a, l, j, d);

    if((i == r) && (ch(a[i]) == v)) i++;

    if(v != '\0') quicksortX(a, j+1, i-1, d+1);

    quicksortX(a, i, r, d);
}
