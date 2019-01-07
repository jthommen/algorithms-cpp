/*
###
Program 1.3: Weighted version of the Quick-union solution to the 
connectivity problem
###

Connectivity Problem: Are all elements in the input pairs connected?

Abstract Operations:
- Find: Find the set containing a given item
- Union: Replace the sets containing two given items by their union

Description:
This program is a modification to the quick-union algorithm that
keeps an additional array sz for the purpose of maintaining, for
each object with id[id] == 1, the number of nodes in the associated
tree, so that the union operation can link the smaller of the two
specified trees to the larger, thus preventing the growth of 
long paths in the trees.

Property:
The weighted quick-union algorithm follows at most log N pointers
to determine whether two of N objects are connected.
Can be linear for huge data sets.

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
        for(i=p; i!= id[i]; i=id[i]);
        for(j=q; j!=id[j]; j=id[j]);

        /*
        Union:
        all elements start with tree size = 1
        size is compared, if they're the same size, arbitrarly
        j is attached to i.
        */
        if(i==j) continue;

        if(sz[i] < sz[j])
        {
            id[i] = j; sz[j] += sz[i];
        } else {
            id[j] = i; sz[i] += sz[j];
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
