/*
###
Program 4.11: Equivalence-relations ADT implementation
###

Description:
The code for the weighted-quick-union code from 
Chapter 1, implementes the interface of Program 4.9,
packaging the code in a form that makes it convenient
for use in other applications. The implementation
overloads the name find in a private member function
that implements the traversal up to the root in the tree.

*/

class unionfind
{
  private:
    int* id, * sz;
    int find(int x)
    {
      while (x != id[x]) x = id[x];
      return x;
    }
  
  public:
    unionfind(int N)
    {
      id = new int[N];
      sz = new int[N];
      for(int i=0; i < N; i++)
      {
        id[i] = i;
        sz[i] = i;
      }
    }
    
    int find(int p, int q)
    {
      return (find(p) == find(q));
    }

    void unite(int p, int q)
    {
      int i = find(p);
      int j = find(q);
      if(i == j) return;
      if(sz[i] < sz[j])
      {
        id[i] = j; sz[j] += sz[i];
      } else {
        id[j] = i; sz[i] += sz[j];
      }
    }
};