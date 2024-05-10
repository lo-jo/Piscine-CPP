/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:41:30 by ljospin           #+#    #+#             */
/*   Updated: 2023/07/05 10:06:00 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

/* HumanB may not always be armed*/
HumanB::HumanB(std::string name) :
	name(name),
	weapon(NULL)
{
	return;
}

HumanB::~HumanB(){
	return;
}

void	HumanB::setWeapon(Weapon& weapon){
	this->weapon = &weapon;
}
void	HumanB::attack(){
	if (this->weapon != NULL)
		std::cout<< this->name << " attacks with their " << this->weapon->getType() << std::endl;
	else
		std::cout<< this->name << " attacks with their bare hands" << std::endl;
}
