/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:15:47 by ljospin           #+#    #+#             */
/*   Updated: 2023/09/05 13:15:48 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
class Bureaucrat;

class Form{
	private :
		const std::string 	name;
		const int			gradeSign;
		const int			gradeEx;
		bool				signature;

	public :
		Form(std::string name, int gradeSign, int gradeEx);
		Form(Form const &obj);
		Form& operator=(Form const &obj);
		~Form();

	// ACCESSORS 
		std::string getName() const;
		int			getGradeSign() const;
		int 		getGradeEx() const;
		bool		getSigStatus() const;

	// MEMBER FUNCTIONS
		void beSigned(Bureaucrat &bur);

	// EXCEPTION
	class GradeTooHighException : public std::exception{
		public :
		virtual const char *what() const throw(){
		return "FORM Grade too high !";
	}
	};
	class GradeTooLowException : public std::exception{
		public :
		virtual const char *what() const throw(){
			return "FORM Grade too low :(";
		}
	};
};

std::ostream &operator<<(std::ostream &out, Form const &obj);
#endif