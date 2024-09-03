/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 14:42:00 by ljospin           #+#    #+#             */
/*   Updated: 2023/09/05 12:15:20 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
	AForm("PresidentialPardonForm", 25, 5),
	target(target){
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &obj) :
	AForm(obj), 
	target(obj.target){
		*this= obj;
	}

PresidentialPardonForm::~PresidentialPardonForm(){
}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const &obj){
	if (this != &obj)
		this->target = obj.target;
	return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
		if (!this->getSigStatus())
			throw AForm::NotSignedException();
		else if (executor.getGrade() > this->getGradeEx())
				throw Bureaucrat::GradeTooLowException();
		else
			std::cout << BOLD << this->target << " has been pardoned by Zaphod Beeblebrox" << RESET << std::endl;
}


