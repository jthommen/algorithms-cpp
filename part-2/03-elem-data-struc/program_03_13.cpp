/*
###
Program 3.13: List allocation for the Josephus problem
###

Description:
This program for the Josephus problem is an example
of a client program utilizing the list-processing
primitives declared in Program 3.12 and implemented
in program 3.14.

*/

#include<iostream>
#include<cstdlib>
#include "../../lib/list.hpp"

int main(int argc, char* argv[])
{
  // get command line arguments
  int i, N = atoi(argv[1]), M = atoi(argv[2]);

  // declare Nodes
  Node t, x;

  // allocate free list with max size of nodes
  construct(N);

  // construct list
  // with appropriate item values and links
  for(i = 2, x = newNode(1); i <= N; i++)
  {
    t = newNode(i);
    insert(x, t);
    x = t;
  }

  // travers list while more than 1 element is left
  while(x != next(x)) 
  {
    // jump M steps
    for (i=1; i < M; i++) x = next(x);
    // delete link at position M
    deleteNode(remove(x));
  }

  // print out winner
  std::cout << item(x) << std::endl;
  return 0;

}