/*
###
Program 7.4: Improved Recursive Quicksort (Array)
###

Description:
Quicksort - Choosing the median of the first, middle and final elements as the
partitioning element and cutting off the recursion for small subfiles can
significantgly improve the performance of quicksort. This implementation partitions
on the median of the first, middle and final elements in the array (otherwise leaving
these elements out of the partitioning process). Files of size 11 or smaller are ignored
during paritioning; then, insertion sort is used to finish the sort in a hybrid approach.

Partition - The variable v holds the value of the partitioning element a[r], and i
and j are the left and right scan pointers, respectively. The partitioning loop
increments i and decrements j, while maintaining the invariant property that no
elements to the left of i are greather than v and no elements to the right of j
are smaller than v. Once the pointers meet, we complete the partitioning by
exchanging a[i] and a[r], which puts v into a[i], with no larger elements
to v's right and no smaller elements to its left.
The partitioning loop is implemented as an infinte loop, with a break when
the pointers cross. The test j == l protects aginst the case that the
partitioning element is the smallest element in the file.

Properties:
- Uses about N^2/2 comparisons in the worst case.
- Uses about 2NlnN comparisons on the average.



*/

#include<iostream>
#include<cstdlib>

static const int M = 10;

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
int partition(Item a[], int l, int r)
{
    // Left and right scan pointers
    int i = l-1, j=r;

    // Value of partitioning element
    Item v = a[r];
    
    // Infinity loop
    for(;;)
    {
        // precrement before comparison
        // Check if part of array is smaller than value of partitioning elem
        while(a[++i] < v);

        // protection against r == smallest elem in the file
        while(v < a[--j]) if(j == l) break;

        // Break if pointers cross
        if(i >= j) break;

        // Otherwise exchange left and right elem
        exch(a[i], a[j]);
    }
    // Put partitioning element where pointers cross
    exch(a[i], a[r]);
    return i;
}

// Iterate through numbers
// Compare and sort them
// Double loop: for every item compare with every item
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
void quicksort(Item a[], int l, int r)
{
    if(r-l <= M) return;
    exch(a[(l+r)/2], a[r-1]);
    compexch(a[l], a[r-1]);
    compexch(a[l], a[r]);
    compexch(a[r-1], a[r]);

    int i = partition(a, l+1, r-1);
    quicksort(a, l, i-1);
    quicksort(a, i+1, r);
}

template<typename Item>
void hybridsort(Item a[], int l, int r)
{
    quicksort(a, l, r);

    // quick sort returns for stubs with length less than 11
    insertion(a, l, r);
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
  quicksort(a, 0, N-1);

  // Printing sorted numbers
  for(i=0; i<N; i++) std::cout << a[i] << " ";
  std::cout << std::endl;

}