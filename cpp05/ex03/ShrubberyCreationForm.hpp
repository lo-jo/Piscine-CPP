/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 12:16:19 by ljospin           #+#    #+#             */
/*   Updated: 2023/09/05 12:16:23 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERRYCREATIONFORM_HPP
#define SHRUBBERRYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class AForm;

class ShrubberyCreationForm : public AForm {
	public :
		//CANONICAL
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm const &obj);
		ShrubberyCreationForm &operator=(ShrubberyCreationForm const &obj);
		~ShrubberyCreationForm();

		// MEMBER FUNCTIONS
		void execute(Bureaucrat const &bur) const;

	private :
		std::string target;

};

#endif