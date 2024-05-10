#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

// ANSI COLORS
#define WBG "\x1B[47m"
#define RBG "\e[41m"
#define RESET "\x1B[0m"
#define BOLD "\x1B[1m"
#define MAG "\x1B[35m"
#define YEL "\x1B[33m"
#define RED "\x1B[31m"
#define BLK "\e[0;30m"
#define GREEN "\e[0;32m"


class ScavTrap : public ClapTrap {
	public:
	ScavTrap(); //default constructor
	ScavTrap(std::string name); // ad hoc constructor
	ScavTrap(ScavTrap const &obj);// copy constructor
	~ScavTrap(); // destructor
	ScavTrap& operator=(const ScavTrap &obj);// copy assignment operator

	void attack(const std::string& robot);
	void beRepaired(unsigned int amount);
	void guardGate();
	
	private:

};


#endif