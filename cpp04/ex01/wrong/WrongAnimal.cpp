/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 12:44:27 by ljospin           #+#    #+#             */
/*   Updated: 2023/07/27 13:51:41 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

/** CONSTRUCTORS **/
WrongAnimal::WrongAnimal() : 
	type("WrongAnimal"){
	std::cout << BLK << WBG << "🐾❌ WrongANIMAL 🐾" << RESET << " Constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const& obj){
	std::cout << BLK << WBG << "🐾❌ WrongANIMAL 🐾" << RESET << " Copy Constructor called" << std::endl;
	*this = obj;
}
WrongAnimal::WrongAnimal(std::string type) : 
	type(type){ 
	std::cout << BLK << WBG << "🐾❌ ANIMAL 🐾" << RESET << " AdHoc Constructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &obj){
	if (this != &obj){
		this->type = obj.type;
	}
	return *this;
}
/** DESTRUCTOR **/
WrongAnimal::~WrongAnimal(){
	std::cout << BLK << WBG << "🐾❌ WrongANIMAL 🐾" << RESET << " Destroyed" << std::endl;
}

/** METHODS **/
std::string WrongAnimal::getType() const {
    return (this->type);
}

void WrongAnimal::makeSound(void) const {
	std::cout << "*Random WrongAnimal noises*" << std::endl;
}