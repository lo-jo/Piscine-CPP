/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 12:15:02 by ljospin           #+#    #+#             */
/*   Updated: 2023/09/05 12:15:03 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class AForm;

class Intern{
	public :
	Intern();
	Intern(Intern const &obj);
	Intern& operator=(Intern const &obj);
	~Intern();

	class FormNotFoundException : public std::exception{
		public :
			virtual const char* what() const throw(){
				return ("Form not found");
			}
	};

	AForm* makeForm(std::string name, std::string target);

	private :
	AForm* createShrub(std::string const & target);
	AForm* createPresidential(std::string const & target);
	AForm* createRobotomy(std::string const & target);

};

#endif