/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:41:27 by ljospin           #+#    #+#             */
/*   Updated: 2024/04/09 12:57:26 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

/* HumanA takes the Weapon in its constructor, HumanA will always be armed*/
HumanA::HumanA(std::string name, Weapon& weapon) :
	name(name),
	weapon(weapon){
	return;
}

HumanA::~HumanA(){
	return;
}

void	HumanA::attack(){
	std::cout<< this->name << " attacks with their " << this->weapon.getType() << std::endl;
}
