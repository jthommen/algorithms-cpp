/*
###
Program 12.5: Array-based symbol table (ordered)
###

Description:
Array based symbol table without relying on keys being small integers.
We keep the array in order when inserting a new item by moving larger items
to make roo, in the same manner as insertion sort. Then, the search function
can scan through the array to look for an item with the specified key, 
returning nullItem when encountering an item with a larger key. The select
and sort functions are trivial, remove is not implemented.

Properties:
- Sequential search in a symbol table with N items uses about N/2 comparisons
for search hits (on the average).


*/

template<typename Item, typename Key>
class SymbolTable
{
    private:
        Item nullItem, * st;
        int N;
    public:
        SymbolTable(int maxN): N{0}, st{new Item[maxN+1]} { };

        int count() { return N; }

        void insert(Item x)
        {
            int i = N++;
            Key v = x.key();

            // Finding the position to place the item
            // stop at first item or when the item is smaller than
            // the one to insert
            while(i > 0 && v < st[i-1].key())
            {
                // Moving keys one to the right
                st[i] = st[i-1];
                i--;
            }
            // place item
            st[i] = x;
        }

        Item search(Key v)
        {
            for(int i=0; i < N; i++)
                if(!(st[i].key() < v)) break;
            if(v == st[i].key()) return st[i];
            return nullItem;
        }

        Item select(int k)
        { return st[k]; }

        void show(std::ostream& os)
        {
           int i = 0;
           while(i < N) st[i++].show(os);
        }
};
