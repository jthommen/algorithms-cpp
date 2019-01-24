/*
###
Program 10.2: MSD radix sort (array)

Description:
Derived from key-indexed-counting sort by changing key references
to key-digit-references, and adding a loop at the end that does
recursive calls for each subfile of keys starting with the same
digit. For variable-length keys terminated by 0 digits (such as
C-style strings), omit the first if statement and the first recursive
call. The implementation uses an auxiliary array (aux) that is big
enough to hold a copy of the input.

Properties:
- Worst case for radix sorting is to examien all the bytes in all the keys.
- Sort with radix R on a file of size N requires at least 2N + 2R steps.
- If the radix is always less than the file size, the number of steps taken
is within a small constant factor of N logr N on the average (for keys
comprising random bytes), and within a small constant factor of the number
of bytes in the keys in the worst case.

*/
const int bitsword = 32;
const int bitsbyte = 8;
const int bytesword = bitsword/bitsbyte;
const int R = 1 << bitsbyte;

#define bin(A) l+count[A]

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
void radixMSD(Item a[], int l, int r, int d)
{
    int i, j, count[R+1];

    static Item aux[maxN];

    if(d > bytesword) return;

    if(r-l <= M)
    { insertion(a, l, r); return; }

    for(j = 0; j < R; j++)
        count[j] = 0;

    for(i = l; i <= r; i++)
        count[digit(a[i], d) + 1]++;

    for(j = 1; j < R; j++)
        count[j] += count[j-1];

    for(i = l; i <= r; i++)
        aux[count[digit(a[i], d)]++] = a[i];

    for(i = l; i <= r; i++)
        ai[i] = aux[i-l];

    radixMSD(a, l, bin(0)-1, d+1);

    for(j = 0; j < R-1; j++)
        radixMSD(a, bin(j), bin(j+1)-1, d+1);
}
