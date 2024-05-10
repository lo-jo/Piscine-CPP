#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include "lib.hpp"


/*
Abstract classes are a fundamental concept 
in object-oriented programming (OOP) 
and are an essential feature of C++ 
and many other programming languages. 
An abstract class is a class that cannot 
be instantiated directly and is designed 
to serve as a base for other classes. 
It acts as a blueprint for derived classes, 
defining a common interface and shared behavior 
that all derived classes must implement.

In C++, you can create an abstract class 
by adding at least one pure virtual function to it. 
A pure virtual function is declared using the 
virtual keyword, followed by = 0 in its declaration, 
and it has no implementation in the abstract class. 
Classes containing pure virtual functions become 
abstract classes, and you cannot create objects 
directly from them.
*/
class Animal{
	public:
	Animal(); //default constructor
	Animal(std::string type);
	Animal(Animal const  &obj);// copy constructor
	virtual ~Animal(); // destructor
	Animal& operator=(const Animal &obj);// copy assignment operator
	
	std::string getType() const;
	virtual void	makeSound() const = 0;

 protected:
	std::string type;
};


#endif