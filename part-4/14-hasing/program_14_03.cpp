/*
###
Program 14.3: Hashing with separate chaining
###

Description:
This symbol-table representation is based on replacing the ST
constructor, search, and insert functiosn in the linked-list-based
symbol table with the functions given here, and replacing the link
head with an array of link heads. We use the same recursive list search
and deletion procedures, but we maintain M lists, with head links in heads,
using a hash function to choose among the lists.
The constructor sets M such that we expect the lists to have about five
items each; therefore the other operatiosn require just a few probes.

Properties:
- Approximate chance of having collisions to 1/M by using pseudorandom sequence

*/

template<typename Item, typename Key>
class SymbolTable
{
    private:
        Item nullItem;
        struct node 
        {
            Item item;
            node* next;
            node(Item x, node* t): item{x}, next{t} { };
        };

        typedef node* link;
        int N, M; // hash table specific
        link* heads; // hash table specific

        // universal hashing function (string)
        int hash(char* v, int M)
        {
            int h, a = 31415, b = 27183;
            for(h=0; *v != 0; v++, a = a*b % (M-1))
                h = (a*h + *v) % M;
            return (h < 0) ? (h + M) : h;
        }

        Item searchR(link t, Key v)
        {
            if(t == 0) return nullItem;
            if(t->item.key() == v) return t->item;
            return searchR(t->next, v);
        }
    public:
        SymbolTable(int maxN): heads{new link[M]}, N{0}, M{maxN/5}
        // hash table specific, initialize head nodes
        { for(int i=0; i<M; i++) heads[i] = 0; };

        int count() { return N; }

        Item search(Key v)
        { return searchR(heads[hash(v, M)], v); } // hash table specific

        void insert(Item x)
        // hash table specific
        {   
            int i = hash(item.key(), M);
            heads[i] = new node(x, heads[i]); N++;
        }
};
