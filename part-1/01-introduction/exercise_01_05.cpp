/*
###
Exercise 1.5: Quick-union
###

Description: 
a) Show the contents of the id array after each union operation
when you use the quick union algorithm to solve the connectivity 
problem for the sequence: 0-2, 1-4, 2-5, 3-6, 0-4, 6-0 and 1-3.
b) Also give the number of times the program accesses the id
array for each input pair.
*/

#include<iostream>
#include "../../lib/analysis.hpp"

static const int N = 10;

int main()
{
    int i, j, p, q, id[N], sz[N];

    for(i=0; i<N; i++)
    {
    id[i] = i;
    sz[i] = 1;    
    }

    std::cout << "Please enter non negative integer pairs, separated by spaces (e.g. 3 9): \n";
    while(std::cin >> p >> q)
    {
        // Find
        for(i=p; i!= id[i]; i=id[i]);
        for(j=q; j!=id[j]; j=id[j])


        // Union
        if(i==j) continue;
        id[i] = j;
        ++sz[i];
        analysis::print_array(id, N);
        analysis::print_array(sz, N);

        std::cout << " " << p << " " << q << std::endl;
    }

}