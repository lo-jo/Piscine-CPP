/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 14:43:03 by ljospin           #+#    #+#             */
/*   Updated: 2023/07/31 13:33:04 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

/*
INHERITANCE HIERARCHY
When a derived object is created, 
the original class constructor is called before the derived class constructor
When a derived object is destroyed,
its destructor is called before the base class destructor
>>> Why ? 
Because the derived class is built on top of the base class and inherits the properties and behaviours
of the base class. 
*/

int main(){
	std::cout << GREEN << "Base class ClapTrap :" << RESET << std::endl;
	ClapTrap Clapper("ClapTrap Robot");
	std::cout << std::endl;
	std::cout << GREEN << "Derived class ScavTrap :" << RESET << std::endl;
	ScavTrap Derived("ScavTrap Robot");

	std::cout << std::endl;
	std::cout << GREEN << "Here comes our new character (derived class FragTrap):" << RESET << std::endl;
	FragTrap Frag("Fraggy");

	std::cout << std::endl;
	std::cout << GREEN << "Let's make Fragster attack ClapTrap Robot and Derived ScavTrap Robot" << RESET << std::endl;
	Frag.attack("ClapTrap Robot");
	Frag.attack("ScavTrap Robot");

	std::cout << std::endl;
	std::cout << GREEN << "Let's make Fragster even stronger for no reason at all" << RESET << std::endl;
	Frag.beRepaired(50);
	std::cout << std::endl;

	Frag.highFivesGuys();
	std::cout << std::endl;
	return 0;
}