/*
###
Program 3.11: List insertion sort
###

Description:
This code generates N random integers between 0 and 999,
builds a linked list with one number per node (first for loop),
and then rearranges the nodes so that the numbers appear in order
when we traverse the list (second loop). To accomplish the sort,
we maintain two lists, an input (unsorted) list and an output
(sorted) list. On each iteration of the loop, we remove a node
from the input and insert it into position in the output. The 
code is simplified by the use of head nodes for each list,
that contain the links to the first nodes on the lists. The
declarations of the head nodes use the constructor, so that 
their data members are initialized when they are created.

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
    if(argc<1) 
    {
        std::cerr << "Need one command line argument.\n";
        return -1;
    }
    int i,  N = atoi(argv[1]);

    node heada(0,0); link a = &heada, t=a;

    for(i=0; i<N; i++)
        t = (t-> next = new node(rand() % 1000, 0));
    
    node headb(0,0); link u, x, b = &headb;
    for(x = b; x -> next != 0; x = x->next)
        if(x->next->item > t->item) break;
    t->next = x->next; x->next = t;
}