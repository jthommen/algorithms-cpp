/*
###
Program 6.2: Selection Sort
###

Description:
For each i from l to r-1, exchange a[i] with the minimum
element in a[i], ..., a[r]. As the index i travels from
left to right, the elements to its left are in their final
position in the array (and will not be touched again), so
the array is fully sorted when i reaches the right end.

Properties:
- Selection sort uses N^2/2 comparisons and N exchanges.
- In the usual case, the runtime is input independent.
- Runs in linear time for files with large items and small keys.

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
void selection(Item a[], int l, int r)
{
  for(int i=l; i<r; i++)
  {
    int min = i;
    for(int j=i+1; j<=r; j++)
      if(a[j] < a[min]) min = j;
      exch(a[i], a[min]);
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
  selection(a, 0, N-1);

  // Printing sorted numbers
  for(i=0; i<N; i++) std::cout << a[i] << " ";
  std::cout << std::endl;
}