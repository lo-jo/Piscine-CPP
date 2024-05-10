#include "Cat.hpp"

Cat::Cat() : Animal(){
	this->type = "Cat";
	std::cout << MAG << WBG << "🐈  CAT   🐈" << RESET << MAG << " Constructor called" << RESET << std::endl;
}

Cat::Cat(Cat const& obj): Animal(){
	*this = obj;
	std::cout << MAG << WBG << "🐈‍  CAT   🐈‍" << RESET << MAG << " Copy Constructor called" << RESET << std::endl;
}

Cat& Cat::operator=(const Cat &obj){
	if (this != &obj)
		this->type = "Cat";
	return *this;
}

Cat::~Cat(){
		std::cout << MAG << WBG << "🐈‍  CAT   🐈‍" << RESET << MAG <<" Destroyed"<< RESET << std::endl;
}

void Cat::makeSound(void) const {
	std::cout << this->type << " : *MeooooowW*" << std::endl;
}