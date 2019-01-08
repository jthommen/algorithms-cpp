/*
###
Program 2.2: Binary Search
###


Abstract Operations:
- Search: Find object in collection

Description:
Same functionality as sequential search, but is much more efficient.
Data needs to be sorted in order to work.

Property:
Binary search never examines more than [lg N] + 1 elements.

*/
#include<fstream>
#include<iostream>
#include "../../lib/analysis.hpp"

int binary_search(int a[], int v, int l, int r);

int main()
try {

    // Initialize array from file (ugly, should use vector)
    std::ifstream is {"sample_data_02_01.txt"};
    int N = 100;
    int d;
    int i = 0;
    int c[N];
    while(is >> d)
    {
        if(i<N) c[i] = d;
        i++;
    }
    analysis::print_array(c, 23);

    // run search
    std::cout << binary_search(c, 8340, 0, 22) << std::endl;
    std::cout << binary_search(c, 5036, 0, 22) << std::endl;
    std::cout << binary_search(c, 3665, 0, 22) << std::endl;

} catch(...){
    std::cerr << "An error occured.\n";
}

int binary_search(int a[], int v, int l, int r)
/* Params:
a = collection to search trough
v = value to look for
l = leftmost position in collection
r = rightmost position in collection
*/
{
    std::cout << v << std::endl;
    while(r >= 1)
    {
        int m = (l+r)/2;
        if(v == a[m]) return m;
        if(v < a[m]) r = m-1; else l = m+1;
        std::cout << "l==" << l << " m==" << m
            << " r==" << r << std::endl;
        if(l==m || r==m) break; // endless loop otherwise
    }
    return -1;
}