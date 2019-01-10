/*
###
Program 3.8: Closest-point Computation
###

Description:
This program illustrates the use of an array of structures, and is
representative of the typical situation where we save items in an
array to process them later, during some computation. It counts the
number of pairs of N randomly generated points in the unit square
that can be connected by a straight line of length less than d,
using a simple struct for points. 

Property:
The running time is O(N^2), so this program cannot be used for huge N.

*/

#include<iostream>
#include<cstdlib>
#include "Point.hpp"

float randFloat()
{ return 1.0*rand()/RAND_MAX; }

int main(int argc, char *argv[])
{
    // Command line arguments check
    if(argc<2) 
    {
        std::cerr << "Need two command line arguments.\n";
        return -1;
    }

    float d  = atof(argv[2]);
    int i, j, cnt = 0, N = atoi(argv[1]);
    point *a = new point[N]; // create array to hold points
    
    // Initialize array of points with random floats
    for(i=0; i<N; i++)
    {
        a[i].x = randFloat(); a[i].y = randFloat();
    }

    // Check & count for point x, x+1 if they're within distance
    for(i=0; i<N; i++)
        for(j=i+1; j<N; j++)
            if(distance(a[i], a[j]) < d) cnt++;

    // Print out pairs that hold condition
    std::cout << cnt << " pairs within " << d << std::endl;
}