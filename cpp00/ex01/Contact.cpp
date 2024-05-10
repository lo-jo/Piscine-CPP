/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 12:12:54 by ljospin           #+#    #+#             */
/*   Updated: 2023/07/05 11:03:36 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {
	return;
}
Contact::~Contact() {
	return;
}

std::string	Contact::getInfo(std::string str) const{
	if(str == FN_MSG)
		return(this->firstName);
	else if (str == LN_MSG)
		return(this->lastName);
	else if (str == NN_MSG)
		return(this->nickName);
	else if (str == PN_MSG)
		return(this->phoneNbr);
	else if (str == DS_MSG)
		return(this->darkestSecret);
	else
		return(NULL);
}

void	Contact::setInfo(std::string str, std::string type){
	if (type == FN_MSG)
		this->firstName = str;
	else if (type == LN_MSG)
		this->lastName = str;
	else if (type == NN_MSG)
		this->nickName = str;
	else if (type == PN_MSG)
		this->phoneNbr = str;
	else if (type == DS_MSG)
		this->darkestSecret = str;
}