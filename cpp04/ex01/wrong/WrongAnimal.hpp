#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

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
#define BLUE "\e[0;34m"


class WrongAnimal{
	public:
	WrongAnimal(); //default constructor
	WrongAnimal(WrongAnimal const  &obj);// copy constructor
	~WrongAnimal(); // destructor
	WrongAnimal(std::string type);
	WrongAnimal& operator=(const WrongAnimal &obj);// copy assignment operator
	
	std::string getType() const;
	void	makeSound() const;

 protected:
	std::string type;
};


#endif