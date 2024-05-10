/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 11:33:49 by ljospin           #+#    #+#             */
/*   Updated: 2023/08/03 19:10:11 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cure.hpp"

/********************* CONSTRUCTORS ******************************/
// DEFAULT CONSTRUCTOR
Cure::Cure() : 
	AMateria("cure"){
	std::cout << RED << GBG << "💉   Cure   💉" << RESET << " Constructor called" << std::endl;
}


// COPY CONSTRUCTOR
Cure::Cure(Cure const &obj):
	AMateria("cure"){
	std::cout << RED << GBG << "💉   Cure   💉" << RESET << " Copy Constructor called" << std::endl;
	*this = obj;
}

/************************ DESTRUCTOR  ************************/
Cure::~Cure(){
	std::cout << RED << GBG << "💉   Cure   💉" << RESET << " Destroyed" << std::endl;
}

/************************ OVERLOADERS ***********************/
// ASIGNMENT OPERATOR OVERLOADER
Cure& Cure::operator=(const Cure &obj){
	if (this != &obj){
		this->type = obj.type;
	}
	return *this;
}


/************************* METHODS **************************/
// ACCESSORS

AMateria *Cure::clone(void) const{
	AMateria*	Clone = new Cure();
	std::cout << "!!! just cloned cure" << std::endl;
	return (Clone);
}

void	Cure::use(ICharacter & target){
	std::cout << MAG << "* heals " << target.getName() << "\'s wounds *" << RESET << std::endl;
}
