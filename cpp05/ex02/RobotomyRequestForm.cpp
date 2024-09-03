/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 14:42:00 by ljospin           #+#    #+#             */
/*   Updated: 2023/09/05 14:33:57 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
	AForm("RobotomyRequestForm", 72, 45),
	target(target){
	std::srand(time(0));
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &obj) :
	AForm(obj), 
	target(obj.target){
		*this= obj;
	}

RobotomyRequestForm::~RobotomyRequestForm(){
}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const &obj){
	if (this != &obj)
		this->target = obj.target;
	return (*this);
}



void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	std::cout << MAG << "* drRRRRrrrRRRRRRRRRRRrrrRRR *" << RESET << std::endl;
	if (!this->getSigStatus())
			throw AForm::NotSignedException();
	if (std::rand() % 2){
		if (executor.getGrade() > 45)
			throw Bureaucrat::GradeTooLowException();
		else
			std::cout << BOLD << this->target << " has been robotomized successfully by " << executor.getName() << RESET << std::endl;
	}
	else
		std::cout << RED << this->target << " robotomization failed." << RESET << std::endl;
}

