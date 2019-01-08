/*
###
Exercise 2.2: Runtime Checks
###

Description: 
How long does it take to count to 1 billion (ignoring overflow)?
Determine the amout of time it takes the program to complete in
your programming environment for N=10, 100 and 1000.
*/
#include<iostream>
#include<chrono>

void counting(int N);

int main()
try{
    /*
    System Information:
    Intel i7 9700k (8 Core, 4.6Ghz Turboboost)
    16GB DDR4-3200Mhz RAM
    */
    counting(10); // go to 1000: < 1 ms
    counting(100); // go to 1'000'000: 1ms
    counting(1000); // go to 1'000'000'000: 1109s or 1.109s
    counting(10000); // go to 1'000'000'000'000: 1099560ms or 1099.560s or 18.326min
} catch(...) {
    std::cerr << "An error occcured.\n";
}


void counting(int N)
// Big O: N^3
{
    auto start = std::chrono::system_clock::now();
    int i, j, k;
    long count = 0; // 64bit with space for up to 9,223,372,036,854,775,807
    for(i=0; i<N; i++)
    {
        for(j=0; j<N; j++)
        {
            for(k=0; k<N; k++)
            {
                count++;
            }
        }
    }
    auto end = std::chrono::system_clock::now();

    std::cout << "counting(" << N << ") took "
        << std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count()<< " milliseconds "
        << "final count was: " << count << std::endl;
}