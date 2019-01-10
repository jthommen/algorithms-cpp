/*
###
Exercise 3.2: Random-number generator
###

Description:
Test the random-number generator on your system by generating N
random integers between 0 and r-1 with rand() % r and computing the
average and standard deviation for r=10, 100 and 1000 and N=10^3, 10^4
10^5, and 10^6.

*/

#include<cmath>
#include<cstdlib>
#include<iostream>


int rndNmbr(int r);
double cmpAvg(int *a, int sz);
double cmpVar(int *a, int sz);
double cmpStd(int *a, int sz); 
void compute(int r, int N);

int main()
{
    // r=10
    // N=1000
    compute(10, 1000);
    // N=10'000
    compute(10, 10000);
    // N=100'000
    compute(10, 100000);
    // N=1'000'000
    compute(10, 1000000);

    // r=100
    // N=1000
    compute(100, 1000);
    // N=10'000
    compute(100, 10000);
    // N=100'000
    compute(100, 100000);
    // N=1'000'000
    compute(100, 1000000);

    // r=1000
    // N=1000
    compute(1000, 1000);
    // N=10'000
    compute(1000, 10000);
    // N=100'000
    compute(1000, 100000);
    // N=1'000'000
    compute(1000, 1000000);
}

void compute(int r, int N)
{
    int a[N];
    for(int i=0; i<N; i++) a[i] = rndNmbr(r);
    double avg = cmpAvg(a, N);
    double var = cmpVar(a, N);
    double std = cmpStd(a, N);
    std::cout << "R=" << r << ", N=" << N << ", avg: " << avg
        << ", Var: " << var << ", Std: " << std << std::endl;
}

int rndNmbr(int r)
{
    return rand() % r;
}

double cmpAvg(int *a, int sz)
{
    int sum = 0;
    for(int i=0; i<sz; ++i) sum += a[i];
    return sum / sz;
}

double cmpVar(int *a, int sz)
{
    double mean = cmpAvg(a, sz);
    double temp = 0;
    for(int i=0; i<sz; ++i) temp+=(a[i]-mean)*(a[i]-mean);
    return temp/(sz-1);
}

double cmpStd(int *a, int sz)
{
    return sqrt(cmpVar(a, sz));
};