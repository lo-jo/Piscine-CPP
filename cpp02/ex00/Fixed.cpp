#include "Fixed.hpp"

Fixed::Fixed() : fixVal(0){
	std::cout << YEL << "Default constructor called" << RESET << std::endl;
	return;
} // default constructor, initialises fixed point nb val to 0

Fixed::Fixed(const Fixed& object){ 
	std::cout << MAG << "Copy constructor called"  << RESET << std::endl;
	*this = object;
}

Fixed::~Fixed(){ // destructor
	std::cout << GREEN << "Destructor called" << RESET << std::endl;
}

Fixed& Fixed::operator=(const Fixed& object){
	std::cout << RED << "Copy Assignment operator called"<< RESET << std::endl;
	// Check for self-assignment
	if (this == &object){
		return *this;
	}
	// Copies member variables from source object to the current object
	this->fixVal = object.getRawBits();
	// Returns a reference to the current object
	return *this;
}

/* Gets value from the private attribute of the class*/
int Fixed::getRawBits() const{
	std::cout <<"GetRawBits() function called" << std::endl;
	return this->fixVal;
}

void Fixed::setRawBits(int const raw){
	std::cout <<"SetRawBits() function called" << std::endl;
	this->fixVal = raw;
	return;
}
