/*
###
Program 13.6 Insertion in red-black BSTs
###

Description:
Implements insertion in 2-3-4 trees using red-black 
representation. We add a color bit red to the type node
(and extend its constructor accordingly), with 1 signifiying
that the node is red, and 0 signifying that it is black.
On the way down the tree (before the recursive call),
we check for 4-nodes, and split them by flipping the color
bits in all three nodes. When we reach the bottom, we create
a new red node for the item to be inserted and return a pointer
to it. On the way up the tree (after the recursive call), we
check wheter a rotation is needed. If the search path has
two red links with the same orientation, we do a single rotation
from the top node, then flip the color bits to make a proper 4-node.
If the earch path has two red links with different orientations,
we do asingle rotation from the bottom node, reducing to the other
case for the next step up.

Properties:


*/

#include<iostream>

template<typename Item, typename Key>
class ST
{
private:
    int red(link x)
    { if(x == 0) return 0; return x-> red; }

    void RBinsert(link& h, Item x, int sw)
    {
        if(h == 0) { h = new node(x); return; }
        if(red(h->l) && red(h->r))
        {
            h->red = 1;
            h->l->red = 0;
            h->r->red = 0;
        }
        if(x.key() < h->item.key())
        {
            RBinsert(h->l, x, 0);
            if(red(h) && red(h->l) && sw) rotR(h);
            if(red(h->l) && red(h->l->l))
            { rotR(h); h->red = 0; h->r->red = 1;}
        }
        else
        {
            RBinsert(h->r, x, 1);
            if(red(h) && red(h->r) && !sw) rotL(h);
            if(red(h->r) && red(h->r->r))
            { rotL(h); h->red=0; h->l->red = 1; }
        }
        
    }

public:
    void insert(Item x) { RBinsert(head, x, 0); head->red=0; }
};
