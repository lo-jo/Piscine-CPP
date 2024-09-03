/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 12:12:43 by ljospin           #+#    #+#             */
/*   Updated: 2023/09/06 11:25:41 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

// CONSTRUCTOR 
AForm::AForm(std::string name, int gradeSign, int gradeEx) : 
	name(name), 
	gradeSign(gradeSign), 
	gradeEx(gradeEx), 
	signature(0){
//try{
	if (gradeSign > 150 || gradeEx > 150)
		throw AForm::GradeTooLowException();
	else if (gradeSign < 1 || gradeEx < 1)
		throw AForm::GradeTooHighException();
	else 
		std::cout << MAG << WBG << " FORM " << RESET << " " <<  MAG << this->name << RESET << " SIGNATURE GRADE : " << this->gradeSign << " | EXECUTION GRADE : "<< this->gradeEx << " created" << std::endl;

// catch(AForm::GradeTooHighException &e){
// 	std::cout << BOLD << RED << "WARNING " << RESET <<  "Creating form with a... " << e.what() << std::endl;
// }
// catch(AForm::GradeTooLowException &e){
// 	std::cout << BOLD << RED << "WARNING " << RESET << "Creating form with a... " << e.what() << RESET << std::endl;
// }

}

// COPY CONSTRUCTOR
AForm::AForm(AForm const &obj) :
	name(obj.name), 
	gradeSign(obj.gradeSign), 
	gradeEx(obj.gradeEx), 
	signature(obj.signature){
	std::cout << GREEN << WBG << "form" << RESET << " " << this->name << " ranked " << this->gradeEx << this->gradeSign << " copy created" << std::endl;

}

// ASSIGNMENT OPERATOR
AForm &AForm::operator=(AForm const &obj){
	if (this != &obj){
		this->signature = obj.signature;
	}
	std::cout << MAG << WBG << "FORM" << RESET << " " << this->name << " ranked " << this->gradeSign << " copy assignment constructor called" << std::endl;
	return (*this);
}

// DESTRUCTOR
AForm::~AForm(){
	std::cout <<  MAG << WBG << "FORM" << RESET << " " << this->name << " ranked " << this->gradeSign << " destructed" << std::endl;
}

// ACCESSORS
std::string AForm::getName() const{
	return (this->name);
}

int		AForm::getGradeSign() const{
	return(this->gradeSign);
}

int		AForm::getGradeEx() const{
	return(this->gradeEx);
}

bool	AForm::getSigStatus() const{
	return(this->signature);
}

// MEMBER FUNCTIONS 

//ex: gradeSign = 10
// > il faut etre un bureaucrate de grade 10 ou -
// si grade > gradeSign
// catch grade too low

void	AForm::beSigned(Bureaucrat &bur){
//	try{
		if (bur.getGrade() > this->gradeSign)
			throw AForm::GradeTooLowException();
		else{
			this->signature = true;
			std::cout << BOLD << this->name << " was successfully signed by " << bur.getName() << RESET << std::endl; 
		}
//	}
	// catch(AForm::GradeTooLowException &e){
	// 	std::cout << this->getName() << " couldn't be signed by " << bur.getName() << " because " << e.what() << std::endl;
	// }
}



void	AForm::execute(Bureaucrat const &bur) const {
	// try {
	if (bur.getGrade() > this->gradeEx || !this->signature)
		throw AForm::GradeTooLowException();
	else if (!this->getSigStatus())
		throw AForm::NotSignedException();
	// }
	// catch (AForm::GradeTooLowException &e){
	// 	std::cout << this->getName() << " couldn't be executed by " << bur.getName() << " because " << e.what() << " or isnt signed" << std::endl;
	// }
}


// NON MEMBER FUNCTIONS
std::ostream &operator<<(std::ostream &out, AForm const &obj){
	out << MAG << BOLD << "FORM "<< RESET << RED << "\"" << obj.getName() << "\"" << RESET << " SIGNATURE GRADE : " <<MAG<< obj.getGradeSign() << RESET << " | EXECUTION GRADE : "<< MAG << obj.getGradeEx() << RESET << " | SIGNATURE STATUS : " << MAG << obj.getSigStatus() << RESET << std::endl;
	return out;
}

// EXCEPTIONS
const char* AForm::GradeTooLowException::what() const throw(){
	return "FORM grade too low";
}

const char* AForm::GradeTooHighException::what() const throw(){
	return "FORM grade too high";
}

const char* AForm::NotSignedException::what() const throw(){
	return "Form not signed";
}