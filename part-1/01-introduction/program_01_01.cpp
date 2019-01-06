/*
###
Program 1.1: Quick-find solution to the connectivity problem
###

Connectivity Problem: Are all elements in the input pairs connected?

Abstract Operations:
- Find: Find the set containing a given item
- Union: Replace the sets containing two given items by their union

Description:
This program reads a sequence of pairs of nonnegative integers less than
N from standard input (interpreting the pair p q to mean "connect object
p to object q") and prints out pairs representing objects that are not yet
connected. It maintains an array id that has an entry for each object,
with the property that id[p] and id[q] are equal if and only if p and
q are connected. For simplicity, we define N as a compile-time constant.
Alternatively, we could take it from the input and allocate the id array
dynamically.

Property:
Brute-force approach. The quick find algorithm executes at least M N instructions
to solve a connectivity problem with N objects that involes M
union operations. 

Sample data: 3 9 4 9 8 0 2 3 5 6 2 9 5 9 7 3 4 8 5 6 0 2 6 1
*/

#include<iostream>

static const int N = 10000;

int main()
{
    // variable declaration
    int i, p, q, id[N];

    // array initialization
    for(i=0; i<N; i++) id[i] = i;

    // read pairs from input compute comparison
    std::cout << "Please enter non negative integer pairs, separated by spaces (3 9 4 9): \n";
    while(std::cin >> p >> q)
    {
        // change all entries with value id[p] to have the value id[q]
        int t = id[p];

        if(t==id[q]) continue; // check: jump to next pair if done already

        for(i=0; i<N; i++)
            if(id[i]==t) id[i] = id[q];

        std::cout << " " << p << " " << q << std::endl;
    }

    // If all array elements are the same, elements are connected

}
