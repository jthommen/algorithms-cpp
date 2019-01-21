/*
###
Program 8.8: Bottom-up Mergesort (List)
###

Description:
Merging - This program merges the list pointed to by a with the list
pointed to by b, with the help of an auxiliary pointer c. The key
comparison in merge includes equality, so that the merge will be stable,
if the b list is considered to follow the a list. For simplicity, we
adopt the convention that all lists end with 0. Other conventions for 
ending the list would work as well. More importantly, we don't use list
head nodes, to avoid proliferation of them. 

Top-down mergesort - This program uses a queue ADT to implement a bottom-
up mergesort. Queue elements are ordered linked lists. After initializing
the queue with lists of length 1, the program simply remoes two lists
from the queue, merges them, and puts the result back on the queue, 
continuing until there is only oen list. This corresponds to a sequence
of passes through all the elements, doubling the length of the ordered
lists on each pass, as in bottom-up mergesort.

Properties:
- Requires about N lg N comparisons to sort any file of N elements.
- Uses extra space proportional to N.
- Stable if the underlying merge is stable
- The resource requirements of mergesort are insensitive to the 
initial order of its input.
- All the merges in each pass of a bottom-up mergesort involve file
sizes that are a power of 2, except possibly the final file size.
- The number of passes in a bottom-up mergesort of N elements is precisely
the number of bits in a binary representation of N (ignoring leading 0 bits).

*/

#include<iostream>
#include<cstdlib>

template<typename Item>
struct node
{
  Item item; node *l, *r; 
  node(Item x): item{x}, l{0}, r{0} { };
};

typedef node* link;

template<typename Item>
void merge(link a, link b)
{
    node dummy(0); link head = &dummy, c = head;
    while((a != 0) && (b != 0))
        if(a->item < b->item)
        {
            c->next = a;
            c = a;
            a = a->next;
        }
        else
        {
            c->next;
            c = b;
            b = b->next;
        }
    c->next = (a==0) ? b : a;
    return head->next;
}

template<typename Item>
void mergesort(link c)
{
    queue<link> Q(max);
    if(t == 0 || t->next == 0) return t;
    for(link u = 0; t!= 0; t = u)
    {
        u = t->next;
        t->next = 0;
        Q.put(t);
    }
    t = Q.get();
    while(!Q.empty())
    {
        Q.put(t);
        t = merge(Q.get(), Q.get());
    }
    return t;
}
