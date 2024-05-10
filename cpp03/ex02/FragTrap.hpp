#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
	public:
	FragTrap(); //default constructor
	FragTrap(std::string name); // ad hoc constructor
	FragTrap(FragTrap const &obj);// copy constructor
	~FragTrap(); // destructor
	FragTrap& operator=(const FragTrap &obj);// copy assignment operator

	void highFivesGuys();
	void attack(const std::string& robot);
	void beRepaired(unsigned int amount);
	
	private:

};


#endif