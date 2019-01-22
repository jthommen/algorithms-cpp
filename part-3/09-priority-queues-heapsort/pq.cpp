/*
###
Program 9.5: Heap-based Priority Queue (Array)
###

Description:
To implement insert, we increment N by 1, add the new element
at the end of the heap, then use fixUp to restore the heap
condition. For getmax, the size of the heap has to decrease by 1,
so we take the value to be returned from pq[1], then reduce the
size of the heap by moving pq[N] to pq[1] and using fixDown to
restore the heap condition. The implementations of the constructor
and empty are trivial.
The first position in the array, pq[0], 
is not used, but may be available as a sentinel for some
implementations. 

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
void exch(Item& A, Item& B)
{
    Item t = A; A = B; B = t;
}

template<typename Item>
void fixUp(Item a[], int k)
/*  To restore the heap condition when a node's priority is
    increased, we move up the heap, exchanging the node at
    position k with it's parent (at position k/2) if necessary,
    continuing as long as a[k/2] < a[k] or until we reach
    the top of the heap.
*/
{
    while(k > 1 && a[k/2] < a[k])
    {
        exch(a[k], a[k/2]);
        k = k/2;
    }
}

template<typename Item>
void fixDown(Item a[], int k, int N)
/*  To restore heap condition when a node's priority is decreased,
    we move down the heap, exchanging the node at position k with
    the larger of that node's children if necessary and stopping
    when the node at k is not smaller than either child or the 
    bottom is reached. Note that if N is even and k is N/2, then the
    node at k has only one child.
    The inner loop in this program has two distinct exits: one for 
    the case that the bottom of the heap is hit, and another for
    the case that the heap condition is satisfied somewhere in
    the interior of the heap. It is a prototypical example of the
    need for the break statement.
*/
{
    while(2*k <= N)
    {
        int j = 2*k;
        if(j < N && a[j] < a[j+1]) j++;
        if(!(a[k] < a[j])) break;
        exch(a[k], a[j]);
        k = j;
    }
}

template<typename Item>
class PQ
{
    private:
        Item* pq;
        int N;
    
    public:
        PQ(int maxN): pq{new Item[maxN+1]}, N{0} { };
        
        int empty() const { return N == 0; }
        
        void insert(Item item)
        {
            pq[++N] = item;
            fixUp(pq, N);
        }

        Item getmax()
        {
            exch(pq[1], pq[N]);
            fixDown(pq, 1, N-1);
            return pq[N--];
        }
};