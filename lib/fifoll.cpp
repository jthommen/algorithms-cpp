/*
###
Program 4.14: FIFO queue linked-list implementation
###

Description:
The difference beween a FIFO queue and a pushdown stack
is that new items are inserted at the end, rather than the
beginning. Accordingly, this class keeps a pointer tail
to the last node of the list, so that the function put can
add a new node by linking that node to the node referenced
by tail and then updating tail to point to the new node.
The functions queue, get, and empty are all identical to 
their counterparts for the linked-list pushdown-stack
implementation. Since new nodes are always inserted at the
end of the list, the node constructor can set the pointer
field of each new node to be null and needs to have only
one argument
*/

template <class Item>
class queue
{
  private:
    struct node
    {
      Item item;
      node* next;
      node(Item x): item{x}, next{0} { };
    };
    typedef node* link;
    link head, tail;
  
  public:
    queue(int)
    {
      head = 0;
    }
    
    int empty() const
    {
      return head == 0;
    }

    void put(Item x)
    {
      link t = tail;
      tail = new node(x);
      if(head == 0)
        head = tail;
      else t->next = tail;
    }

    Item get()
    {
      Item v = head->item;
      link t = head->next;
      delete head;
      head = t;
      return v;
    }

};