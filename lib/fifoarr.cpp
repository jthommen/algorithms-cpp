/*
###
Program 4.15: FIFO queue array implementation
###

Description:
The contents of the queue are all the elements in
the array between head and tail, taking into account
the wraparound back to 0 when the end of the array is
encountered. If head and tail are equal, then we consider
the queue to be empty; but if put would make them equal, 
then we consider it to be full. As usual, we do not check
such error conditions, but we make the size of the array
1 greater than the maximum number of elements that the
client expects to see in the queue, so that we could
augment this program to make such checks.
*/

template <class Item>
class queue
{
  private:
    Item* q;
    int N, head, tail;
  
  public:
    queue(int maxN)
    {
      q = new Item[maxN+1];
      N = maxN+1; head = N; tail = 0;
    }

    int empty() const
    {
      return head % N == tail;
    }

    void put(Item item)
    {
      q[tail++] = item;
      tail = tail % N;
    }

    Item get()
    {
      head = head % N;
      return q[head++];
    }
};