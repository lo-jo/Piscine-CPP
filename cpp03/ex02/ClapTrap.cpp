/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 14:43:47 by ljospin           #+#    #+#             */
/*   Updated: 2023/07/31 15:58:07 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

static int i = 0;
ClapTrap *ClapTab[30];

void addClap(ClapTrap *obj){
	i++;
	ClapTab[i] = obj;
}

/** CONSTRUCTORS **/
ClapTrap::ClapTrap() : 
	hit(10),
	energy(10),
	damage(0){
	addClap(this);
	std::cout << BLK << WBG << "CLAPTRAP" << RESET << "Default Constructor called" << RESET << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const& obj){
	std::cout << BLK << WBG << "CLAPTRAP" << RESET << "Copy Constructor called" << RESET << std::endl;
	*this = obj;
	addClap(this);
}

ClapTrap::ClapTrap(std::string name) :
	name(name),
	hit(10),
	energy(10),
	damage(0){
	addClap(this);
	std::cout  << BLK << WBG << "CLAPTRAP" << RESET << " Adhoc Constructor called, welcome to " << MAG << this->name << RESET << std::endl;
}


ClapTrap& ClapTrap::operator=(const ClapTrap &obj){
	if (this != &obj){
		this->name = obj.name;
		this->energy = obj.energy;
		this->hit = obj.hit;
		this->damage = obj.damage;
	}
	return *this;
}
/** DESTRUCTOR **/
ClapTrap::~ClapTrap(){
	std::cout << BLK << WBG << "CLAPTRAP" << RESET << RED << " " << this->name << " Destroyed "<< RESET << std::endl;
}

//Accessors
unsigned int ClapTrap::getHit(){
	return (this->hit);
}
unsigned int ClapTrap::getEnergy(){
	return (this->energy);
}
unsigned int ClapTrap::getDamage(){
	return (this->damage);
}
std::string ClapTrap::getName(){
	return (this->name);
}

int findRobot(const std::string &robot){
	int x = 1;
	while(x <= i){
		if ((ClapTab[x]->getName() == robot) && (ClapTab[x]->getName() != "")){
			return x;
		}
		x++;
	}
	std::cout << "You can't attack someone who doesnt exist" << std::endl;
	return 0;
}

/* 
• this->energy needs to have enough energy to attack 
1 attack = this->energy -1;
• target->hit must be superior to 0 otherwise it is already dead
1 attack -= target.hit - target.damage;
• this->name must be different than target "this->name cannot attack itself"
*/

void ClapTrap::attack(const std::string& target){
	if (this->hit <= 0){
		std::cout << RED << this->name << " is dead and cannot attack" << RESET << std::endl;
		return;
	}
	if (this->energy <= 0){
		std::cout << RED << this->name << " is too tired to attack" << RESET << std::endl;
		return;
	}
	if (target == this->name){
		std::cout << "Pretty stupid of you to attack urself but okay" << std::endl;
	}
	this->energy--;
	std::cout << "🔪 " << RBG << this->name << " attacks " << target << " causing " << this->damage << " points of damage !" << RESET << " 🔪"<< std::endl;
	if (findRobot(target) != 0){
		ClapTab[findRobot(target)]->takeDamage(this->damage);
	}
		
}

void ClapTrap::takeDamage(unsigned int amount){
	std::cout << "🩸 ouchhh " << this->name << " took a hit of " << RED << amount << RESET << std::endl;
	setHit(this->hit - amount);
	if (this->hit <= 0){
		std::cout << "🪦  Um... " << RED << this->name << RESET << " did not make it and is D E A D 🪦" << std::endl;
		return;
	}
}

void ClapTrap::beRepaired(unsigned int amount){
	if (this->energy <= 0){
		std::cout << RED << this->name << " is too tired to get repaired" << RESET << std::endl;
		return;
	}
	std::cout << "💊 " << GREEN << this->name << " is feeling a bit better with those " << amount << " hit points" << RESET << std::endl;
	setHit(this->hit + amount);
	this->energy--;
}

//Setters
void ClapTrap::setHit(unsigned int hit){
	this->hit = hit;
}
void ClapTrap::setEnergy(unsigned int energy){
	this->energy = energy;
}
void setDamage(unsigned int damage);