/*
###
Program 4.19: First-class ADT for complex numbers
###

Description:
This code implements the ADT using floats to represent
the real and imaginary parts of each complex number. It
is a first-class data type because there are no pointers
in the data representation. When we use a Complex object
in an assignment statement or as an argument or a return
value in a function, the system makes a copy by allocating
a new object and copying the data, just as it does for 
built-in types.
  The definition given here for the overloaded operator <<
does not format the output.

*/

#include<iostream>

class Complex 
{
  private:
    float re, im;
  
  public:
    Complex(float x, float y): re{x}, im{y} { };
    float Re() const { return re; }
    float Im() const { return im; }
    Complex& operator*=(const Complex& rhs)
    {
      float t = Re();
      re = Re()*rhs.Re() - Im()*rhs.Im();
      im = t*rhs.Im() + Im()*rhs.Re();
      return *this;
    }
};

std::ostream& operator<<(std::ostream& t, const Complex& c)
{
  t << c.Re() << " " << c.Im();
  return t;
}
