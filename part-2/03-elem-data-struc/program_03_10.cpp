/*
###
Program 3.10: List reversal
###

Description:
This function reverses the links in a list, returning a pointer
to the final node, which then points to the next-to-final node,
and so forth, with the link in the first node of the original
set to 0, the null pointer. To accomplish this task, we need
to maintain links to three consecutive nodes in the list.

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

link reverse(link x)
{
    link t, y = x, r = 0;
    while(y!=0)
    { t = y-> next; y->next = r; r = y; y = t; }
    return r;
}

int main(int argc, char *argv[])
{
    // Command line arguments check
    if(argc<1) 
    {
        std::cerr << "Need one command line argument.\n";
        return -1;
    }

    int i,  N = atoi(argv[1]);
    std::cout << "Amount of nodes: N==" << N <<  std::endl;

    link t = new node(1,0);
    t->next = t;

    // x = active element
    link x = t;

    for(i=2; i<=N; i++)
        x = (x->next = new node(i, t));

    reverse(x);

}