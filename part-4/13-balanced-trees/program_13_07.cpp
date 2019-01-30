/*
###
Program 13.7 - 13.10: Skip List
###

Description:

data structure & constructor - Nodes in skip lists have an
an array of links, so the constructor for node needs to 
allocate the array and to set all the link to 0. The constant
lgNmax is the maximum number of levels that we will allow in the list:
It might be set to five for tiny lists, or to 30 for huge lists.
The variable N keeps the number of items in the list, as usual,
and lgN is the number of levels. An empty list is a head node with
lgNmax links, all set to 0, with N and lgN also set to 0.

search - For k equal to 0, this code is equal to
searching in singly linked lists. For general k, we
move to the next node in the list on level k if its key
is smaller than the search key, and down to level k-1
if its key is not smaller.

insertion - We generate a new j-link node with probability 2/2^j,
then follow the search path precisely as in the search path, but
link in the new node when we move down to each of the bottom j levels.

removal - To remove a node with a given key from a skip list, we unlink it
at each level that we find a link to it, then delete it when we reach
the bottom level.

Properties:


*/

#include<iostream>

template<typename Item, typename Key>
class ST
{
private:
    struct node
    {
        Item item;
        node** next;
        int sz;
        node(Item x, int k): item{x}, sz{k}, next{new node*[k]}
        {
            for(int i=0; i<k; i++) next[i] = 0;
        }
    };
    typedef node* link;
    link head;
    Item nullItem;
    int lgN;

    Item searchR(link t, Key v, int k)
    {
        if(t == 0) return nullItem;
        if(v == t->item.key()) return t->item;
        link x = t->next[k];
        if( (x == 0) || (v < x->item.key()))
        {
            if(k == 0) return nullItem;
            return searchR(t, v, k-1);
        }
        return searchR(x, v, k);
    }

    int randX()
    {
        int i, j, t = rand();
        for(i=1, j=2; i< lgNmax; i++, j+=j)
            if(t > RAND_MAX/j) break;
        if(i > lgN) lgN = i;
        return i;
    }

    void insertR(link t, link x, int k)
    {
        Key v = x->item.key();
        link tk = t->next[k];
        if( (tk == 0) || (v < tk->item.key()))
        {
            if(k < x->sz)
            { 
                x->next[k] = tk;
                t->next[k] = x;
            }
            if(k == 0) return;
            insertR(t, x, k-1) return;
        }
        insertR(tk, x, k);
    }

    void removeR(link t, link x, int k)
    {
        link x = t -> next[k];
        if(!(x->item.key() < v))
        {
            if(v == x->item.key())
            { t->next[k] = x->next[k]; }
            if(k == 0)
            { delete x; return; }
        }
        removeR(t->next[k], v, k);
    }

public:
    ST(int): head{new node(nullItem, lgNmax)}, lgN{0} { };
    Item search(Key v) { return searchR(head, v, lgN); }
    void insert(Item v) { insertR(head, new node(v, randX()), lgN); }
    void remove(Item x) { removeR(head, x.key(), lgN); }
};
