#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal(){
	this->type = "WrongCat";
	std::cout << MAG << WBG << "🐈❌  WRONGCAT   🐈" << RESET << MAG << " Constructor called" << RESET << std::endl;
}

WrongCat::WrongCat(WrongCat const& obj): WrongAnimal(){
	*this = obj;
	std::cout << MAG << WBG << "🐈❌‍  WRONGCAT   🐈‍" << RESET << MAG << " Copy Constructor called" << RESET << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat &obj){
	if (this != &obj)
		this->type = "WrongCat";
	return *this;
}

WrongCat::~WrongCat(){
		std::cout << MAG << WBG << "🐈❌‍  WRONGCAT   🐈‍" << RESET << MAG <<" Destroyed"<< RESET << std::endl;
}

void WrongCat::makeSound(void) const{
	std::cout << this->type << " : *MeooooowW*" << std::endl;
}