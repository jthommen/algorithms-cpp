/*
###
Program 7.5: Quicksort with three-way partitioning
###

Description:
Based on partitioning the array into three parts:
1. elements smaller than the partitioning element (a[l], ..., a[j]);
2. elements equal to the partitioning element (in a[j+1], ..., a[i-1]);
3. elements equal to the partitioning element (in a[i], ..., a[r]);
Then the sort can be completed with two recursive calls.

To accomplish the objective, the program keeps keys equal to the
partitioning  element on the left between l and p and on the right
between q and r. In the partitioning loop, after the scan pointers stop
and the items at i and j are exchanged, it checks each of those items to
see whether it is equal to the partitioning element. If the one now on
the left is equal to the partitioning element, it is exchanged into the
left element; if one now on the right is equal to the partitioning element,
it is exchanged into the right part of the array.
    After the pointers cross, the elements equal to the partitioning element
are exchanged from the ends of the array into position. Then those keys
can be excluded from the subfiles for the recursive calls.

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

template<typename Item>
int operator==(const Item& A, const Item& B)
{
    return !less(A, B) && !less(B, A);
}

template<typename Item>
void quicksort(Item a[], int l, int r)
{
    int k;
    Item v = a[r];
    
    if(r <= l) return;
    
    int i = l-1, j = r, p = l-1, q = r;
    
    for(;;)
    {
     while(a[++i] < v);
     while(v < a[--j]) if (j == l) break;
     if(i >= j) break;
     exch(a[i], a[j]);
     if(a[i] == v) { p++; exch(a[p], a[i]); }
     if(v == a[j]) { q--; exch(a[q], a[j]); }  
    }
    
    exch(a[i], a[r]);
    j = i-1;
    i = i+1;
    
    for(k=l; k <= p; k++, j--) exch(a[k], a[j]);
    for(k=r-1; k >=q; k--, i++) exch(a[k], a[i]);
    
    quicksort(a, l, j);
    quicksort(a, i, r);
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