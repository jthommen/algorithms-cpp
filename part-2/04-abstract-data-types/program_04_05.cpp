/*
###
Program 4.5: Postfix-expression evaluation
###

Description:
Uses postfix notation to calculate parenthesized arithmetic
expressions.

Sample Input: 598+46*7+*

Sample Output: 2075
*/

#include<iostream>
#include<cstring>
#include "../../lib/stack.cpp"

int main(int argc, char* argv[])
{
  // Get command line args with infix
  char* a = argv[1]; int N = strlen(a);
  std::cout << "Input: ";
  for(int j=0; j<N;j++)
    std::cout << a[j];
  std::cout << std::endl;

  // Create stack with N max links
  Stack<int> save(N);

  // Loop over input, push and pop
  // to obtain postfix notation
  std::cout << "Output: ";
  for(int i=0; i < N; i++) // Not working properly...
  {
    if(a[i] == '+')
    {
      int add = save.pop() + save.pop();
      std::cout << add << std::endl;
      save.push(add);
    }
    if(a[i] == '*')
    {
      int mul = save.pop() * save.pop();
      std::cout << mul << std::endl;
      save.push(mul);
    }
    if((a[i] >= '0') && (a[i] <= '9'))
      save.push(0);
    while((a[i] >= '0') && (a[i] <= '9'))
      save.push(10*save.pop() + (a[i++]-'0'));
  }
  std::cout << save.pop() << std::endl;
}
