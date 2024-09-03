/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 11:25:51 by ljospin           #+#    #+#             */
/*   Updated: 2023/09/11 12:20:40 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Base.hpp"

Base::~Base(){}
A::~A(){}
B::~B(){}
C::~C(){}

/*
Randomly instanciates A, B or C and returns the instance as a bse pointer 
Feel free to use anything u like for the random choice implementation
>> RANDOMISING NUMBERS with srand(), which takes an integer as the seed
A commonly used technique is to seed the random nbr generator using the clock
*/

Base* generate(void) {
	srand(time(NULL));
	int rando = rand() %3;
	
	if (rando == 0) {
		std::cout << "A generated" << std::endl;
		return new A();
	} else if (rando == 1) {
		std::cout << "B generated" << std::endl;
		return new B();
	} else {
		std::cout << "C generated" << std::endl;
		return new C();}

}

/**
	Dynamic cast :
	a pointer or ref to a class can point to any class derived tom that class
	The dynamic type cast converts a pointer to a class into a point to another class
	(both classes must be part of the same hierarchy)
 */
void identify(Base *p) {
	if (dynamic_cast<A*>(p)) {
		std::cout << "A" << std::endl;
	} else if (dynamic_cast<B*>(p)) {
		std::cout << "B" << std::endl;
	} else if (dynamic_cast<C*>(p)) {
		std::cout << "C" << std::endl;
	}
}

/*
	USING A POINTER INSIDE THIS FUNCTION IS FORBIDDEN >:[
	storing cast into tmp variable
	trying exception on failed cast to find out type
*/
void identify(Base& p) {
	Base tmp;
	try {
		tmp = dynamic_cast<A&>(p);
		std::cout << "a" << std::endl;
	} catch (std::exception &e){}
	try {

		tmp = dynamic_cast<B&>(p);
		std::cout << "b" << std::endl;

	} catch (std::exception &e){}

	try {
		tmp = dynamic_cast<C&>(p);
		std::cout << "c" << std::endl;
	} catch (std::exception &e){}
}