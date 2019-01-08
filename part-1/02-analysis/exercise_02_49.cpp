/*
###
Exercise 2.49: Sequential search with (pseudo) random numbers
###

Description: 
Write a driver program that generates M random integers and puts them in an array,
then counts the number of N random integers that matches one of the numbers in the
array, using sequential search. Run your program for M=10, 100, and 1000.
*/

#include<chrono>
#include <iostream>
#include "../../lib/analysis.hpp"

int sequential_search(int *a, int v, int l, int r);
int binary_search(int *a, int v, int l, int r);

int main()
{
    // Create search bodies
    int c10[10], c100[100], c1000[1000];
    analysis::random_number_array(c10, 10);
    analysis::random_number_array(c100, 100);
    analysis::random_number_array(c1000, 1000);

    // Create values to searchfor
    int t[10];
    analysis::random_number_array(t, 10);

    // Sequential search through it and measure time
    std::cout << "Sequential Search\n";
    // M = 10
    auto start = std::chrono::system_clock::now();
    for(int i=0; i<10; i++)
    {
        sequential_search(c10, t[i], 0, 9);
    }
    auto end = std::chrono::system_clock::now();
    std::cout << "Time for N=10 and M=10: "
        << std::chrono::duration_cast<std::chrono::microseconds>(end-start).count()
        << " microseconds\n";

    // M = 100
    start = std::chrono::system_clock::now();
    for(int i=0; i<100; i++)
    {
        sequential_search(c100, t[i], 0, 99);
    }
    end = std::chrono::system_clock::now();
    std::cout << "Time for N=10 and M=100: "
        << std::chrono::duration_cast<std::chrono::microseconds>(end-start).count()
        << " microseconds\n";

    // M = 1000
    start = std::chrono::system_clock::now();
    for(int i=0; i<1000; i++)
    {
        if(sequential_search(c1000, t[i], 0, 999) == -1);
    }
    end = std::chrono::system_clock::now();
    std::cout << "Time for N=10 and M=1000: "
        << std::chrono::duration_cast<std::chrono::microseconds>(end-start).count()
        << " microseconds\n";

    // Optional: Same with binary search
    std::cout << "Binary Search\n";
    // M = 10
    start = std::chrono::system_clock::now();
    for(int i=0; i<10; i++)
    {
        binary_search(c10, t[i], 0, 9);
    }
    end = std::chrono::system_clock::now();
    std::cout << "Time for N=10 and M=10: "
        << std::chrono::duration_cast<std::chrono::microseconds>(end-start).count()
        << " microseconds\n";

    // M = 100
    start = std::chrono::system_clock::now();
    for(int i=0; i<100; i++)
    {
        binary_search(c100, t[i], 0, 99);
    }
    end = std::chrono::system_clock::now();
    std::cout << "Time for N=10 and M=100: "
        << std::chrono::duration_cast<std::chrono::microseconds>(end-start).count()
        << " microseconds\n";

    // M = 1000
    start = std::chrono::system_clock::now();
    for(int i=0; i<1000; i++)
    {
        binary_search(c1000, t[i], 0, 999);
    }
    end = std::chrono::system_clock::now();
    std::cout << "Time for N=10 and M=1000: "
        << std::chrono::duration_cast<std::chrono::microseconds>(end-start).count()
        << " microseconds\n";


}

int sequential_search(int *a, int v, int l, int r)
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

int binary_search(int *a, int v, int l, int r)
/* Params:
a = collection to search trough
v = value to look for
l = leftmost position in collection
r = rightmost position in collection
*/
{
    while(r >= 1)
    {
        int m = (l+r)/2;
        if(v == a[m]) return m;
        if(v < a[m]) r = m-1; else l = m+1;
        if(l==m || r==m) break; // endless loop otherwise
    }
    return -1;
}