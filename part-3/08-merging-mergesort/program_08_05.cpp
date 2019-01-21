/*
###
Program 8.5: Bottm-up Mergesert (Array)
###

Description:
In-place merge - Merging without sentinels by copying the second array
into aux in reverse order back to back with the first (putting 
aux in bitonic order). The first for loop moves the first array
and leaves i pointing to l, ready to begin the merge. The second
for loop moves the second array, and leaves j pointing to r. Then,
in the merge (the third for loop), the largest element serves as 
the sentinel in whichever array it is. The inner loop of this 
program isshort (move to aux, compare, move back to a, increment
i or j, increment and test k).

Top-down mergesort - Consists of a sequence of passes over the whole
file doing m-by-m merges, doubling m on each pass. The final subfile
is of size m only if the file size is an even multiple of m, so the
final merge is an m-by-x merge, for some x less than or equal to m.

Properties:
- Requires about N lg N comparisons to sort any file of N elements.
- Uses extra space proportional to N.
- Stable if the underlying merge is stable
- The resource requirements of mergesort are insensitive to the 
initial order of its input.
- All the merges in each pass of a bottom-up mergesort involve file
sizes that are a power of 2, except possibly the final file size.
- The number of passes in a bottom-up mergesort of N elements is precisely
the number of bits in a binary representation of N (ignoring leading 0 bits).

*/

#include<iostream>
#include<cstdlib>

static const int maxN = 100;

inline int min(int A, int B)
{
    return (A < B) ? A : B;
}

template<typename Item>
void merge(Item a[], int l, int m, int r)
{
    int i, j;
    Item aux[maxN];

    // Copy the sequences l to m and m to r in a bitonic sequence
    for(i = m+1; i > l; i--) aux[i-1] = a[i-1];
    for(j = m; j < r; j++) aux[r+m-j] = a[j+1];

    // Merge the two sequences
    for(int k = l; k <= r; k++)
        if(aux[j] < aux[i])
            a[k] = aux[j--]; else a[k] = aux[i++];
}

template<typename Item>
void mergesort(Item a[], int l, int r)
{
    for(int m = 1; m <= r-l; m = m+m)
        for(int i = l; i <= r-m; i += m+m)
            merge(a, i, i+m-1, min(i+m+m-1, r));
}

int main(int argc, char* argv[])
{
  // Getting command line arguments
  // N = amount of numbers to sort
  // sw = generate numbers randomly or take from std input
  int i, N = atoi(argv[1]), sw = atoi(argv[2]);
  int* a = new int[N];
  
  // Random number generation or command line input
  if(sw)
    for(i=0; i<N; i++)
      a[i] = 1000*(1.0*rand()/RAND_MAX);
  else
  {
    N = 0; while(std::cin >> a[N]) N++;
  }

  // Sorting numbers
  mergesort(a, 0, N-1);

  // Printing sorted numbers
  for(i=0; i<N; i++) std::cout << a[i] << " ";
  std::cout << std::endl;

}