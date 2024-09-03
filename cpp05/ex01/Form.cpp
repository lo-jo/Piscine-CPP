/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:15:44 by ljospin           #+#    #+#             */
/*   Updated: 2023/09/05 13:26:35 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(std::string name, int gradeSign, int gradeEx) : 
	name(name), 
	gradeSign(gradeSign), 
	gradeEx(gradeEx), 
	signature(0){
	if (gradeSign > 150 || gradeEx > 150)
		throw Form::GradeTooLowException();
	else if (gradeSign < 1 || gradeEx < 1)
		throw Form::GradeTooHighException();
	else 
		std::cout << MAG << WBG << "FORM" << RESET << " " <<  MAG << this->name << RESET << " SIGNATURE GRADE : " << this->gradeSign << " | EXECUTION GRADE : "<< this->gradeEx << " created" << std::endl;

}

// COPY CONSTRUCTOR
Form::Form(Form const &obj) :
	name(obj.name), 
	gradeSign(obj.gradeSign), 
	gradeEx(obj.gradeEx), 
	signature(obj.signature){
	std::cout << GREEN << WBG << "form" << RESET << " " << this->name << " ranked " << this->gradeEx << this->gradeSign << " copy created" << std::endl;

}

// ASSIGNMENT OPERATOR
Form &Form::operator=(Form const &obj){
	if (this != &obj){
		this->signature = obj.signature;
	}
	std::cout << MAG << WBG << "FORM" << RESET << " " << this->name << " ranked " << this->gradeSign << " copy assignment constructor called" << std::endl;
	return (*this);
}

Form::~Form(){
	std::cout <<  MAG << WBG << "FORM" << RESET << " " << this->name << " ranked " << this->gradeSign << " destructed" << std::endl;
}

	// ACCESSORS
std::string Form::getName() const{
	return (this->name);
}

int		Form::getGradeSign() const{
	return(this->gradeSign);
}

int		Form::getGradeEx() const{
	return(this->gradeEx);
}

bool	Form::getSigStatus() const{
	return(this->signature);
}

std::ostream &operator<<(std::ostream &out, Form const &obj){
	out << MAG << BOLD << "FORM "<< RESET << RED << "\"" << obj.getName() << "\"" << RESET << " SIGNATURE GRADE : " <<MAG<< obj.getGradeSign() << RESET << " | EXECUTION GRADE : "<< MAG << obj.getGradeEx() << RESET << " | SIGNATURE STATUS : " << MAG << obj.getSigStatus() << RESET << std::endl;
	return out;
}

//ex: gradeSign = 10
// > il faut etre un bureaucrate de grade 10 ou -
// si grade >= gradeSign
// catch grade too low

void	Form::beSigned(Bureaucrat &bur){
	if (bur.getGrade() >= this->gradeSign && bur.getGrade() >= 1)
			throw Form::GradeTooLowException();
	else{
		this->signature = true;
		std::cout << this->name << " signed by " << bur.getName() << ". Signature status is now " << this->signature << std::endl;
		}
}
