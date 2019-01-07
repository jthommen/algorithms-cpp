#include<iostream>

#include "analysis.hpp"

using namespace analysis;

void analysis::print_array(int *a, int N)
{
    for(int i=0; i<N; ++i)
    {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
}