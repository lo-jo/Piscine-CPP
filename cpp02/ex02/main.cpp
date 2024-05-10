#include "Fixed.hpp"

int	main(){
Fixed a;;
Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

std::cout << a << std::endl;
std::cout << ++a << std::endl;
std::cout << a << std::endl;
std::cout << a++ << std::endl;
std::cout << a << std::endl;
std::cout << b << std::endl;
std::cout << Fixed::max( a, b ) << std::endl;

std::cout << std::endl << MAG << "******** ARITHMETIC OPERATOR TESTS ********" << RESET << std::endl;
a = 0;
std::cout << YEL << "CASE 1 | a is : " << a <<  RESET<< std::endl;
std::cout << ">> a + 2 = " << (a + 2)  << std::endl;
std::cout << ">> a - 2 = " << (a - 2)  << std::endl;
std::cout << ">> a * 2 = " << (a * 2)  << std::endl;
Fixed d  = 1;
a = 4;
std::cout << YEL << "CASE 2 | a is : " << a << ", d is : " << d << RESET << std::endl;
std::cout << ">> a - d = " << (a - d)  << std::endl;
std::cout << "2 * 2 = " << (2 * 2)  << std::endl;
std::cout << "2 / 2 = " << (2 / 2)  << std::endl;

std::cout << std::endl << MAG << "************* MIN MAX TESTS ***************" << RESET << std::endl;
std::cout << YEL << "CASE 1 | a is set to 300, c to 1." << RESET << std::endl;
a = 300;
Fixed c = 1;
std::cout << "Maximum betweem a & c : " << Fixed::max( a, c ) << std::endl;
std::cout << "Minimum betweem a & c : " << Fixed::min( a, c ) << std::endl;
std::cout << "Maximum betweem b & c (const): " << Fixed::max(b, c) << std::endl;

return 0;
}

