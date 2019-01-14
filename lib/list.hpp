/*
###
Program 3.12: List-processing interface
###

Description:
Defines the types of nodes and links, including the operations
we want to perform on them. We declare our own functions for
allocating and freeing memory for list nodes. The function
construct is for the convenience of the implementation. These
definitions allow clients to use Nodes and associated operations
without dependence upon implementation details.

*/


// Alias for type int named Item
typedef int Item;

// Simple struct with one int item and a pointer to another struct
struct node { Item item; node* next; };

// Alias for type poiner to node struct named link
typedef node* link;

// Alias for type link (pointer to node struct) named Node
typedef link Node;

// Interface functions for list operations
void construct(int);
Node newNode(int);
void deleteNode(Node);
void insert(Node, Node);
Node remove(Node);
Node next(Node);
Item item(Node);