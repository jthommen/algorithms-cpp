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
#include<iostream>
#include "../../lib/analysis.hpp"

int sequential_search(int *a, int v, int l, int r);
int binary_search(int *a, int v, int l, int r);

int main()
{
    // Variable setup
    int count, M, t_length, lower;
    int *c;

    // Create search bodies
    int c10[10], c100[100], c1000[1000], c10000[10000];
    analysis::random_number_array(c10, 10);
    analysis::random_number_array(c100, 100);
    analysis::random_number_array(c1000, 1000);
    analysis::random_number_array(c10000, 10000);

    // Create values to searchfor
    t_length = 10;
    int t[t_length];
    analysis::random_number_array(t, t_length);


    // Sequential search through it and measure time
    std::cout << "Sequential Search\n";

    M = 10;
    c = c10;
    count = 0;
    for(int i=0; i<t_length; ++i) analysis::measure_time(sequential_search, c, t[i], lower, (M-1));
    std::cout << "Execution time: " << count << " nanoseconds\n";
    
    M = 100;
    count = 0;
    c = c100;
    for(int i=0; i<t_length; i++) count += analysis::measure_time(sequential_search, c, t[i], lower, (M-1));
    std::cout << "Execution time: " << (count/1000.0) << " microseconds\n";

    M = 1000;
    count = 0;
    c = c1000;
    for(int i=0; i<t_length; i++) count += analysis::measure_time(sequential_search, c, t[i], lower, (M-1));
    std::cout << "Execution time: " << (count/1000.0) << " microseconds\n";

    M = 10000;
    count = 0;
    c = c10000;
    for(int i=0; i<t_length; i++) count += analysis::measure_time(sequential_search, c, t[i], lower, (M-1));
    std::cout << "Execution time: " << (count/1000.0) << " microseconds\n";

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
        //std::cout << a[i];
    }
    return -1;
}