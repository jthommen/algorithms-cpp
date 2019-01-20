/*
###
Program 6.16: Selection Sort (Linked-List)
###

Description:
Selection sort of a linked list is straightforward,
but differs slightly from the array version because it is 
easier to insert at the front of a list. We maintain an input
list (pointed to by h->next), and an output list (pointed to
by out). While it is nonempty, we scan the input list to find the 
maximum remaining element, then remove that element from the
input list and insert it at the front of the output list. This
implementation uses an auxilary routine findmax, which returns a
link to the node whose link points to the maximum element on a list.


*/

#include<iostream>
#include<cstdlib>


// Data, index, data size
template<typename Item>
void listselection(link h)
{
  node dummy(0); 
  link head = &dummy, out = 0;
  head->next = h;
  while(head->next != 0)
  {
    link max = findmax(head);
    link t = max->next;
    max->next = t->next;
    t->next = out;
    out = t;
  }
  return out;
}
