/*
###
Program 4.7: Array implementation of a pushdown stack
###

Properties:
We can implement the push and pop operations for the
pushdown stack ADT in contant time, using either arrays or
linked lists.

*/
/*
template<class Item>
class Stack {
  private:
    Item* s; int N;
  public:
    Stack(int maxN);
    {
      s = new Item[maxN]; N=0;
    }
    int empty() const;
    {
      return N == 0;
    }
    void push(Item item)
    {
      s[N++] = item;
    }
    Item pop()
    {
      return s[--N];
    }
};
*/

/*
###
Program 4.8: Linked-list implementation of a pushdown stack
###

Properties:
We can implement the push and pop operations for the
pushdown stack ADT in contant time, using either arrays or
linked lists.
*/

template<class Item>
class Stack {
  private:
    struct node
    {
      Item item;
      node* next;
      node(Item x, node* t): item{x}, next{t} { };
    };
    typedef node* link;
    link head;
  public:
    Stack(int)
    {
      head = 0;
    }
    int empty() const
    {
      return head == 0;
    }
    void push(Item x)
    {
      head = new node(x, head);
    }
    Item pop()
    {
      Item v = head->item;
      link t = head->next;
      delete head;
      head = t;
      return v;
    }
};
