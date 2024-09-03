/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:39:10 by ljospin           #+#    #+#             */
/*   Updated: 2023/09/05 14:35:54 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void	form_not_signed(){
	std::cout << std::endl << YEL << "*** FORM NOT SIGNED TEST ***" << RESET << std::endl;
	try{
		Bureaucrat 	Dave("Dave", 2);
		RobotomyRequestForm Robotomy("Student");
		Robotomy.execute(Dave);
	}
	catch (std::exception &e){
		std::cout << RED << e.what() << std::endl;
	}
	
}


void	sucessful_execution(){
	std::cout << std::endl << YEL << "*** BASIC WORKING TESTS ***" << RESET << std::endl;
	try{
		std::cout << GREEN << "*** SHRUBBERY CREATION ***" << RESET << std::endl;
		ShrubberyCreationForm ShrubForm("garden");
		Bureaucrat 			Dave("Dave", 2);
		Dave.signForm(ShrubForm);
		ShrubForm.execute(Dave);
		std::cout << std::endl << GREEN << "*** ROBOTOMY REQUEST FORM ***" << RESET << std::endl;
		RobotomyRequestForm Robotomy("Student");
		Robotomy.beSigned(Dave);
		Robotomy.execute(Dave);
		Robotomy.execute(Dave);
		Dave.executeForm(Robotomy);

		std::cout << std::endl << GREEN << "*** PRESIDENTIAL PARDON ***" << RESET << std::endl;
		PresidentialPardonForm Presid("Baby Mouse");
		Dave.signForm(Presid);
		Presid.execute(Dave);
		Dave.executeForm(Presid);
	}
	catch (std::exception &e){
		std::cout << RED << e.what() << std::endl;
	}
	
}

void grade_too_low(){
	std::cout << std::endl << YEL << "*** GRADE TOO LOW TESTS ***" << RESET << std::endl;
	std::cout << GREEN << "*** SHRUBBERY ***" << RESET << std::endl;
	try{
		Bureaucrat Rookie("Rookie", 143);
		ShrubberyCreationForm Shrub("Backyard");
		Rookie.signForm(Shrub);
		Rookie.executeForm(Shrub);
	}
	catch (std::exception &e){
		std::cout << RED << e.what() << std::endl;
	}


{
	std::cout << std::endl << GREEN << "*** PRESIDENTIAL PARDON ***" << RESET << std::endl;
	try{
		Bureaucrat Rookie("Rookie", 6);
		PresidentialPardonForm Pres("Criminal");
		Rookie.signForm(Pres);
		Rookie.executeForm(Pres);
	}
	catch (std::exception &e){
		std::cout << RED << e.what() << std::endl;
	}
}


{
	std::cout << std::endl << GREEN << "*** ROBOTOMY ***" << RESET << std::endl;
	try{
		Bureaucrat Rookie("Rookie", 47);
		RobotomyRequestForm Robotomy("You");
		Rookie.signForm(Robotomy);
		Rookie.executeForm(Robotomy);
	}
	catch (std::exception &e){
		std::cout << RED << e.what() << std::endl;
	}
}
}

int main(){
	sucessful_execution();
	form_not_signed();
	grade_too_low();
	


	return 0;
}