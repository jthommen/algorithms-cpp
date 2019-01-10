/*
###
Program 3.5 & 3.6: Sieve of Eratosthenes
###

Description:
The goal of this program is to set a[i] to 1 if i is prime,
and to 0 if i is not prime. First, it sets to 1 all array
elements, to indicate that no numbers are known to be nonprime.
Then it sets to 0 array elements corresponding to indices that 
are known to be nonprime (multiples of known primes). If a[i] is
still 1 after all multiples of smaller primes have been set to
0, then we know it to be prime.
    Because the program uses an array consisting of the simplest 
type of elements, 0-1 values, it would be more efficient if we
explicitly used an array of bits, rather than one of integers.

*/

#include<iostream>

int main(int argc, char *argv[])
{
    // DANGER: No argument check
    int i, N = atoi(argv[1]);

    // Declare array to hold ints
    int *a = new int[N];

    if(a == 0) // Quick memory check
    { std::cout << "out of memory\n"; return 0; }

    // Initialize all N to 1 = prime
    for(i=2; i<N; i++) a[i] = 1;

    // Skip over 0 & 1
    for(i=2; i<N; i++)
        // Check if index has already been computed and is 0
        if(a[i])
            // Increase multiple until N, those multiples aren't prime
            for(int j=i; j*i < N; j++) a[i*j] = 0;
    
    // The numbers that remain have no factors, therefore must be prime
    for(i=2; i<N; i++)
        if(a[i]) std::cout << " " << i;
    std::cout << std::endl;
}