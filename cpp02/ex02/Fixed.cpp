#include "Fixed.hpp"

/***************** CONSTRUCTORS ***********************/

Fixed::Fixed() : fixVal(0){
	return;
} // DEFAULT CONSTRUCTOR

/* ______________ad hoc constructors__________________*/
Fixed::Fixed(const Fixed& object){
	std::cout << MAG << "Copy constructor called"  << RESET << std::endl;
	*this = object;
} // COPY CONSTRUCTOR

//* converts parameter to fixed point value*/
Fixed::Fixed(const int nb){
	this->fixVal = nb << this->fixFract;
} // INT CONSTRUCTOR

Fixed::Fixed(const float nb){
	this->fixVal = roundf(nb * (1 << this->fixFract));// + 0.5f);
} //FLOAT CONSTRUCTOR

Fixed& Fixed::operator=(const Fixed& object){
	if (this == &object){ // Check for self-assignment
		return *this;
	}
	this->fixVal = object.getRawBits();
	return *this;
} // ASSIGNMENT CONSTRUCTOR

/***************** DESTRUCTOR ***********************/
Fixed::~Fixed(){ 
	return ;
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


/* ______COMPARISON OPERATORS_______*/
bool Fixed::operator==(const Fixed& Fixed) const{
	return this->fixVal == Fixed.getRawBits();
}
bool Fixed::operator!=(const Fixed& Fixed) const{
	return this->fixVal != Fixed.getRawBits();
}
bool Fixed::operator<(const Fixed& Fixed) const{
	return this->fixVal < Fixed.getRawBits();
}
bool Fixed::operator>(const Fixed& Fixed) const{
	return this->fixVal > Fixed.getRawBits();
}
bool Fixed::operator>=(const Fixed& Fixed) const{
	return this->fixVal >= Fixed.getRawBits();
}
bool Fixed::operator<=(const Fixed& Fixed) const{
	return this->fixVal <= Fixed.getRawBits();
}

/* ______ARITHMETIC OPERATORS_______ */
Fixed Fixed::operator+(const Fixed& obj){
	return Fixed(this->toFloat() + obj.toFloat());
}
Fixed Fixed::operator-(const Fixed& obj){
	return Fixed(this->toFloat() - obj.toFloat());
}
Fixed Fixed::operator*(const Fixed& obj){
	return Fixed(this->toFloat() * obj.toFloat());
}
Fixed Fixed::operator/(const Fixed& obj){
	return Fixed(this->toFloat() / obj.toFloat());
}

/*INCREMENT DECREMENT OPERATORS*/
Fixed& Fixed::operator++(){   // pre increment ++a
	this->fixVal++;
	return *this;
}

Fixed& Fixed::operator--(){   // pre decrement --a
	this->fixVal--;
	return *this;
}

Fixed Fixed::operator++(int){ // post increment a++
	Fixed tmp(*this);
	this->fixVal++;
	return tmp;
}

Fixed Fixed::operator--(int){ // post decrement a--;
	Fixed tmp = *this;
	this->fixVal--;
	return tmp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
	if (a.getRawBits() < b.getRawBits())
		return a;
	return b;

}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
	if (a.getRawBits() > b.getRawBits())
		return a;
	return b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
	if (a.getRawBits() < b.getRawBits())
		return a;
	return b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
	if (a.getRawBits() > b.getRawBits())
		return a;
	return b;
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