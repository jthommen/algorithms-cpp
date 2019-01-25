/*
###
Program 12.4: Key-indexed array-based symbol table
###

Description:
This code assumes that key values are positive integers less than
a sentinel value M, and uses them as indices into an array. We use the
convention that the Item constructor creates items with key values equal
to the sentinel value, so that the SymbolTable constructor can find the
value of M in a null item. The primary costs to watch are:
- The amount of space requried when the sentinel is large
- The amount of time required for the SymbolTable constructor when N
is small, relative to M.

Properties:
If key values are positive integers less than M and items
have distinct keys, then the symbol-table data type can be
implemented with key-indexed arrays of items such that insert,
search, and remove require constant time;
initialize, select and sort require time proportional to M, 
whenever any of the operations are performed on an N-item table.

*/

template<typename Item, typename Key>
class SymbolTable
{
    private:
        Item nullItem, * st;
        int M;
    public:
        SymbolTable(int maxN): M{nullItem.key()}, st{new Item[maxN]} { };

        int count()
        {
            int N = 0;
            for(int i=0; i<M; i++)
                if(!st[i].null()) N++;
            return N;
        }

        void insert(Item x) { st[x.key()] = x; }

        Item search(Key v) { return st[v]; }

        void remove(Item x) { st[x.key()] = nullItem; }

        Item select(int k)
        {
            for(int i=0; i<M; i++)
                if(!st[i].null())
                    if(k-- == 0) return st[i]; // Returns n-th item?
            return nullItem;
        }

        void show(std::ostream& os)
        {
            for(int i=0; i < M; i++)
                if(!st[i].null()) st[i].show(os);
        }
};
