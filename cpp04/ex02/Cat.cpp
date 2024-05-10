#include "Cat.hpp"

Cat::Cat() : Animal(){
	this->brain = new Brain();
	this->type = "Cat";
	std::cout << MAG << WBG << "🐈  CAT   🐈" << RESET << MAG << " Constructor called" << RESET << std::endl;
}

Cat::Cat(Cat const& obj): Animal(), brain(NULL){
	*this = obj;
	std::cout << MAG << WBG << "🐈‍  CAT   🐈‍" << RESET << MAG << " Copy Constructor called" << RESET << std::endl;
}

Cat& Cat::operator=(const Cat &obj){
	if (this != &obj){
		this->type = "Dog";
		if (this->brain != NULL)
			delete this->brain;
		this->brain = new Brain(*obj.brain);
	}
	return *this;
}

Cat::~Cat(){
	delete this->brain;
	std::cout << MAG << WBG << "🐈‍  CAT   🐈‍" << RESET << MAG <<" Destroyed"<< RESET << std::endl;
}

void Cat::makeSound(void) const {
	std::cout << this->type << " : *MeooooowW*" << std::endl;
}

Brain *Cat::getBrain(void) const{
	return (this->brain);
}