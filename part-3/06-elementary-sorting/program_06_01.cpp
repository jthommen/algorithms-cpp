/*
###
Program 6.1: Example of array insertion sort with driver program
###

Description:
This program illustrates our conventions for implementing basic array
sorts. The main function is a driver that initializes an array of integers
(either with random values or from standard input), calls a sort function
to sort that array, then prints out the ordered result.
  Templates allow the implementation to be used to sort items of any data
type for which comparison and assignment are defined. The sort function
here is a version of insertion sort. It uses a template function that
compares two items and exchanges them if necessary to make the second not <
than the first.
  We can change the driver to sort any type of data for which operator< is
defined without modifying sort at all.

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
void sort(Item a[], int l, int r)
{
  for(int i=l+1; i<=r; i++)
    for(int j=i; j>1; j--)
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
  sort(a, 0, N-1);

  // Printing sorted numbers
  for(i=0; i<N; i++) std::cout << a[i] << " ";
  std::cout << std::endl;
}