/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 12:58:04 by ljospin           #+#    #+#             */
/*   Updated: 2023/09/06 11:19:22 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

// LIBs
#include <iostream>
#include <string>
#include <stdexcept>

// ANSI COLORS
#define WBG "\x1B[47m"
#define RBG "\e[41m"
#define RESET "\x1B[0m"
#define BOLD "\x1B[1m"
#define MAG "\x1B[35m"
#define YEL "\x1B[33m"
#define RED "\x1B[31m"
#define BLK "\e[0;30m"
#define GREEN "\e[0;32m"
#define BLUE "\e[0;34m"

#include "Form.hpp"
class Form;

class Bureaucrat{
	public :
	Bureaucrat();
	Bureaucrat(Bureaucrat const &obj);
	Bureaucrat(std::string name, int grade);
	Bureaucrat& operator=(Bureaucrat const &obj);
	~Bureaucrat();

	// ACCESSORS
	std::string getName() const;
	int			getGrade() const;

	// EXCEPTION
	class GradeTooHighException : public std::exception{
		public :
		virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception{
		public :
		virtual const char *what() const throw();
	};


	// SETTERS
	void		upGrade();
	void		downGrade();

	// MEMBER FUNCTIONS
	void		signForm(Form &form);

	private :
	std::string const 	name;
	int					grade;
};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &obj);

#endif