#include "Dog.hpp"

Dog::Dog() : Animal(){
	this->type = "Dog";
	std::cout << BLUE << WBG << "🐩  DOG   🐩" << RESET << BLUE << " Constructor called" << RESET << std::endl;
}

Dog::Dog(Dog const& obj): Animal(){
	*this = obj;
	std::cout << BLUE << WBG << "🐩  DOG   🐩" << RESET << BLUE << " Copy Constructor called" << RESET << std::endl;
}

Dog& Dog::operator=(const Dog &obj){
	if (this != &obj)
		this->type = "Dog";
	return *this;
}

Dog::~Dog(){
	std::cout << BLUE << WBG << "🐩  DOG   🐩" << RESET << BLUE <<" Destroyed"<< RESET << std::endl;
}

void Dog::makeSound(void) const {
	std::cout << this->type << " : *WooofF*" << std::endl;
}