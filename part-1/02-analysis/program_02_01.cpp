/*
###
Program 2.1: Sequential Search
###


Abstract Operations:
- Search: Find object in collection

Description:
This function checks whether the number v is among a previously stored
set of numbers in a[1], a[i+1], ..., a[r], by comparing against each
number sequentially, starting at the beginning. If we reach the end
without finding the number sought, then we return the value -1. Otherwise,
we return the index of the array position containing this number.

Property:
a) Sequential search examines N numbers for each unsuccessful search
and about N/2 numbers for each successful search on average.
b) Sequential search in an orderedtable examines N numbers for each
search in the worst case and about N/2 numbers for each search on
the average.

*/

#include<iostream>

int sequential_search(int a[], int v, int l, int r);

int main()
{
    int c1[] = {1,2,3,4,5,6,7,8,9,10};
    int c2[] = {5,7,3,9,6,1,4,8,10,7};

    std::cout << sequential_search(c1, 8, 0, 9) << std::endl;
    std::cout << sequential_search(c2, 7, 0, 9) << std::endl;
    std::cout << sequential_search(c2, 0, 0, 9) << std::endl;

}

int sequential_search(int a[], int v, int l, int r)
/* Params:
a = collection to search trough
v = value to look for
l = leftmost position in collection
r = rightmost position in collection
*/
{
    for(int i=l; i<=r; i++)
    {
        if(v==a[i]) return i;
    }
    return -1;
}