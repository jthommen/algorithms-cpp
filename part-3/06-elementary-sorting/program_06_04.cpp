/*
###
Program 6.4: Bubble Sort
###

Description:
For each i from l to r-1, the inner (j) loop puts the minimum
element among the elements in a[i], ..., a[r] into a[i] by passing
from right to left through the elements, compare-exchanging 
successive elements.
The smallest one moves on all such comprisons, so it 'bubbles' to
the beginning. As in selection sort, as the index i travles from
left to right through the file, the elements to its left are in their
final position in the array.

Properties:
- Bubble sort uses about N^2/2 comparisons and N^2/2 exchanges
on the average and in the worst case.
- Bubble sort is considered input independent.
- Uses a lienar number of comparisons and exchanges for files with
at most a constant number of inversions corresponding to each element.

*/

#include<iostream>
#include<cstdlib>

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

// Iterate through numbers
// Compare and sort them
// Double loop: for every item compare with every item
template<typename Item>
void bubble(Item a[], int l, int r)
{
  for(int i=l; i<r; i++)
    for(int j=r; j>i; j--)
      compexch(a[j-1], a[j]);
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
  bubble(a, 0, N-1);

  // Printing sorted numbers
  for(i=0; i<N; i++) std::cout << a[i] << " ";
  std::cout << std::endl;

}