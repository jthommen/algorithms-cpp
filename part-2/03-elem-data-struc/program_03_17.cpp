/*
###
Program 3.17: Sorting an array of strings
###

Description:
Important string-processing function: rearranging
a set of strings into sorted order. We read strings
into a buffer large enough to hold them all, maintaining
a pointer to each string in an array, then rearrange
the pointers to put the pointer to the smaller string
in the first position in the arry, the pointer to the
second smallest string in the second position in the
array and so forth.
    The qsort library function that does the sort takes
4 arguments:
1. A pointer to the beginning of an array
2. The number of objects
3. The size of each object
4. A comparison function
To actually access the first character in a string for a 
comparison, we dereference three pointers:
1. To get the index (which is a pointer) into our array
2. To get the pointer to the string (using the index)
3. To get the charater (using the pointer)

*/

#include<iostream>
#include<cstdlib>
#include<cstring>

// Hold off till future chapters
int compare(const void* i, const void* j)
{
  return strcmp(*(char**)i, *(char **)j);
}

int main()
{
  const int Nmax = 1000;
  const int Mmax = 10000;

  // Declare array to hold pointers
  char* a[Nmax]; int N;

  // Decalre buffer for strings
  char buf[Mmax]; int M = 0;

  // Read strings into buffer
  for(N=0; N < Nmax; N++)
  {
    a[N] = &buf[M];
    if(!(std::cin >> a[N])) break;
    M += strlen(a[N])+1;
  }
  
  // Sort strings
  qsort(a, N, sizeof(char*), compare);

  // Print strings
  for(int i=0; i < N; i++)
    std::cout << a[i] << std::endl;
}