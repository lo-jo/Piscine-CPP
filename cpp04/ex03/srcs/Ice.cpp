/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 11:33:49 by ljospin           #+#    #+#             */
/*   Updated: 2023/08/03 19:10:07 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Ice.hpp"

/********************* CONSTRUCTORS ******************************/
// DEFAULT CONSTRUCTOR
Ice::Ice() : 
	AMateria("ice"){
	std::cout << BLUE << BLUBG << "🧊   Ice    🧊" << RESET << " Constructor called" << std::endl;
	}


// COPY CONSTRUCTOR
Ice::Ice(Ice const &obj):
	AMateria("ice"){
	std::cout << BLK << BLUBG << "🧊    Ice    🧊" << RESET << " Copy Constructor called" << std::endl;
	*this = obj;
}

/************************ DESTRUCTOR  ************************/
Ice::~Ice(){
	std::cout << BLK << BLUBG << "🧊   Ice    🧊" << RESET << " Destroyed" << std::endl;
}

/************************ OVERLOADERS ***********************/
// ASIGNMENT OPERATOR OVERLOADER
Ice& Ice::operator=(const Ice &obj){
	if (this != &obj){
		this->type = obj.type;
	}
	return *this;
}


/************************* METHODS **************************/
// ACCESSORS

AMateria *Ice::clone(void) const{
	AMateria*	Clone = new Ice();
		std::cout << "!!! just cloned - ice" << std::endl;
	return (Clone);
}

void	Ice::use(ICharacter & target){
	std::cout << BLUE << "* shoots an icebolt at " << target.getName() << " *"<< RESET << std::endl;
}
