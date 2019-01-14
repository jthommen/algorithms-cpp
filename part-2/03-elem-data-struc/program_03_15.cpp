/*
###
Program 3.15: String search
###

Description:
This program discovers all occurences of a word from
the command line in a (presumably much larger) text
string. We declare the text string as a fixed-size
character array (we could also use new[]) and read it 
from the standard input, using cin.get(). Memory for the
word from the command line-argument is allocated by the
system before this program is invoked, and we find the
string pointer in argv[1]. For each starting position
i in a, we try matching the substring starting at that
position with p, testing for equality character by character.
Whenever we reach the end of p successfully, we print
out the starting position i of the occurence of the word
in the text.

*/

#include <iostream>
#include <cstring>

static const int N = 10000;

int main(int argc, char* argv[])
{
  int i;
  char t;
  char a[N], *p = argv[1];

  // Save cin input in A
  for(i=0; i < N-1; a[i] = t, i++)
    if(!std::cin.get(t)) break;
  
  // Add 0 terminating char
  a[i] = 0;
  
  // Loop over characters ina
  for(i=0; a[i] != 0; i++)
  {
    int j;

    // For every character see if it 
    // matches with search string p
    for(j=0; p[j] != 0; j++)
      if(a[i+j] != p[j]) break;
    
    if(p[j] == 0) std::cout << i << " ";
  }

  std::cout << std::endl;
}