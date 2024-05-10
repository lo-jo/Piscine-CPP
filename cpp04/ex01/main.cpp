/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 12:53:24 by ljospin           #+#    #+#             */
/*   Updated: 2023/08/04 15:57:41 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int	main(){
	{std::cout << GREEN << "************************************************" << std::endl;
	std::cout << "> Create an array of 10 animal objects" << RESET << std::endl;  
	Animal *aniTab[10];
	aniTab[10] = NULL;
	std::cout << GREEN << "> Fill that table with half DOGS and half CATS" << RESET << std::endl;
	for (int i = 0; i < 5; i++){
		std::cout << i + 1 << ": " << std::endl;
		aniTab[i] = new Dog();
	}
		
	for (int i = 5; i < 10; i++){
		std::cout << i + 1 << ": " << std::endl;
		aniTab[i] = new Cat();
		
	}

	std::cout << std::endl << GREEN << "> Ask each animal to make a sound" << RESET << std::endl;
	for (int i = 0; i < 10; i++){
		aniTab[i]->makeSound();
	}	
	
	std::cout << std::endl << GREEN << "> Destruct the animals" << RESET << std::endl;
	for (int i = 0; aniTab[i]; i++){
		std::cout << i << ": " << std::endl;
		delete aniTab[i];
	}
	

	std::cout << std::endl << GREEN << "************************************************" << std::endl;
	std::cout << "> Deep copy test" << std::endl;
	std::cout << "> Create a Cat \"Gato\"" << RESET << std::endl; 
	{Cat gato;
	std::cout << std::endl << GREEN "> Set 3 ideas in its head" << RESET << std::endl;
	gato.getBrain()->setIdeas(0, "Who am i?");
	gato.getBrain()->setIdeas(1, "Where am I going?");
	gato.getBrain()->setIdeas(2, "What is the meaning of life?");
	for (int i = 0; i < 3; i++)
		std::cout << gato.getBrain()->getIdeas(i) << std::endl;
	
	std::cout << std::endl << GREEN <<"> Create a Copy of \"Gato\", \"Copycat\"" << RESET << std::endl;
	Cat copyCat(gato);
	std::cout << std::endl << GREEN <<"> What is copyCat thinking ?" << RESET << std::endl;
		for (int i = 0; i < 3; i++)
		std::cout << copyCat.getBrain()->getIdeas(i) << std::endl;
	std::cout << std::endl;
	}

	}
	
	{
	std::cout << std::endl << "> ASSIGNMENT DEEP COPY TEST" << std::endl;
	std::cout <<  "> create a regular dog" << std::endl;
	Dog main;{
	std::cout << "assign regular dog to a random dog" << std::endl;
	Dog tmp = main;
	std::cout << "getting out of that scope, random dog should be destroyed:" << std::endl;
	}
	std::cout << "At the end of this scope now the regular dog should be destroyed" << std::endl;
	}
	return 0;
}