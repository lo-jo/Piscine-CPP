#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

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

/* ORTHODOx CANONICAL FORM :
* - default constructor
* - copy constructor
* - assignment operator
* - destructor 
*/

class ClapTrap{
	public:
	ClapTrap(); //default constructor
	ClapTrap(std::string name); // ad hoc constructor
	ClapTrap(ClapTrap const  &obj);// copy constructor
	~ClapTrap(); // destructor
	ClapTrap& operator=(const ClapTrap &obj);// copy assignment operator

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	//Accessors
	unsigned int getHit();
	unsigned int getEnergy();
	unsigned int getDamage();
	std::string getName();

	//Setters
	void setHit(unsigned int hit);
	void setEnergy(unsigned int energy);
	void setDamage(unsigned int damage);

 protected:
	std::string name;
	int hit;
	int energy;
	int damage;
};



#endif