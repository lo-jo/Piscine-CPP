/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 12:55:16 by ljospin           #+#    #+#             */
/*   Updated: 2023/09/05 18:01:29 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() :
	name("White Collar"),
	grade(150){
	std::cout << BLUE << WBG << "BUREAUCRAT" << RESET << " " << "default constructor >> " << BLUE << this->name << RESET <<" ranked " << this->grade << " created"  << std::endl;
	return;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : 
	name(name), grade(0){
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else{
		this->grade = grade;
		std::cout << MAG << WBG << "BUREAUCRAT" << RESET << " " <<  MAG << this->name << RESET << " ranked " << this->grade << " created" << std::endl;
	}
}

// COPY CONSTRUCTOR
Bureaucrat::Bureaucrat(Bureaucrat const &obj) :
	name(obj.name), grade(obj.grade){
	std::cout << GREEN << WBG << "BUREAUCRAT" << RESET << " " << this->name << " ranked " << this->grade << " copy created" << std::endl;
}

// ASSIGNMENT OPERATOR
Bureaucrat &Bureaucrat::operator=(Bureaucrat const &obj){
	if (this != &obj){
		this->grade = obj.grade;
	}
	std::cout << GREEN << WBG << "BUREAUCRAT" << RESET << " " << this->name << " ranked " << this->grade << " copy assignment constructor called" << std::endl;
	return (*this);
}

Bureaucrat::~Bureaucrat(){
	std::cout <<  BLUE << WBG << "BUREAUCRAT" << RESET << " " << this->name << " ranked " << this->grade << " destructed" << std::endl;
}

	// ACCESSORS
std::string Bureaucrat::getName() const{
	return (this->name);
}

int		Bureaucrat::getGrade() const{
	return(this->grade);
}

void		Bureaucrat::upGrade(){
	if (this->grade <= 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->grade--;	
}

void		Bureaucrat::downGrade(){
	if (this->grade >= 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->grade++;
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &obj){
	out << BLUE << obj.getName() << RESET << ", bureaucrat grade " << MAG << obj.getGrade() << RESET << std::endl;
	return out;
}

// EXCEPTIONS
const char*	Bureaucrat::GradeTooHighException::what() const throw(){
	return "Grade too high !";
}

const char*	Bureaucrat::GradeTooLowException::what() const throw(){
	return "Grade too low :(";
}