/*
###
Program 7.1 & 7.2: Basic Quicksort (Array)
###

Description:
Quicksort - If the array has one or fewer elements, do nothing. Otherwise, the array
is processed by a partition procedure, which puts a[i] into position for
some i between l and r inclusive, and rearranges the other elements such
that the recursive calls properly finish the sort.

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

// Switch items
template<typename Item>
void exch(Item& A, Item& B)
{
  Item t = A; A = B; B = t;
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

template<typename Item>
void quicksort(Item a[], int l, int r)
{
    // Only one item, don't sort
    if(r <= l) return;

    // Create partition
    int i = partition(a, l, r);

    // Sort both partitions recursively
    quicksort(a, l, i-1);
    quicksort(a, i+1, r);
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