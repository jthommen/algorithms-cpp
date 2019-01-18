/*
###
Program 5.19: Construction of a tournament
###

Description:
The recursive function divides an array a[l], ..., a[r] into
the two parts a[l], ..., a[m], and a[m+1], ..., a[r], builds 
tournaments for the two parts (recursively), and makes a tour-
nament for the whole array by setting links in a new node to 
the recursively built tournaments and setting its item value
to the larger of the items in the roots of the two recursively
built tournaments.

*/

template<typename Item>
struct node 
{
  Item item;
  node* l, * r;
  node(Item x): item{x}, l{0}, r{0} { };
};

typedef node* link;

template<typename Item>
link max(Item a[], int l, int r)
{
  int m = (l+r)/2;
  link x = new node(a[m]);
  if(l == r) return x;
  x->l = max(a, l, m);
  x->r = max(a, m+1, r);
  Item u = x->l->item;
  Item v = x->r->item;
  if(u > v)
    x->item = u; else x->item = v;
  return x;
}