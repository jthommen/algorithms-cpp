/*
###
Program 1.4: Weighted version of the Quick-union solution to the 
connectivity problem with path compression by halving
###

Connectivity Problem: Are all elements in the input pairs connected?

Abstract Operations:
- Find: Find the set containing a given item
- Union: Replace the sets containing two given items by their union

Description:
If we replace the for loops by this code, we halve the length
of any path that we traverse. The net result of this change is
that the trees become almost completely flat after a long
sequence of operations.

Property:
The weighted quick-union algorithm follows at most log N pointers


Sample data: 3 9 4 9 8 0 2 3 5 6 2 9 5 9 7 3 4 8 5 6 0 2 6 1
*/

#include<iostream>
#include "../../lib/analysis.hpp"

static const int N = 10;

int main()
{
    // variable declaration
    int i, j, p, q, id[N], sz[N];
    /*
    Note: id of nodes are the indexes, the id[i] specifies
    the element's parent, sz[i] specifies amount of child elements - 1.
    */

    // array initialization
    for(i=0; i<N; i++) 
    {
        id[i] = i;
        sz[i] = 1;
    }
    analysis::print_array(id, N);
    analysis::print_array(sz, N);

    // read pairs from input compute comparison
    std::cout << "Please enter non negative integer pairs, separated by spaces (e.g. 3 9): \n";
    while(std::cin >> p >> q)
    {
        /* 
        Find:
        if i is not array[i] then set i to array[i]
        repeat as long as condition isn't true
        Follows the pointers/connections until the root node for p and q
        */
        for(i=p; i!= id[i]; i=id[i])
        {
            id[i] = id[id[i]];
            std::cout << "i=" << i << std::endl;
            std::cout << "id[i]=" << id[i] << std::endl;
            std::cout << "id[id[i]]=" << id[id[i]] << std::endl;
        }
        for(j=q; j!=id[j]; j=id[j])
        {
            id[j] = id[id[j]];
            std::cout << "j=" << j << std::endl;
            std::cout << "id[j]=" << id[j] << std::endl;
            std::cout << "id[id[j]]=" << id[id[j]] << std::endl;
        }

        /*
        Union:
        all elements start with tree size = 1
        size is compared, if they're the same size, arbitrarly
        j is attached to i.
        */
        if(i==j) continue;

        if(sz[i] < sz[j])
        {
            id[i] = j;
            sz[j] += sz[i];
        } else {
            id[j] = i;
            sz[i] += sz[j];
        }
        analysis::print_array(id, N);
        analysis::print_array(sz, N);
        /*
        Note: Connected elements moved into the tree get the value of 
        the tree root node and default length 1.
        */

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