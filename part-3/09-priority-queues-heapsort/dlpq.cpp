/*
###
Program 9.8-9.10: Doubly-linked-list priority queue
###

Description:


Properties:
- Insert and remove the maximum operations for the priority queue
abstract data type can be implemented with heap-ordered trees such
that insert requires no more than log N comparisons and remove the max
no more than 2 lg N comparisons, when performed on an N-item queue.
- The change priority, remove and replace the maximum operations for 
the priority queue abstract data type can be implemented with heap-
ordered trees such that no more than 2 lg N comparisons are required
for any operation on an N-item queue.
- Bottom-up heap construction takes linear time

*/

template<typename Item>
class PQ
{
    private:
        struct node
        {
            Item item;
            node* prev, * next;
            node(Item v): item{v}, prev{0}, next{0} { };
        };
        typedef node* link;
        link head, tail;
    
    public:
        typedef node* handle;
        PQ(int = 0): head{new node(0)}, tail{new node(0)} 
        {
            head->prev = tail;
            head->next = tail;
            tail->prev = head;
            tail->next = head;
        };

        int empty() const
        {
            return head->next->next == head;
        }

        handle insert(Item v)
        {
            handle t = new node(v);
            t->next = head->next;
            t->next->prev = t;
            t->prev = head;
            head->next = t;
            return t;
        }

        Item getmax()
        {
            Item max; 
            link x = head->next;
            for(link t = x; t->next != head; t = t->next)
                if(x->item < t->item) x = t;
            max = x->item;
            remove(x);
            return max;
        }

        void change(handle x, Item v)
        {
            x->key = v;
        }

        void remove(handle x)
        {
            x->next->prev = x->prev;
            x->prev->next = x->next;
            delete x;
        }

        void join(PQ<Item>& p)
        {
            tail->prev->next = p.head->next;
            p.head->next->prev = tail->prev;
            head->prev = p.tail;
            p.tail->next = head;
            delete tail;
            delete p.head;
            tail = p.tail;
        }
        
};
