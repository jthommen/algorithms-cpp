/*
###
Program 4.16: Stack with index items and no duplicates
###

Description:
This pushdown-stack implementation assumes that Item
has an int cast that returns integers beween 0 and maxN-1,
so that it can maintain an array t that has a nonzero
value corresponding to each item in the stack. The array
enables push to test quickly whether its argument is already
on the stack, and to take no action if the test succeeds.
We use only one bit per entry in t, so we could save space
by using characters or bits instead of integers, if desired.

*/

template<class Item>
class Stack {
  private:
    Item* s,* t; Int N;
  public:
    Stack(int maxN);
    {
      s = new Item[maxN]; N=0;
      t = new Item[maxN];
      for(int i=0; i < maxN; i++) t[i]=0;
    }
    
    int empty() const;
    {
      return N == 0;
    }

    void push(Item item)
    {
      // check if item already on the stack
      // to avoid duplicates
      if(t[item] == 1) return;
      s[N++] = item;
      t[N++] = 1;
    }

    Item pop()
    {
      t[s[--N]] = 0;
      return s[N];
    }
};
