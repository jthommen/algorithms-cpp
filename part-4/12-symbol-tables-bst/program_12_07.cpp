/*
###
Program 12.7: Binary search (for array-based symbol table)
###

Description:
This implementation of search uses a recursive binary-search
procedure. To find whether a given key v is in an ordered array,
it first compares v with the element at the middle position. If
v is smaller, then it must be in the first half of the array; if
v is greater, then it must be in the second half of the array.
    The array must be in sorted order. We could include a symbol-
table constructor that takes an array an argument, then builds
a symbol table from items in the argument array and uses a standard
sort routine to prepare it for searching.

Properties:
- Search in lg N
- input must be sorted

*/

private:
    Item searchR(int l, int r, Key v)
    {
        if(l>r) return nullItem;
        int m = (l+r)/2;
        if(v == st[m].key()) return st[m];
        if(l == r) return nullItem;
        if(v < st[m].key())
            return searchR(l, m-1, v);
        else return searchR(m+1, r, v);
    }

public:
    Item search(Key v)
    {
        return searchR(0, N-1, v);
    }
