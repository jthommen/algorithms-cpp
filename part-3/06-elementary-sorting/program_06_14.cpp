/*
###
Program 6.14: In-place (insitu) Sort (Array)
###

Description:
The array data[0], ..., data[N-1] is to be rearranged in place as
directed by the index array a[0], ... a[N-1]. Any element with
a[i] == i is in place and does not need to be touched again. Otherwise,
save data[i] as v and work through the cycle a[i], a[a[i]], a[a[a[i]]],
and so on, until reaching the index i again. We follow the process again
for the next element which is not in place, and continue in this manner,
ultimately rearranging the entire file, moving each record only once.

*/

#include<iostream>
#include<cstdlib>


// Data, index, data size
template<typename Item>
void insitu(Item data[], Item a[], int N)
{
  for(int i=0; i<N; i++)
  {
    Item v = data[i];
    int j, k;
    for(k=i; a[k] != i; k=a[j], a[j]=j)
    {
      j=k;
      data[k]=data[a[k]];
    }
    data[k]=v;
    a[k]=k
  }
}
