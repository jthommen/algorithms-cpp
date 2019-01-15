/*
###
Program 4.6: Infix-to-postfix conversion
###

Description:
This program is another example of a pushdown-stack client.
In this case, the stack contains characters. To convert (A+B)
to the postfix form AB+, we ignore the left parenthesis, convert
A to postfix, save the + on the stack, convert B to postfix, then,
on encountering the right parenthesis, pop the stack and output
the +.

Sample Input: (have to escape parenthesis for bash, otherwise the
param gets interpreted as sub-shell command.)
\(5*\(\(\(9+8\)*\(4*6\)+7\)\)

Sample Output: 5 9 8 + 4 6 * 7 + *
*/

#include<iostream>
#include<cstring>
#include "../../lib/stack.cpp"

int main(int argc, char* argv[])
{
  // Get command line args with infix
  char* a = argv[1]; int N = strlen(a);
  std::cout << "Infix: ";
  for(int j=0; j<N;j++)
    std::cout << a[j];
  std::cout << std::endl;

  // Create stack with N max links
  Stack<char> ops(N);

  // Loop over input, push and pop
  // to obtain postfix notation
  std::cout << "Postfix: ";
  for(int i=0; i < N; i++)
  {
    if(a[i] == ')')
      std::cout << ops.pop() << " ";
    if((a[i] == '+') || (a[i] == '*'))
      ops.push(a[i]);
    if((a[i] >= '0') && (a[i] <= '9'))
      std::cout << a[i] << " ";
  }
  std::cout << std::endl;
}
