/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:15:03 by ljospin           #+#    #+#             */
/*   Updated: 2023/07/05 10:47:13 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name) : name(name){
	std::cout << name << " ...is getting born" << std::endl;
	return;
}

Zombie::~Zombie(){
	std::cout << GREEN << name << " Has died" << RESET << std::endl;
	return;
}

void	Zombie::announce(){
	std::cout << name <<" : " << MAG << "BraiiiiiiinnnzzzZ..." << RESET << std::endl;
	return;
}

