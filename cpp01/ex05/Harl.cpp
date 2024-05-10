#include "Harl.hpp"

Harl::Harl(){
	std::cout << "Uh oh. Harl is coming." << std::endl;
	return;
}
Harl::~Harl(){
	return;
}

void Harl::debug(){
	std::cout << DEBUG << std::endl;
}
void Harl::info(){
	std::cout << INFO << std::endl;
}
void Harl::warning(){
	std::cout << WARNING << std::endl;
}
void Harl::error(){
	std::cout << ERROR << std::endl;
}

// array of complain() method in which each element points to a member function
void Harl::complain(std::string level){
	std::string	gravity[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*complain[4])(void) = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};
	for (int i = 0; i < 4; i++){
		if (gravity[i] == level)
			(this->*complain[i])();
	}
}