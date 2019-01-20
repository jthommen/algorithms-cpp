/*
###
Program 6.5: Shellsort
###

Description:
If we do not use sentinels and then replace every occurrence
of "1" by "h" in insertion sort, the resulting program h-sorts
the file. Adding an outer loop to change the increments leads
to this compact shellsort implementation, which uses the increment 
sequence: 1 4 13 40 121 364 1093 3280 9841 ....
(start with 1, generate next increment by multiplying by 3 and adding 1)

Properties:
- Runtime depends on the increment sequence, but approx. N(log N)^2

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
void shellsort(Item a[], int l, int r)
{
  int h;
  for(h=1; h<= (r-l)/9; h = 3*h+1);
  for(; h>0; h/=3)
    for(int i = l+h; i <= r; i++)
    {
      int j=i;
      Item v = a[i];
      while(j >= l+h && v < a[j-h])
      {
        a[j] = a[j-h];
        j -= h;
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
  shellsort(a, 0, N-1);

  // Printing sorted numbers
  for(i=0; i<N; i++) std::cout << a[i] << " ";
  std::cout << std::endl;
}