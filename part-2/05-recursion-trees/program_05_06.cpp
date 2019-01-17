/*
###
Program 5.6: Divide-and-conquer to find the maximum
###

Description:
This function divides an array a[1], ..., a[r] into
a[l], ..., a[m] and a[m+1], ... a[r], finds the maximum
elements in the two parts recursively, and returns the larger
ofthe two as the maximum element in the whole array. It 
assumes that Item is a first-class type for which > is
defined. If the array size is even, the two parts are equal
in size; if the array size is odd, the size of the two 
parts differ by 1.

Properties:
A recursive function that divides a problem of size N into
two independent (nonempty) parts that it solves recursively
calls itself less than N times.
*/

#include<iostream>

template<typename Item>
Item max(Item a[], int l, int r)
{
  if(l == r) return a[l];
  int m = (l+r)/2;
  Item u = max(a, l, m);
  Item v = max(a, m+1, r);
  if(u > v) return u; else return v;
}

int main()
{
  int a[10] {3, 53, 23, 43, 3, 98, 63, 17, 34, 15};

  int m = max(a, 0, 9);
  std::cout << "Max of a is: " << m << std::endl;
}