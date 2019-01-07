/*
###
Exercise 1.4: Quick-find
###

Description: 
a) Show the contents of the id array after each union operation
when you use the quick find algorithm to solve the connectivity 
problem for the sequence: 0-2, 1-4, 2-5, 3-6, 0-4, 6-0 and 1-3.
b) Also give the number of times the program accesses the id
array for each input pair.
*/

#include<iostream>
#include "../../lib/analysis.hpp"

static const int N = 10;

int main()
{
    int i, p, q, id[N], sz[N];

    for(i=0; i<N; i++)
    {
    id[i] = i;
    sz[i] = 1;    
    }

    std::cout << "Please enter non negative integer pairs, separated by spaces (e.g. 3 9): \n";
    while(std::cin >> p >> q)
    {
        // Find
        int t = id[p];


        // Union
        if(t==id[q]) continue;
        for(i=0; i<N; i++)
        {
            if(id[i]==t) id[i] = id[q];
            ++sz[i];
            analysis::print_array(id, N);
            analysis::print_array(sz, N);
        }

        std::cout << " " << p << " " << q << std::endl;
    }

}