/*
###
Program 14.6: Double hashing
###

Description:
Using two hashing functions in a list-based symbol ADT.
Double hashing is the same as linear probing except
that we use a second hash function to determine the 
search increment to use after each collision. The search
increment must be nonzero, and the table size and the
search increment should be relatively prime. The remove
function for linear probing doesn't work with double
hashing, because any key might be in many different
probe sequences. (Placeholder use should work?)

Properties:
- Expected number of probes in a half full table (1/2)
equals 1.4 for search hit and 1.5 for search miss
- Expected number of probes in a nearly full table (9/10)
equals 2.6 for search hit and 5.5 for search miss
- Probing will reach infinity when table load is 1

*/

inline hash(Key v, int M)
// Using the golden ratio
{ return (int) (.618033 * (float) v) % M; }

// Simple second hashing function
inline int hashtwo(Key v)
{ return (v % 97)+1; }

void insert(Item item)
{
    key v = item.key();
    int i = hash(v, M), k = hashtwo(v, M);
    while(!st[i].null()) i = (i+k) % M;
    st[i] = item;
    N++;
}

Item search(Key v)
{
    key v = item.key();
    int i = hash(v, M), k = hashtwo(v, M);
    while(!st[i].null())
        if(v==st[i].key()) return st[i];
        else i = (i+k) % M;
    return nullItem;
}