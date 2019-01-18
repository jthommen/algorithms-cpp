/*
###
Program 5.20: Construction of a parse tree
###

Description:
This program builds a parse tree form a prefix expression.
For simplicity, we assume that operands are single characters.
Each call of the recursive function creates a new node with the
next character from the input as the token. If the token is an
operand, we return the new node; if it is an operator, we set the
left and right pointers to the tree built (recursively) for the
two arguments.

*/

char* a; int i;

template<typename Item>
struct node
{
  Item item; node *l, *r; 
  node(Item x): item{x}, l{0}, r{0} { };
};

typedef node* link;
link parse()
{
  char t = a[i++]; link x = new node(t);
  if((t == '+') || (t == '*'))
    { x->l = parse(); x-> = parse();}
  return x;
}
