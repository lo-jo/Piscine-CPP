/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 12:15:38 by ljospin           #+#    #+#             */
/*   Updated: 2023/09/05 12:15:39 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP


#include "AForm.hpp"
#include <cstdlib> 


class AForm;

class RobotomyRequestForm : public AForm {
	public :
		//CANONICAL
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm const &obj);
		RobotomyRequestForm &operator=(RobotomyRequestForm const &obj);
		~RobotomyRequestForm();

		// MEMBER FUNCTIONS
		void execute(Bureaucrat const &bur) const;

	private :
		std::string target;

};

#endif