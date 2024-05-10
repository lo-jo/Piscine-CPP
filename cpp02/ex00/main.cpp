#include "Fixed.hpp"

int	main(){
Fixed a; // Default object creation
Fixed b(a); // Copy constructor creation
Fixed c; // Default object creation

c = b; // assignment operator
std::cout << a.getRawBits() << std::endl;
std::cout << b.getRawBits() << std::endl;
std::cout << c.getRawBits() << std::endl;


std::cout << std::endl;
std::cout << YEL << BOLD << "******************************" << RESET << std::endl;
std::cout << BOLD << "****** SOME OTHER TESTS ******" << RESET << std::endl;
std::cout << "** Lets set A to 18" << std::endl;
a.setRawBits(18);
std::cout << a.getRawBits() << std::endl;
std::cout << "** Lets assign A to C" << std::endl;
c = a;
std::cout << c.getRawBits() << std::endl;

std::cout << YEL << BOLD << "******************************" << RESET << std::endl << std::endl;
return 0;
}

