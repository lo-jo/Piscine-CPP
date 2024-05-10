/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 12:44:27 by ljospin           #+#    #+#             */
/*   Updated: 2023/07/27 13:50:19 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

/** CONSTRUCTORS **/
Animal::Animal() : 
	type("Animal"){
	std::cout << BLK << WBG << "🐾 ANIMAL 🐾" << RESET << " Constructor called" << std::endl;
}

Animal::Animal(std::string type) : 
	type(type){ 
	std::cout << BLK << WBG << "🐾 ANIMAL 🐾" << RESET << " AdHoc Constructor called" << std::endl;
}

Animal::Animal(Animal const& obj){
	std::cout << BLK << WBG << "🐾 ANIMAL 🐾" << RESET << " Copy Constructor called" << std::endl;
	*this = obj;
}

Animal& Animal::operator=(const Animal &obj){
	if (this != &obj){
		this->type = obj.type;
	}
	return *this;
}
/** DESTRUCTOR **/
Animal::~Animal(){
	std::cout << BLK << WBG << "🐾 ANIMAL 🐾" << RESET << " Destroyed" << std::endl;
}

/** METHODS **/
std::string Animal::getType() const {
    return (this->type);
}

void Animal::makeSound(void) const {
	std::cout << "*Random Animal noises*" << std::endl;
}