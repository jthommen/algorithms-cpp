/*
###
Program 9.6: Heapsort
###

Description:
Using fixDown directly gives the classical heapsort algorithm.
The for loop constructs the heap, then the while loop exchanges
the largest element with the final element in the array and 
repairs the heap, continuing until the heap is empty.
The pointer pq to a[l-1] allows the code to treat the subarray
passed to it as an array with the first element at index 1, for
the array representation of the complete tree. 
Some programming environments may disallow this usage.

Properties:
- Heapsort uses fewer than 2N lg N comparisons to sort N elements.
- Heap-based selection allows the kth largest of N items to be found
in time proportional to N when k is small or close to N, and in
time proportional to N log N otherwise.

*/

#include<iostream>
#include<cstdlib>
#include "pq.cpp"

template<typename Item>
void heapsort(Item a[], int l, int r)
{
    int k, N = r-l+1;
    Item* pq = a+l-1;

    // constructing heap tree
    for(k = N/2; k >= 1; k--)
        fixDown(pq, k, N);

    // performing sort (sortdown)
    while(N > 1)
    {
        exch(pq[1], pq[N]);
        fixDown(pq, 1, --N);
    }
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
  heapsort(a, 0, N-1);

  // Printing sorted numbers
  for(i=0; i<N; i++) std::cout << a[i] << " ";
  std::cout << std::endl;

}