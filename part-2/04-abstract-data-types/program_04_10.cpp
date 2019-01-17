/*
###
Program 4.10: Equivalence-relations ADT client
###

Description:
The ADT of Program 4.11 (unionfind.cpp) separates
the connectivity algorithm from the union-find
implementation, making the algorithm more accessible.

*/

#include<iostream>
#include<cstdlib>
#include "../../lib/unionfind.cpp"

int main(int argc, char* argv[])
{
  int p, q, N = atoi(argv[1]);
  unionfind info(N);
  while(std::cin >> p >> q)
  {
    if(!info.find(p, q))
    {
      info.unite(p, q);
      std::cout << " " << p << " " << q << std::endl;
    }
  }
}
