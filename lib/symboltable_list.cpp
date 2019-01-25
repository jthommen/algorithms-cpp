/*
###
Program 12.6: Linked-list based symbol table (unordered)
###

Description:
This implementation of construct, count, search and insert uses a
singly-linked list with each node containing an item with a key and
a link. The insert function puts the new item at the beginning of the
list, and takes constant time. The search member function uses a
private recursive function searchR to scan through the list.
    Since the list is not in order, the sort and select implementations
are omitted.

Properties:


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
        int N;
        link head;
        Item searchR(link t, Key v)
        {
            if(t == 0) return nullItem;
            if(t->item.key() == v) return t->item;
            return searchR(t->next, v);
        }
    public:
        SymbolTable(int maxN): head{0}, N{0} { };

        int count() { return N; }

        Item search(Key v)
        { return searchR(head, v); }

        void insert(Item x)
        { head = new node(x, head); N++; }
};
