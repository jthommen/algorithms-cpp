/*
###
Program 12.1: Sample implementation for item ADT

Description:
This class definition for items that are small records
consisting of integer keys and associated floating-point information
illustrates our basic conventions for symbol-table items.
Our symbol-table implementatiosn are client programs that use the 
operators == and < to compare keys, and the member functions key()
and null() to access keys and test whether items are null,
respectively.
    We also include  the functiosn scan (read an Item), rand
(generate a random Item), and show (print an Item) in item type
definitions for use by drivers. This arrangement gives us the flexibility
to implement and test various symbol-table implementations on various types
of items.

*/

#include<cstdlib>
#include<iostream>

static int maxKey = 1000;
typedef int Key;

class Item
{
    private:
        Key keyval;
        float info;
    
    public:
        Item(): keyval{maxKey} { };
        
        Key key() { return keyval; }
        
        int null() { return keyval == maxKey; }
        
        void rand()
        {
            keyval = 1000*rand()/RAND_MAX;
            info = 1.0*rand()/RAND_MAX;
        }

        int scan(std::istream& is = std::cin)
        {
            return (is >> keyval >> info) != 0;
        }

        void show(std::ostream& os = std::cout)
        {
            os << keyval << " " << info << std::endl;
        }
};

std::ostream& operator<<(std::ostream& os, Item& x)
{
    x.show(os);
    return(os);
}