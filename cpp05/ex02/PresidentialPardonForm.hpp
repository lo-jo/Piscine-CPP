/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 12:15:28 by ljospin           #+#    #+#             */
/*   Updated: 2023/09/05 12:15:29 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP


#include "AForm.hpp"


class AForm;

class PresidentialPardonForm : public AForm {
	public :
		//CANONICAL
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm const &obj);
		PresidentialPardonForm &operator=(PresidentialPardonForm const &obj);
		~PresidentialPardonForm();

		// MEMBER FUNCTIONS
		void execute(Bureaucrat const &bur) const;

	private :
		std::string target;

};

#endif