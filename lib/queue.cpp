/*
###
Program 4.22: Linked-list implementation of a first class queue
###

Description:
Upgrade of the FIFO queue to be a first-class queue, by adding
a copy constructor, overloaded assignment operator and destructor.


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

    void deletelist()
    {
      for(link t=head; t != 0; head=t)
      {
        t = head->next; 
        delete head;
      }
    }
  public:
    // Normal constructor    
    queue() :head{0} { };

    // Copy constructor
    queue(const queue& rhs) :head{0} { *this = rhs; }

    // Assignment operator
    queue& operator=(const queue& rhs)
    {
      if(this == &rhs) return *this;
      deletelist();
      link t = rhs.head;
      while(t != 0)
      {
        put(t->item);
        t = t->next;
      }
      return *this;
    }

    // Destructor
    ~queue()
    {
      deletelist();
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