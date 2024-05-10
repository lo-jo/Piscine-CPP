#include "Fixed.hpp"

/***************** CONSTRUCTORS ***********************/
Fixed::Fixed() : fixVal(0){
	std::cout << YEL << "Default constructor called" << RESET << std::endl;
	return;
} // DEFAULT CONSTRUCTOR

/* ______________ad hoc constructors__________________*/
Fixed::Fixed(Fixed const &object){
	std::cout << MAG << "Copy constructor called"  << RESET << std::endl;
	*this = object;
} // COPY CONSTRUCTOR

//* converts parameter to fixed point value*/
Fixed::Fixed(const int nb){
	std::cout << "Int constructor called" << std::endl;
	this->fixVal = nb << this->fixFract;
} // INT CONSTRUCTOR

Fixed::Fixed(const float nb){
	this->fixVal = roundf(nb * (1 << this->fixFract));// + 0.5f);
	std::cout << "Float constructor called" << std::endl;
} //FLOAT CONSTRUCTOR

Fixed& Fixed::operator=(const Fixed& object){
	std::cout << RED << "Assignment operator constructor called"<< RESET << std::endl;
	if (this == &object){ // Check for self-assignment
		return *this;
	}
	this->fixVal = object.getRawBits();
	return *this;
} // ASSIGNMENT CONSTRUCTOR

/***************** DESTRUCTOR ***********************/
Fixed::~Fixed(){ 
	std::cout << GREEN << "Destructor called" << RESET << std::endl;
}

/***************** MEMBER FUNCTIONS ***********************/
/* Gets value from the private attribute of the class*/
int Fixed::getRawBits() const{
	return this->fixVal;
}

void Fixed::setRawBits(int const raw){
	this->fixVal = raw;
	return;
}

/* static_cast can be used to convert between compatible numeric types,
* such as int to float, double to int, etc.
* To convert the fixed value to floating value,
* just return the fixed value divided by the scale factor
* in our case it is 1 leftshifted to 8 (fixFract)*/
float Fixed::toFloat() const{
	return static_cast<float>(this->fixVal) / (1 << this->fixFract);
}

int	Fixed::toInt() const{
	return (this->fixVal >> this->fixFract);
}

/***************** OPERATOR OVERLOADERS *************/

std::ostream& operator<<(std::ostream& out, Fixed const& fixed){
	out << fixed.toFloat();
	return out;
}