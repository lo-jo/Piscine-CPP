/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 12:53:24 by ljospin           #+#    #+#             */
/*   Updated: 2023/08/04 15:45:37 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "./wrong/WrongCat.hpp"
#include "./wrong/WrongAnimal.hpp"

int	main(){
	std::cout << GREEN << "************************************" << RESET << std::endl;
	std::cout << GREEN << "****** Basic animal tests **********" << RESET << std::endl;
	std::cout << GREEN << "************************************" << RESET << std::endl;
	std::cout << std::endl;

	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << std::endl;
	
	std::cout << GREEN << "****** Get the Animal Type **********" << RESET << std::endl;
	std::cout << "j is of type " << j->getType() << " " << std::endl;
	std::cout << "i is of type "<< i->getType() << " " << std::endl;

	std::cout << std::endl;
	std::cout << GREEN << "****** Animal Sounds **********" << RESET << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	
	std::cout << std::endl;
	std::cout << GREEN << "******* Animal destruction **********" << RESET << std::endl;
	delete meta;
	delete i;
	delete j;


	std::cout << std::endl;
	std::cout << GREEN << "************************************" << RESET << std::endl;
	std::cout << GREEN << "****** Wrong animal tests **********" << RESET << std::endl;
	std::cout << GREEN << "************************************" << RESET << std::endl;
	std::cout << std::endl;

	const WrongAnimal* ani = new WrongAnimal();
	const WrongAnimal* gato = new WrongCat();
	std::cout << std::endl;
	
	std::cout << GREEN << "****** Get the Animal Type **********" << RESET << std::endl;
	std::cout << "gato is of type "<< gato->getType() << " " << std::endl;

	std::cout << std::endl;
	std::cout << GREEN << "****** Get the Animal Sounds **********" << RESET << std::endl;
	gato->makeSound(); //will output the cat sound!
	//j->makeSound();
	ani->makeSound();
	
	std::cout << std::endl;
	std::cout << GREEN << "****** Wrong animal destruction **********" << RESET << std::endl;
	delete gato;
	delete ani;
	return 0;
}