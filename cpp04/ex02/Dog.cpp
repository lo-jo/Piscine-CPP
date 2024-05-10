#include "Dog.hpp"

Dog::Dog() : Animal(){
	this->brain = new Brain();
	this->type = "Dog";
	std::cout << BLUE << WBG << "🐩  DOG   🐩" << RESET << BLUE << " Constructor called" << RESET << std::endl;
}

Dog::Dog(Dog const& obj): Animal(), brain(NULL){
	*this = obj;
	std::cout << BLUE << WBG << "🐩  DOG   🐩" << RESET << BLUE << " Copy Constructor called" << RESET << std::endl;
}

Dog& Dog::operator=(const Dog &obj){
	if (this != &obj){
		this->type = "Dog";
		if (this->brain != NULL)
			delete this->brain;
		this->brain = new Brain(*obj.brain);
	}
		
	return *this;
}

Dog::~Dog(){
	delete this->brain;
	std::cout << BLUE << WBG << "🐩  DOG   🐩" << RESET << BLUE <<" Destroyed"<< RESET << std::endl;
}

void Dog::makeSound(void) const {
	std::cout << this->type << " : *WooofF*" << std::endl;
}