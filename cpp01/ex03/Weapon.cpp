/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:54:55 by ljospin           #+#    #+#             */
/*   Updated: 2023/07/05 10:54:56 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type): type(type){
		return;
}

Weapon::~Weapon(){
	return;
}

const std::string& Weapon::getType(){
	return(this->type);
}

void Weapon::setType(std::string type){
	this->type = type;
}