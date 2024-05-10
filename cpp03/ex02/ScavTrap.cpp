/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 14:43:47 by ljospin           #+#    #+#             */
/*   Updated: 2023/07/31 15:53:52 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/** CONSTRUCTORS **/
ScavTrap::ScavTrap() : ClapTrap(){
	this->hit = 100;
	this->energy = 50;
	this->damage = 20;
	std::cout << MAG << WBG << "Default ScavTrap Constructor" << RESET << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const& obj): ClapTrap(){
	std::cout <<  YEL << "ScavTrap Copy constructor called" << RESET << std::endl;
	*this = obj;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name){
	this->name = name;
	this->hit = 100;
	this->energy = 50;
	this->damage = 20;
	std::cout << MAG << WBG << "SCAVTRAP" << RESET << " AD HOC CONSTRUCTOR CALLED" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &obj){
	if (this != &obj){
		this->name = obj.name;
		this->energy = obj.energy;
		this->hit = obj.hit;
		this->damage = obj.damage;
	}
	return *this;
}

/** DESTRUCTOR **/
ScavTrap::~ScavTrap(){
	std::cout << MAG << WBG << "SCAVTRAP"<< RESET << " " << YEL << this->name << " Destroyed" << RESET << std::endl;
}

void ScavTrap::attack(const std::string& target){
	std::cout << "  🗡️🗡️🗡️🗡️🗡️ ! SCAVTRAP ATTACK !🗡️🗡️🗡️🗡️" << std::endl;
	ClapTrap::attack(target);
}

void ScavTrap::guardGate() {
	std::cout << MAG << this->name << " (ScavTrap) is in gate keeping mode" << RESET << std::endl;
}