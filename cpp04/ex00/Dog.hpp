#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal{
	public:
	Dog();
	Dog(Dog const &obj);
	virtual ~Dog();

	Dog& operator=(const Dog &obj);
	virtual void makeSound(void) const;

};

#endif