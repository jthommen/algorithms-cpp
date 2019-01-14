/*
###
Program 3.14: Implementation of list-processing interface
###

Description:
Implements interface declared in Program 3.12 and illustrates
a standard approach to allocating memory for fixed-size nodes.
We build a free list that is initilized to the maximum
number of nodes that our program will use, all linked together.
Then, when a client program frees a node, we link that node
in to the free list.
    By convention, client programs do not refer to list nodes
except by declaring variables of type Node and using them as
arguments to functions defined in the interface, and nodes
returned to client programs have self-links.  These conventions
provide a measure of protection against referencing undefined
pointers and provide some assurance that the client is using
the interface as intended.

*/
#include<cstdlib>
#include "list.hpp"

// declare list element
link freelist;

void construct(int N)
{
  // assign node array to freelist
  // returns pointer to first element
  freelist = new node[N+1];

  // build list
  for(int i=0; i < N; i++)
    freelist[i].next = &freelist[i+1];
    // What is the item default value?
  // last element points to 0
  freelist[N].next = 0;
}

// remove elem from free list
// construct struct values
link newNode(int i)
{
  link x = remove(freelist);
  x->item = i;
  x->next = x;
  return x;
}

// Insert back into free list
void deleteNode(link x)
{
  insert(freelist, x);
}

// Insert link t after link x
void insert(link x, link t)
{
  t->next = x->next;
  x->next = t;
}

// Remove the link after x
link remove(link x)
{
  link t = x->next;
  x->next = t->next;
  return t;
}

// Return the link after x
link next(link x)
{
  return x->next;
}

// Get item (int value) from link
Item item(link x)
{
  return x->item;
}