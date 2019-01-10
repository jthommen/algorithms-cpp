/*
###
Program 3.9: Circular list example (Josephus problem)
###

Description:
To represent people arranged in a circle, we build a circular linked list,
with a link from each person to the person on the left in the circle. The
integer i represents the ith person in the circle. After building a one-node
circular list for 1, we insert 2 through N after that node, resulting in
a circle with 1 through N, leaving x pointing to N. Then, we skip M-1 nodes,
beginning with 1, and set the link of the (M-1)st to skip the Mth, continuing
until only one node is left.

*/

#include<iostream>
#include<cstdlib>

// structure for list element, called node
struct node
{
    int item; 
    node* next;
    node(int x, node* t): item{x}, next{t} { };
};

// pointer from one node to the next, called link
typedef node* link;

int main(int argc, char *argv[])
{
    // Command line arguments check
    if(argc<2) 
    {
        std::cerr << "Need two command line arguments.\n";
        return -1;
    }

    // Declare iterator, assign command line args
    int i,  N = atoi(argv[1]), M = atoi(argv[2]);
    std::cout << "Amount of nodes: N==" << N 
        << " , which node to eliminate each round: M==" 
        << M << std::endl;

    // Create root node
    link t = new node(1,0);

    // Point root node to itself
    t->next = t;

    // x = active element
    link x = t;

    // Create a total of N nodes
    for(i=2; i<=N; i++)
    /* Note:
    new element always point to t (root node with item 1)
    "old x" points to the new element
    then the new element becomes x
    */
        x = (x->next = new node(i, t));

    // Eliminate Mth node until only one is left
    while(x !=x->next)
    {
        for(i=1; i<M; i++) x = x-> next;
        x->next = x->next->next;
    }

    // Print left node
    std::cout << x->item << std::endl;
}