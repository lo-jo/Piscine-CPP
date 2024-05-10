/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 14:43:47 by ljospin           #+#    #+#             */
/*   Updated: 2023/07/27 12:20:06 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

/** CONSTRUCTORS **/
FragTrap::FragTrap() : ClapTrap(){
	this->hit = 100;
	this->energy = 100;
	this->damage = 30;
	std::cout << GREEN << WBG << "Default FragTrap Constructor" << RESET << std::endl;
}

FragTrap::FragTrap(FragTrap const& obj): ClapTrap(){
	std::cout <<  YEL << "FragTrap Copy constructor called" << RESET << std::endl;
	*this = obj;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name){
	this->name = name;
	this->hit = 100;
	this->energy = 100;
	this->damage = 30;
	std::cout << GREEN << WBG << "FragTRAP" << RESET << " AD HOC CONSTRUCTOR CALLED" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &obj){
	if (this != &obj){
		this->name = obj.name;
		this->energy = obj.energy;
		this->hit = obj.hit;
		this->damage = obj.damage;
	}
	return *this;
}

/** DESTRUCTOR **/
FragTrap::~FragTrap(){
	std::cout << GREEN << WBG << "FRAGTRAP"<< RESET << " " << YEL << this->name << " Destroyed" << RESET << std::endl;
}
	
void FragTrap::highFivesGuys(){
	std::cout << YEL << "!! " << this->name << " REQUESTED A HIGH FIVE !!" << RESET << std::endl;
}