/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 16:05:51 by ljospin           #+#    #+#             */
/*   Updated: 2023/07/05 10:48:51 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	create = 0;
int destruct = 0;

Zombie::Zombie(){
	create++;
	std::cout << name << "Zombie " << create << " was constructed" << std::endl;
	return;
}

Zombie::~Zombie(){
	destruct++;
	std::cout << name << " Has died on the "<< destruct << "th destruction" << std::endl;
	return;
}

void	Zombie::announce(){
	std::cout << name <<" : " << MAG << "BraiiiiiiinnnzzzZ..." << RESET << std::endl;
	return;
}

void	Zombie::giveName(std::string name){
	this->name = name;
	return;
}