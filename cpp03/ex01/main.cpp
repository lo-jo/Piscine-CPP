/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 14:43:03 by ljospin           #+#    #+#             */
/*   Updated: 2023/07/31 15:49:08 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

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
	std::cout << GREEN << "Base Class ClapTrap :" << RESET << std::endl;
	ClapTrap Clapper("Classic Robot");
	std::cout << GREEN << "Base Class ClapTrap (without name) :" << RESET << std::endl;
	ClapTrap Claptest;
	std::cout << std::endl;
	std::cout << GREEN << "Derived Class ScavTrap  :" << RESET << std::endl;
	ScavTrap Derived("Derived Robot");
	
	std::cout << std::endl;
	std::cout << GREEN << "Classic Robot starts attacking Derived Robot ..." << RESET << std::endl;
	Clapper.attack("Derived Robot");
	std::cout << std::endl;
	std::cout << GREEN << "Let's make Derived Robot attack the Classic Robot :" << RESET << std::endl;
	Derived.attack("Classic Robot");
	std::cout << std::endl << GREEN << "Let's make Derived Robot attack Robot without a name :" << RESET << std::endl;
	Derived.attack("");

	std::cout << std::endl;
	std::cout << GREEN << "Let's try and make classic Robot attack Derived Robot from the grave:" << RESET << std::endl;
	Clapper.attack("Derived Robot");

	std::cout << std::endl;
	std::cout << GREEN << "Let's set Derived Robot into gate keeping mode:" << RESET << std::endl;
	Derived.guardGate();
	std::cout << std::endl;
	
	return 0;
}