/*
###
Program 10.1: Binary quicksort
###

Description:
This program paritions a file on the leading  bits of the keys, and
then sorts the subfiles recursively. The variable d keeps track of the
bit being examined, starting at 0 (leftmost). The partitioning stops 
with j equal to i, and all elements to the right of a[i] having 1 bits
in the dth position. The element a[i] itself will have 1 bit unless all
keys in the file have a 0 in position d. An extra test just after the
partitioning loop covers this case.

Properties:
- Worst case for radix sorting is to examien all the bytes in all the keys.
- Examines about N lg N bits, on average, when sorting keys composed
of random bits.

*/

const int bitsword = 32;
const int bitsbyte = 8;
const int bytesword = bitsword/bitsbyte;
const int R = 1 << bitsbyte;

// Extracting the Bth byte of a binary word A
inline int digit(long A, long B)
{ return (A >> bitsbyte*(bytesword-B-1)) & (R-1); }

template<typename Item>
void exch(Item A, Item B)
{
    Item t = A; A = B; B = t;
}

template<typename Item>
void quicksortB(Item a[], int l, int r, int d)
{
    int i = l, j = r;
    if(r <= l || d > bitsword) return;
    while(j != i)
    {
        while(digit(a[i], d) == 0 && (i < j)) i++;
        while(digit(a[j], d) == 0 && (j > i)) j--;
        exch(a[i], a[j]);
    }
    if(digit(a[r], d) == 0) j++;
    quicksortB(a, l, j-1, d+1);
    quicksortB(a, j, r, d+1);
}

template<typename Item>
void sort(Item a[], int l, int r)
{
    quicksortB(a, l, r, 0);
}

