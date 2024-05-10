#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include "lib.hpp"

class Animal{
	public:
	Animal(); //default constructor
	Animal(std::string type);
	Animal(Animal const  &obj);// copy constructor
	virtual ~Animal(); // destructor
	Animal& operator=(const Animal &obj);// copy assignment operator
	
	std::string getType() const;
	virtual void	makeSound() const;

 protected:
	std::string type;
};


#endif