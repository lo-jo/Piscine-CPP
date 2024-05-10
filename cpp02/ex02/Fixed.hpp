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
	Fixed(); 
	Fixed(const Fixed& object);// copy constructor
	Fixed(const int nb); // constructor to convert param to fixed point
	Fixed(float const nb); // constructor to convert param to fixed point
	~Fixed(); // destructor
	Fixed &operator=(const Fixed& copy);// copy assignment operator overload

	int		getRawBits() const;// returns the raw value of the nbVal
	void	setRawBits(int const raw); // sets the raw value of the fixed point number
	float	toFloat() const;
	int		toInt() const;
	/* COMPARISON OPERATORS */
	bool operator==(const Fixed& Fixed) const;
	bool operator!=(const Fixed& Fixed) const;
	bool operator<(const Fixed& Fixed) const;
	bool operator>(const Fixed& Fixed) const;
	bool operator>=(const Fixed& Fixed) const;
	bool operator<=(const Fixed& Fixed) const;

	/* ARITHMETIC OPERATORS */
	Fixed operator+(const Fixed &obj);
	Fixed operator-(const Fixed &obj);
	Fixed operator*(const Fixed &obj);
	Fixed operator/(const Fixed &obj);
	
	/*INCREMENT DECREMENT OPERATORS*/
	Fixed &operator++();   // pre increment ++a
	Fixed &operator--();   // pre decrement --a
	Fixed operator++(int); // post increment a++
	Fixed operator--(int);  // post decrement a--;

	static Fixed &min(Fixed &a, Fixed &b); /* returns smallest fixed */
	static const Fixed &min(const Fixed &a, const Fixed &b); /* returns smallest ref */
	static Fixed &max(Fixed &a, Fixed &b); /* returns greatest fixed */
	static const Fixed &max(const Fixed &a, const Fixed &b); /* returns greates ref */



	private:
	int	fixVal; // Value of the fixed point number
	static const int fixFract = 8; // nbr of fractional bits, will always be 8
};


/* Stream extraction and insertion
* The overloads of operator >> and operator<< 
* that take a std::istream& or std::ostream&
* as the left hand argument are known as 
* insertion and extraction operators. 
* Since they take the user-defined type as 
* the right argument (b in a @ b), they must be implemented as non-members.
*/
std::ostream& operator<<(std::ostream& out, Fixed const& fixed);
#endif