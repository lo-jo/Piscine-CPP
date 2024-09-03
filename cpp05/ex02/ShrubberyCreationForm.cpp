/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 14:42:00 by ljospin           #+#    #+#             */
/*   Updated: 2023/09/05 14:26:38 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
	AForm("Shrubbery Creation Form", 145, 137),
	target(target){
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &obj) :
	AForm(obj), 
	target(obj.target){
		*this= obj;
	std::cout << "Copy ShrubberyCreation Form created" << std::endl;
	}

ShrubberyCreationForm::~ShrubberyCreationForm(){
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const &obj){
	if (this != &obj)
		this->target = obj.target;
	return (*this);
}

// 
void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
		if (!this->getSigStatus())
		throw AForm::NotSignedException();
	if (executor.getGrade() <= 137 && executor.getGrade() >= 1)
		{
			std::string filename = this->target + "_shrubbery";
			std::ofstream file(filename.c_str());
			file << "               ,@@@@@@@," << std::endl
				 << "       ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl
				 << "    ,&&%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl
				 << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl
				 << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl
				 << "   %&&%/ %&%&%&@@\\ V /@@' `88\\8 `/88'" << std::endl
				 << "   `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl
				 << "       |o|        | |         | |" << std::endl
				 << "       |.|        | |         | |" << std::endl
				 << "    \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_" << std::endl;
		}
	else
		throw Bureaucrat::GradeTooLowException();
}


