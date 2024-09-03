/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:15:49 by ljospin           #+#    #+#             */
/*   Updated: 2023/09/05 13:34:25 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

void	signform_failure(){
	try{
		std::cout << GREEN << "***** BASIC TESTS *****" << RESET << std::endl;
		std::cout << YEL << ">> Creating form" << RESET << std::endl;
		Form Formy("Confidential", 2, 12);
		std::cout << YEL << ">> Overload of the insertion << test" << RESET << std::endl;
		std::cout << Formy;
		Bureaucrat Bur("Boss", 1);
		std::cout << YEL << ">> Boss has the proper permission to sign that form" << RESET << std::endl;
		Bur.signForm(Formy);
	
		std::cout << std::endl << GREEN << ">> ** SIGN FORM FUNCTION FAILURE ** (should display because + reason)" << RESET << std::endl;
		std::cout << YEL << ">> An entrylevel bureaucrat tries to sign the form requiring a level 2 or less " << RESET << std::endl;
		Bureaucrat Low("EntryLevel", 120);
		Low.signForm(Formy);

	}
	catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
}

void	out_of_bounds_form(){
	std::cout << std::endl << YEL << ">> testing out of bounds form creation " << RESET << std::endl;
	try{
		Form lol("testform", 0, 1);
		Form loel("testyform", 151, 1);
	}
	catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}

	try{
		Form loel("testyform", 151, 1);
	}
	catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
}

void	signature_success(){
	try{
		std::cout << std::endl << YEL << ">> testing signForm " << RESET << std::endl;
		Bureaucrat Bur("Boss", 1);
		Form Extra("ExtraForm", 3, 25);
		std::cout << YEL << ">> ExtraForm (sig grade 3, exec grade 25) gets signed by grade 1 bureaucrat " << RESET << std::endl;
		Extra.beSigned(Bur);
		//std::cout << Extra;
	}
	catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
}

void besigned_failure(){
	try{
	std::cout << std::endl << GREEN << "***** BE SIGNED FUNCTION FAILURE *****" << RESET << std::endl;
	Bureaucrat Low("EntryLevel", 120);
	Form Extra("ExtraForm", 3, 25);
	Extra.beSigned(Low);
	}
	catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
	
}

int main(){

	signform_failure();
	besigned_failure();
	out_of_bounds_form();
	signature_success();
	return 0;
}