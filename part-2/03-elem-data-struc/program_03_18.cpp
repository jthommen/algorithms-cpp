/*
###
Program 3.18: Adjacency-matrix graph representation
###

Description:
This program reads a set of edges that define an
undirected graph and builds an adjacency-matrix
representation for the graph, setting a[i][j] and
a[j][i] to 1 if there is an edge from i to j or j to
in the graph, or to 0 if there is no such edge.
The program assumes that the number of vertices V
is a compile-time constant. Otherwise, it would need
to dynamically, allocate the array that reprsents
the adjacency matrix.

*/

#include<iostream>

int main()
{
  const int V = 10; 
  int i, j, adj[V][V];

  // Initialize all elements to o
  for(i=0; i < V; i++)
    for(j=0; j < V; j++)
      adj[i][j] = 0;

  // Set selfreference to 1
  for(i=0; i < V; i++) adj[i][i] = 1;

  // Get input pairs and set connections
  while(std::cin >> i >> j)
  {
    adj[i][j] = 1; adj[j][i] = 1;
  }
}