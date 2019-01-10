/*
###
Exercise 3.1: Basic Data Type Sizes
###

Description:
Find the largest and smallest numbers that you can represent with
types int, long int, short int, float, and double in your programming
environment.

*/

#include<iostream>
#include "../../lib/analysis.hpp"



int main()
{
    /*
    Note:
    Basic types in C++ are: int, char, bool, float, and wchar_t
    Datatype modifier are: signed, unsigned, short, long
    */
    std::cout<< "sizeof(int): " << sizeof(int) << " bytes.\n";
    std::cout<< "sizeof(long int): " << sizeof(long int) << " bytes.\n"; 
    std::cout<< "sizeof(short int): " << sizeof(short int) << " bytes.\n";
    std::cout<< "sizeof(float): " << sizeof(float) << " bytes.\n";
    std::cout<< "sizeof(double): " << sizeof(double) << " bytes.\n";

    // optional:
    std::cout<< "sizeof(bool): " << sizeof(bool) << " byte(s).\n";
    std::cout<< "sizeof(char): " << sizeof(char) << " byte(s).\n";
    std::cout<< "sizeof(long long int): " << sizeof(long long int) << " byte(s).\n";

    /*
    Value ranges

    unsigned:
    1 byte: 0 to 255
    2 bytes: 0 to 65'535
    4 bytes: 0 to 4'294'967'265
    8 bytes: 0 to 18'446'744'073'709'551'615

    signed:
    1 byte: -128 t0 127
    2 bytes: -32'768 to 32'767
    4 bytes: -2'147'483'648 to 2'147'483'647
    8 bytes: -9'223'372'036'854'775'808 to 9'223'372'036'854'775'807
    */

}
