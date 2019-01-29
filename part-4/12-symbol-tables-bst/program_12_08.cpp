/*
###
Program 12.8 & 12.9 & 12.12-12.17: Binary Search Tree based symbol table
###

Description:
Search & Insert - The search and insert functions in this implementation use the private
recursive functions searchR and insertR that directly mirrorthe recursive
definition of BSTs. Note the use of a reference argument in insertR.
The link head points to the root of the tree.

Sort - An inorder traversal of a BST visits the items in order of their keys.
In this implementation, we use the item member function show to print
the items in order of their keys.

Properties:
- best case: perfectly balanced: log N
- worst case: N nodes on search path
- average case: log N
- Search hits, misses and insertions require about 2 ln N (1.39 lg N) comparisons on average,
in a BST built from N random keys.

*/

#include<iostream>

template<typename Item, typename Key>
class ST
{
private:
    struct node
    {
        Item item;
        node* l, * r;
        
        node(Item x): item{x}, l{0}, r{0} { };
    };

    typedef node* link;
    
    link head;
    Item nullItem;
    
    Item searchR(link h, Key v)
    {
        // Empty node, return not found
        if(h==0) return nullItem;

        Key t = h->item.key();

        // Hit, we found v return item
        if(v == t) return h->item;
        
        // Value is smaller, search tree on the left
        if(v < t) return searchR(h->l, v);

        // value is bigger, search tree on the right
        else return searchR(h->r, v);
    }

    void InsertR(link& h, Item x)
    {
        // Empty node, insert new 
        if(h==0) { h = new Node(x), return; }

        // If key is smaller, go left
        if(x.key() < h->item.key())
            return insertR(h->l, x);
        // go right otherwise
        else return insertR(h->r, x);
    }

    void showR(link h, std::ostream& os)
    {   
        // Reached nullItem, nothing to print
        if(h==0) return;

        // Show smaller items than h first
        showR(h->l, os);

        // Show the root
        h->item.show(os);

        // Show bigger items than h after
        showR(h->r, os);
    }

    void rotR(link& h)
    {
        link x = h->l;
        h->l = x->r;
        x->r = h;
        h = x;
    }

    void rotL(link& h)
    {
        link x = h->r;
        h->r = x->l;
        x->l = h;
        h = x;
    }

    // root insertion
    void insertT(link& h, Item x)
    {
        // Insert at appropriate end node
        if(h==0) {h = new node(x), return; }

        // See if head is bigger or smaller
        // insert left or right and rotate
        if(h.key() < h->item.key())
            { insertT(h->l, x); rotR(h); }
        else{ insertT(h->r, x), rotL(h); }
    }

    // Quick sort based select
    Item selectR(link h, int k)
    {
        if(h==0) return nullitem;
        int t = (h->l == 0) ? 0 : h->l->N; // N?
        if(t>k) return selectR(h->l, k);
        if(t<k) return selectR(h->r, k-t-1);
        return h->item;
    }

    // Partitioning a binary search tree
    void partR(link& h, int k)
    {
        int t = (h->l == 0) ? 0 : h->l->N; // N = count?
        if(t > k) { partR(h->l, k); rotR(h); }
        if(t < k) { partR(h->r, k-t-1); rotL(h); } // Why k-t-1?
    }

    link joinLR(link a, link b)
    {
        if(b == 0) return a;
        partR(b, 0); b->l = a;
        return b;
    }

    void removeR(link& h, Key v)
    {
        if(h==0) return;
        Key w = h->item.key();
        if(v < w) removeR(h->l, v);
        if(v > w) removeL(h->r, v);
        if(v == w)
        {
            link t = h;
            h = joinLR(h->l, h->r);
            delete t;
        }
    }

    link joinR(link a, link b)
    {
        if(b==0) return a;
        if(a==0) return b;
        insertT(b, a->item);
        b->l = joinR(a->l, b->l);
        b->r = joinR(a->r, b->r);
        delete a;
        return b;
    }

public:
    ST(int maxN): head{0} { };
    Item search(key V) { return searchR(head, v); }
    void insert(Item x) { insertR(head, x); }
    void show(std::ostream& os) { showR(head, os); }
    void insert_root(Item item) { insertT(head, item); }
    Item select(int k) { return selectR(head, k); }
    void remove(Item x) { removeR(head, x.key()); }
    void join(ST<Item, Key>& b) { head = joinR(head, b.head); }
};
