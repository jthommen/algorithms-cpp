/*
###
Exercise 1.6: Weighted quick-union
###

Description: 
Show the contents of the id array after each weighted union operation
when you use the quick union algorithm to solve the connectivity 
problem.

Sample data:
1.7: 3-4, 4-9, 8-0, 3-2, 5-6, 5-9, 3-7, 8-4, 1-6
1.8: 0-1, 2-3, 4-5, 6-7, 8-9, 0-2, 4-6, 0-4, 8-6
*/

#include<fstream>
#include<iostream>
#include "../../lib/analysis.hpp"

static const int N = 10;

int main(int argc, char *argv[])
{
    std::ifstream is {argv[1]};
    if(!is) std::cerr << "no file!\n";
    
    int i, j, p, q, id[N], sz[N];

    for(i=0; i<N; i++)
    {
    id[i] = i;
    sz[i] = 1;    
    }

    std::cout << "Weighed Quick-Union Algorithm to solve Connectivity Problem\n";
    while(is >> p >> q)
    {
        // Find
        for(i=p; i!= id[i]; i=id[i]);
        for(j=q; j!=id[j]; j=id[j])


        // Union
        if(i==j) continue;

        if(sz[i] < sz[j])
        {
            id[i] = j; sz[j] += sz[i];
        } else {
            id[j] = i; sz[i] += sz[j];
        }
        analysis::print_array(id, N);

        std::cout << " " << p << " " << q << std::endl;
    }

}