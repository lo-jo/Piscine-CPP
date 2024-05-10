#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

// ANSI COLORS
#define WBG "\x1B[47m"
#define RESET "\x1B[0m"
#define BOLD "\x1B[1m"
#define MAG "\x1B[35m"
#define YEL "\x1B[33m"
#define RED "\x1B[31m"
#define GREEN "\e[0;32m"

/* ORTHODOx CANONICAL FORM :
* - default constructor
* - copy constructor
* - assignment operator
* - destructor 
*/

class Fixed{
	public:
	Fixed(); // default constructor, initialises fixed point nb val to 0
	Fixed(const Fixed& object);// copy constructor
	Fixed& operator=(const Fixed& copy);// copy assignment operator overload
	~Fixed(); // destructor

	int getRawBits() const; // rturns the raw value of the nbVal
	void setRawBits(int const raw); // sets the raw value of the fixed point number
	
	private:
	int	fixVal; // Value of the fixed point number
	static const int fixFract = 8; // nbr of fractional bits, will always be 8
};



#endif