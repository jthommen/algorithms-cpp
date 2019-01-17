/*
###
Program 4.20: Queue client program (queue simulation)
###

Description:
The client program simulates a situation where we assign
customers waiting for a service at random to one of M 
service queues, then choose a queue at random (possibly the
same one) and, if it is nonempty, perform the service (remove
a customer form the queue). Each time we perform these operations,
we print out the customer added, the customer served, and the
contents of the queues.
  The code implicitly assumes that queue is a first-class data
type (including copy constructor, overloaded assignment operator
and destructor), here especially the copy semantics in the for
loop are important.

*/

#include<iostream>
#include<cstdlib>
#include "../../lib/queue.cpp"

static const int M = 4;

int main(int argc, char* argv[])
{
  int N = atoi(argv[1]);
  queue<int> queues[M];
  for(int i=0; i < N; i++, std::cout << std::endl)
  {
    int in = rand() % M, out = rand() % M;
    queues[in].put(i);
    std::cout << i << " in ";
    if(!queues[out].empty())
    {
      std::cout << queues[out].get() << " out";
    }
    std::cout << std::endl;
    for(int k=0; k < M; k++, std::cout << std::endl)
    {
      queue<int> q = queues[k];
      std::cout << k << ": ";
      while(!q.empty())
        std::cout << q.get() << " ";
    }
  }
}