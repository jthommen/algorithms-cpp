/*
###
Program 3.19: Adjacency-list graph representation
###

Description:
This program reads a set of edges that define a
graph and builds an adjacency-list representation
for the graph. An adjacency list for a graph is
an array of lists, one for each vertex, where the 
jth llist contains a linked list of the nodes connected
to the jth vertex.

*/

#include<iostream>

struct node 
{
  int v; node* next;
  node(int x, node* t): v{x}, next{t} { };
};

typedef node* link;

int main()
{
  // Max number of vertexes
  const int V = 10; 

  // edges from vertexes
  int i, j;

  // Link array holding edges
  link adj[V];

  // Initialize array to 0
  for(i=0; i < V; i++) adj[i] = 0;

  // Get input edges
  while(std::cin >> i >> j)
  {
    // Update lists with edges
    adj[j] = new node(i, adj[j]);
    adj[i] = new node(j, adj[i]);
  }
}