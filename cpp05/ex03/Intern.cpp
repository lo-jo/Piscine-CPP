/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 12:12:37 by ljospin           #+#    #+#             */
/*   Updated: 2023/09/05 12:14:57 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(){
	std::cout << "intern created" << std::endl;
}

Intern::~Intern(){
	std::cout << "intern destructed" << std::endl;
}

Intern::Intern(Intern const &obj){
	std::cout << "copy intern constructor called" << std::endl;
	*this = obj;
}

Intern &Intern::operator=(Intern const &obj){
	(void)obj;
	return (*this);
}

AForm* Intern::createShrub(std::string const & target){
    return (new ShrubberyCreationForm(target));    
} 

AForm* Intern::createPresidential(std::string const & target){
    return (new PresidentialPardonForm(target));    
} 

AForm* Intern::createRobotomy(std::string const & target){
    return (new RobotomyRequestForm(target));    
} 

AForm* Intern::makeForm(std::string const name, std::string const target){
	std::string namelist[3] = {
		"shruberry creation",
		"robotomy request",
		"presidential form"
	};
	AForm* (Intern::*makeForm[3])(std::string const &target)={
		&Intern::createShrub,
		&Intern::createRobotomy,
		&Intern::createPresidential
	};
	for (int i = 0; i < 3; i++){
		if (namelist[i] == name){
			std::cout <<  BLUE << "intern" << RESET << " creates " << name << std::endl;
			return(this->*makeForm[i])(target);
		}
			
	}
	throw Intern::FormNotFoundException();
	//return (NULL);
}


