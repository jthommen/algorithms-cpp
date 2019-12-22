/*
###
Program 8.2 & 8.3: Top-Down Mergesort (Array)
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

Top-down mergesort - The basic mergesort implementation is a proto-
typical divide-and-conquer recursive program. It sorts the array
a[l], ..., a[r] by dividing it into two parts a[l], ..., a[m] and
a[m+1], ..., a[r], sorting them independently (via recursive calls),
and merging the resulting ordered subfiles to produce the final ordered
result. The merge function may need to use an auxiliary array big
enough to hold a copy of the input, but it is convenient to consider
the abstract operation as an inplace merge.

Properties:
- Requires about N lg N comparisons to sort any file of N elements.
- Uses extra space proportional to N.
- Stable if the underlying merge is stable
- The resource requirements of mergesort are insensitive to the 
initial order of its input.


*/

#include<iostream>
#include<cstdlib>

static const int maxN = 100;

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
    if(r <= l) return;
    int m = (r+l)/2;
    mergesort(a, l, m);
    mergesort(a, m+1, r);
    merge(a, l, m, r);
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