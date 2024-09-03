/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 12:12:46 by ljospin           #+#    #+#             */
/*   Updated: 2023/09/06 11:24:07 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
class Bureaucrat;

class AForm{
	private :
		const std::string 	name;
		const int			gradeSign;
		const int			gradeEx;
		bool				signature;

	public :
		AForm(std::string name, int gradeSign, int gradeEx);
		AForm(AForm const &obj);
		AForm& operator=(AForm const &obj);
		virtual ~AForm() = 0;

	// ACCESSORS 
		std::string getName() const;
		int			getGradeSign() const;
		int 		getGradeEx() const;
		bool		getSigStatus() const;

	// MEMBER FUNCTIONS
		void beSigned(Bureaucrat &bur);
		virtual void execute(Bureaucrat const &bur) const = 0;

	// EXCEPTION
	class GradeTooHighException : public std::exception{
	public :
		virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception{
		public :
		virtual const char *what() const throw();
	};

	class NotSignedException : public std::exception{
		public :
		virtual const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &out, AForm const &obj);
#endif