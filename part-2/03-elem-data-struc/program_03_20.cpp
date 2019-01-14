/*
###
Program 3.20: A two-dimensional array of lists
###

Description:
This program illustrates the effectiveness of proper
data-structure choice, for the geometric computation
of Program 3.8. It divides the unit square into a grid,
and maintains a two-dimensional array of linked lists,
with one list corresponding to each grid square. The grid
is choosen to be sufficently fine that all points within
distance d of any given point are either in the same square
or an adjancent one. 

*/

#include<cmath>
#include<iostream>
#include<cstdlib>
#include "Point.hpp"

struct node {
  point p; node* next;
  node(point pt, node* t): p{pt}, next{t} { };
};

typedef node* link;
static link** grid;
static int G, cnt = 0; static float d;

void gridinsert(float x, float y)
{
  int X = x*G+1; int Y = y*G+1;
  point p; p.x = x; p.y = y;
  link s, t = new node(p, grid[X][Y]);
  for(int i=X-1; i<=X+1; i++)
    for(int j=Y-1; j<=Y+1; j++)
      for(s = grid[i][j]; s != 0; s = s->next)
        if(distance(s->p, t->p) < d) cnt++;
  grid[X][Y] = t;
}

float randFloat()
{ return 1.0*rand()/RAND_MAX; }

link** malloc2d(int r, int c)
{
  link** t = new link* [r];
  for(int i=0; i < r; i++)
    t[i] = new link[c];
  return t;
}

int main(int argc, char* argv[])
{
  int i, N = atoi(argv[1]);
  d = atof(argv[2]); G = 1/d;
  grid = malloc2d(G+2, G+2);
  for(i=0; i < G+2; i++)
    for(int j=0; j < G+2; j++)
      grid[i][j]=0;
    for(i=0; i < N; i++)
      gridinsert(randFloat(), randFloat());
    std::cout << cnt << " pairs within " << d << std::endl;
}