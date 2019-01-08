#include<iostream>
#include<random>

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

void analysis::random_number_array(int *a, int N)
{
    /*
    Random Number Generator:
    Initialized with Mersenne Twister with popular params
    using random_device as seed value
    Generates uniform distribution with positive values
    */
    std::random_device rdev;
    int32_t random_seed = rdev();
    std::seed_seq seeder{random_seed};
    std::mt19937 rng(seeder);

    // creating distribution
    std::uniform_int_distribution<int32_t> uint_dist(0);

    for(int i=0; i<N; ++i)
    {
        a[i]= uint_dist(rng);
    }
}