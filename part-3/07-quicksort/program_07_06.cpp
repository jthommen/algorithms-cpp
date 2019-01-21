/*
###
Program 7.6 & 7.7: Recursive & Nonrecursive Selection
###

Description:
Recursive - Procedure partitions an array about the (k-l)th
smallest element (the one in a[k]): It rearranges the array
to leave a[l], ..., a[k-1] less than or equal to a[k], and
a[k+1], ..., a[r] greater than or equal to a[k].
    For example, we could call select(a, 0, N-1, N/2) to
partition the array on the median value, leaving the median
in a[N/2].


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

// Recursive Selection
template<typename Item>
void select(Item a[], int l, int r, int k)
{
    if(r <= l) return;
    int i = partition(a, l, r);
    if(i > k) select(a, l, i-1, k);
    if(i < k) select(a, i+1, r, k);
}

// Nonrecursive selection
/*
template<typename Item>
void select(Item a[], int l, int r, int k)
{
    while (r > l)
    {
        int i = partition(a, l, r);
        if(i >= k) r = i-1;
        if(i <= k) l = i+1;
    }
}
*/

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

  // Selection
  select(a, 0, N-1, N/2);

  // Print Median
  std::cout << a[N/2] << std::endl;

}