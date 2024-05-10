#include "Fixed.hpp"

int	main(){
Fixed a; // Default object creation
Fixed const b(10); // int constructor
Fixed const c(42.42f); // float constructor
Fixed const d(b); // copy constructor

a = Fixed(1234.4321f);

std::cout << "representation of a (float 1234.4321f) is " << a << std::endl;
std::cout << "Same output can be achieved calling the tofloat() method: " << a.toFloat() << std::endl;
std::cout << "representation of b (int) is " << b << std::endl;
std::cout << "representation of c (float 42.42f) is " << c << std::endl;
std::cout << "representation of d (copy of b) is " << d << std::endl;

std::cout << "a is " << a.toInt() << " as integer" << std::endl;
std::cout << "b is " << b.toInt() << " as integer" << std::endl;
std::cout << "c is " << c.toInt() << " as integer" << std::endl;
std::cout << "d is " << d.toInt() << " as integer" << std::endl;
return 0;
}

