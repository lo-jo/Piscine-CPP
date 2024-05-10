/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 11:02:56 by ljospin           #+#    #+#             */
/*   Updated: 2023/08/03 17:50:48 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AMateria.hpp"

/********************* CONSTRUCTORS ******************************/
// DEFAULT CONSTRUCTOR
AMateria::AMateria() : 
	type("materia"){
	std::cout << BLK << "🔸 AMateria 🔸" << RESET << BLK << " Constructor called" << RESET << std::endl;
}

// AD-HOC CONSTRUCTOR
AMateria::AMateria(std::string const &type) : 
	type(type){ 
	std::cout << BLK << "🔸 AMateria 🔸" << RESET << BLK <<  " AdHoc Constructor called" << RESET << std::endl;
}

// COPY CONSTRUCTOR
AMateria::AMateria(AMateria const &obj){
	std::cout << BLK << WBG << "🔸 AMateria 🔸" << RESET << BLK <<  " Copy Constructor called" << RESET << std::endl;
	*this = obj;
}

/************************ DESTRUCTOR  ************************/
AMateria::~AMateria(){
	std::cout << BLK << "🔸 AMateria 🔸" << RESET << BLK <<  " Destroyed" << RESET << std::endl;
}

/************************ OVERLOADERS ***********************/
// ASIGNMENT OPERATOR OVERLOADER
AMateria& AMateria::operator=(const AMateria &obj){
	if (this != &obj){
		this->type = obj.type;
	}
	return *this;
}


/************************* METHODS **************************/
// ACCESSORS
std::string const &AMateria::getType() const{
	return this->type;
}

void AMateria::use(ICharacter &target){
	(void)target;
}