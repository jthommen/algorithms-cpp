#include<chrono>
#include<iostream>
#include "../../lib/analysis.hpp"

int binary_search(int *a, int v, int l, int r);

template<typename func, typename ...Types>
int measure_time(func *f, Types... args)
{
    auto start = std::chrono::system_clock::now();

    f(std::forward<Types>(args)...);

    auto end = std::chrono::system_clock::now();
    auto exect = std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count();
    return exect;
}

int main()
{
    // Create search collection
    int c[10000];
    analysis::random_number_array(c, 10000);

    // Create values to searchfor
    int t[10];
    analysis::random_number_array(t, 10);

    int nano_time;
    for(int i=0; i<10; i++)
    {
        nano_time += measure_time(binary_search, c, t[i], 0, 9999);
    }
    float micro_time = nano_time/1000.0; //microseconds
    std::cout << "Execution time: " << nano_time << " nanoseconds or, " << micro_time << " microseconds\n";
}

int binary_search(int *a, int v, int l, int r)
/* Params:
a = collection to search trough
v = value to look for
l = leftmost position in collection
r = rightmost position in collection
*/
{
    while(r >= 1)
    {
        int m = (l+r)/2;
        if(v == a[m]) return m;
        if(v < a[m]) r = m-1; else l = m+1;
        if(l==m || r==m) break; // endless loop otherwise
    }
    return -1;
}