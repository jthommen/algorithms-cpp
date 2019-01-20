/*
###
Program 6.17: Kex-Indexed Counting (Array)
###

Description:
The first loop initializes the coutns to 0;
the second for loop sets the second counter
to the number of 's, the third counter to the
numbers of 1s, and so forth. Then, the third for
loop simply adds these numbers to produce counts
of the number of keys less than or equal to the one
corresponding to the count. These numbers now give
the indices of the end of the part of the file where
keys belong. The fourth for loop moves the keys into
an auxiliary array b according to these indices, and 
the final loop moves the sorted file back into a.
The keys must be integers less than M for thise code 
to work, although we can easily modify it to extract
such keys from more complex items.

Properties:
- Key-indexed counting is a linear-time sort, provided
that the range of distinct key values is within a 
constant factor of the file size.
*/

#include<iostream>
#include<cstdlib>


void distcount(int a[], int l, int r)
{
  int i, j, cnt[M];
  static int b[maxN];
  for(j=0; j < M; j++) cnt[j]=0;
  for(i=l; i <= r; i++) cnt[a[i]+1]++;
  for(j=i; j < M; j++) cnt[j] += cnt[j-1];
  for(i=l; i <= r; i++) b[cnt[a[i]]++] = a[i];
  for(i=l; i <= r; i++) a[i] = b[i-l];
}
