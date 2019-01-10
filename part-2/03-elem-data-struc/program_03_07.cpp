/*
###
Program 3.7: Coin-flipping Simulation
###

Description:
If we flip a coin N times, we expect to get N/2 heads, but
could get anywhere from 0 to N heads. This program runs the
experiment M times, taking both N and M from the command line.
It uses an array f to keep track of the frequency of occurence
of the outcome "i heads" for  0 <= i <= N, then prints out a
histogram of theresult of the experiments, with one asterisk
for each 10 occurrences.
    The operation on which this program is based - indexing an
array with a computed value - is critical to the efficiency of
many computational problems.

*/

#include<iostream>
#include<cstdlib>

int heads()
{
    return rand() < RAND_MAX/2;
}

int main(int argc, char *argv[])
{
    int i, j, cnt;
    if(argc<2) 
    {
        std::cerr << "Need two command line arguments.\n";
        return -1;
    }
    // N = number of coin flips, M = number of experiments with N flips
    int N = atoi(argv[1]), M = atoi(argv[2]);

    int *f = new int[N+1];
    
    for(j=0; j<=N; j++) f[j]=0; // Initialize array to 0
    
    // Run M experiments with N flips each, count heads
    for(i=0; i<M; i++, f[cnt]++)
        for(cnt=0, j=0; j<=N; j++)
            if(heads()) cnt++;
    
    // Check how many heads we got and print stars accordingly
    for(j=0; j<=N; j++)
    {
        if(f[j]==0) std::cout << ".";
        for(i=0; i<f[j]; i+=10) std::cout<< "*";
        std::cout << std::endl;
    }
}