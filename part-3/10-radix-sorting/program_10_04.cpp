/*
###
Program 10.4. LSD radix sort (array)

Description:
Implementing key-indexed counting on the bytes in the words,
moving right to left. The key-indexed counting implementation
must be stable. If R is 2 (and therefoer bytesword and bitsword
are the same), this program is straight radix sort - a right-to-left
bit-by-bit radix sort.


Properties:
- Running time for sorting N records with w-byte keys is proportional
to N w, beacuse the algorithm makes w passes over N keys.
- For long keys and short bytes, running time comparable to N lg N
- Worst case for radix sorting is to examien all the bytes in all the keys.
- Can sort N records with w-bit keys in w/lg R passes, using extra space for
R counters (and a buffer for rearranging the file).

*/
const int bitsword = 32;
const int bitsbyte = 8;
const int bytesword = bitsword/bitsbyte;
const int R = 1 << bitsbyte;

// Extracting the Bth byte of a binary word A
inline int digit(long A, long B)
{ return (A >> bitsbyte*(bytesword-B-1)) & (R-1); }


template<typename Item>
void radixLSD(Item a[], int l, int r)
{
    static Item aux[maxN];

    for(int d = bytesword -1; d >= 0; d--)
    {
        int i, j, count[R+1];

        for(j = 0; j < R; j++)
            count[j] = 0;

        for(i = l; i <= r; i++)
            count[digit(a[i], d) + 1]++;
        
        for(j = 1; j < R; j++)
            count[j] += count[j-1];

        for(i = l; i <= r; i++)
            aux[count[digit(a[i], d)]++] = a[i];
        
        for(i = l; i <= r; i++)
            a[i] = aux[i-l];
    }
}
