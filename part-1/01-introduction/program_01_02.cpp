/*
###
Program 1.2: Quick-union solution to the connectivity problem
###

Connectivity Problem: Are all elements in the input pairs connected?

Abstract Operations:
- Find: Find the set containing a given item
- Union: Replace the sets containing two given items by their union

Description:
If we replace the body of the while loop in Program 1.1 by this code, we
have a program that meets the same specifications as Program 1.1, but
does less computation for the union operation at the expense of more
computation for the find operation. The foor loops and subsequent if
statement in this code specify the necessary and sufficient conditions on
the id array for p and q to be connected. The assignment statement
id[i] = j implements the union operation.

Property:
Faster than quick-find algorithm, because it doesn't have to go
through the entire array for each input pair.
For M > N, the quick-union algorithm could take more than M N/2
instructions to solve a connectivity problem with M pairs of N objects.

Sample data: 3 9 4 9 8 0 2 3 5 6 2 9 5 9 7 3 4 8 5 6 0 2 6 1
*/

#include<iostream>

static const int N = 10;

void print_array(int *a);

int main()
{
    // variable declaration
    int i, j, p, q, id[N];

    // array initialization
    for(i=0; i<N; i++) id[i] = i;
    print_array(id);

    // read pairs from input compute comparison
    std::cout << "Please enter non negative integer pairs, separated by spaces (3 9 4 9): \n";
    while(std::cin >> p >> q)
    {
        /* 
        Find:
        if is is not array[i] then set i to array[i]
        repeat as long as condition isn't true
        Follows the pointers/connections until the root node for p and q
        */
        for(i=p; i!= id[i]; i=id[i]);
        print_array(id);
        for(j=q; j!=id[j]; j=id[j]);
        print_array(id);

        /*
        Union:
        */
        if(i==j) continue;
        id[i] = j;
        print_array(id);

        std::cout << " " << p << " " << q << std::endl;
    }

}

void print_array(int *a)
{
    for(int i=0; i<N; ++i)
    {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
}