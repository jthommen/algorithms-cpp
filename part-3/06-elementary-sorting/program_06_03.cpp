/*
###
Program 6.3: Adaptive Array insertion sort
###

Description:
Improvement of the insertion sort in program 6.1,
because:
1. it first puts the smallest element in the array 
into the first position, so that that element can
serve as a sentinel.
2. it does a single assignment, rather than an exchange,
in the inner loop.
3. it terminates the inner loop when the element being
inserted is in position.

For each i, it sorts the elements a[l], ..., a[i] by
moving one position to the right elements in the sorted
list a[l], ..., a[i-l] that are larger than a[i], then
putting a[i] into its proper position.

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
void insertion(Item a[], int l, int r)
{
  int i;
  for(i = r; i > l; i--) compexch(a[i-l], a[i]);
  for(i = l+2; i <= r; i++)
  {
    int j = i; Item v = a[i];
    while (v < a[j-1])
    {
      a[j] = a[j-1];
      j--;
    }
    a[j] = v;
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
  insertion(a, 0, N-1);

  // Printing sorted numbers
  for(i=0; i<N; i++) std::cout << a[i] << " ";
  std::cout << std::endl;
}