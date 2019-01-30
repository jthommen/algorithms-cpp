/*
###
Program 13.2-4: Randomized BST
###

Description:
Update from program_12_08 (itself consisting of 12.8 & 12.9 & 12.12-12.17)

Insert - Makes a randomized decision whether to use the root insertion
method or the standard insertion method. In a random BST, each of the nodes
is at the root with equal probability; so we get random trees by putting
a new node at the root of a tree of size N with probability 1/(N+1).

Join - Makes a randomized, rather than arbitrary, decision about which
node to use for the root in a combined tree, using probabilities that
ensure that each node is equally likely to be the root. The private
member function fixN updates b->N to be 1 plus the sum of the corresponding
fields in the subtrees (0 for null trees).

Delete - Makes randomized, rather than arbitrary, decision about whether
to replace the deleted node with the predecessor or the successor, using
probabilities that ensure that each node in the resulting tree is equally
likely to be the root. To properly maintain the node counts, we also need
to include a call to fixN for h as the last statement in removeR.

Properties:
- Building a randomized BST is equivlent to building a standard BST from
a random initial permutation of keys. We use about 2N Ln N comparisons
to construct a randomized BST with N items (no matter in what order the
items are presented for insertion), and about 2N ln N comparisons for 
search in such a tree.
- The probability that the construction cost of a randomized BST is more
than a factor of a times the average is less than e^-a. 

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
        int N; // number of nodes in that nodes subtree
        
        node(Item x): item{x}, l{0}, r{0}, N{0} { };
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

    // Insert Random
    void InsertR(link& h, Item x)
    {
        // Empty node, insert new 
        if(h==0) { h = new Node(x), return; }

        // introduce randomization
        if(rand() < RAND_MAX/(h->N+1))
        { insertT(h, x); return; } // root insertion

        // If key is smaller, go left
        if(x.key() < h->item.key())
            return insertR(h->l, x);
        // go right otherwise
        else return insertR(h->r, x);
        
        h->N++; // Update element
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

    // random version
    link joinLR(link a, link b)
    {   if(a == 0) return b;
        if(b == 0) return a;
        if(rand() / (RAND_MAX/(a->N+b->N)+1) < a->N)
        {
            a->r = joinLR(a->r, b);
            return a;
        }
        else
        {
            b->l = joinLR(a, b->l);
            return b;
        }
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
        fixN(h);
    }

    // Join with random decision for new root
    link joinR(link a, link b)
    {
        if(b==0) return a;
        if(a==0) return b;
        insertR(b, a->item);
        b->l = joinR(a->l, b->l);
        b->r = joinR(a->r, b->r);
        delete a;
        fixN(b); // Not implemented!
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
    void join(ST<Item, Key>& b)
    { 
        int N = head->N;
        if(rand() / (RAND_MAX / (N+b.head->N)+1) < N)
            head = joinR(head, b.head);
        else head = joinR(b.head, head);
    }
};
