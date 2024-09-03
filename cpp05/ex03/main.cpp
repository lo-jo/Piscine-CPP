/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 12:12:35 by ljospin           #+#    #+#             */
/*   Updated: 2023/09/05 12:16:57 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

void	test_that_work(){
		try {
		std::cout << YEL << ">> TESTING things that should work" << RESET << std::endl;
		std::cout << YEL << "* Creating Shrubbery creation form, Bureaucrat, Robotomy and Presidential pardon request forms :" << RESET << std::endl;
		ShrubberyCreationForm ShrubForm("garden");
		Bureaucrat Dave("Dave", 2);
		RobotomyRequestForm Robotomy("Student");
		PresidentialPardonForm Presid("Baby Mouse");

		std::cout << std::endl << YEL << "* Signing and Executing forms by Dave who has the right permissions" << RESET << std::endl;
		ShrubForm.beSigned(Dave);
		Robotomy.beSigned(Dave);
		Dave.signForm(Presid);
		Robotomy.execute(Dave);
		Dave.executeForm(Presid);
		std::cout << std::endl << YEL << "* Intern tests" << RESET << std::endl;
		Intern RandomIntern;
		AForm* testform = RandomIntern.makeForm("robotomy request", "Baby Pig");
		delete testform;
	}
	catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
}

void	failed_form_creation_by_intern(){
	std::cout << std::endl << YEL << ">> TESTING Failed form creation by intern" << RESET << std::endl;
	try{
		Intern Newbie;
		AForm* loser = Newbie.makeForm("job application", "Google");
		delete loser;
	}
	catch (std::exception &e){
		std::cout << RED << e.what() << RESET << std::endl;
	}
}

int main(){
	test_that_work();
	failed_form_creation_by_intern();
	return 0;
}