/*
###
Program 4.7: Array implementation of a pushdown stack
###

Properties:
We can implement the push and pop operations for the
pushdown stack ADT in contant time, using either arrays or
linked lists.

*/

template<class Item>
class Stack {

  private:
    Item* s;
    int N;

  public:

    Stack(int maxN)
    {
      s = new Item[maxN]; N=0;
    }

    int empty() const
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
