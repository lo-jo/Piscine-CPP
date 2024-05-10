/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 11:04:01 by ljospin           #+#    #+#             */
/*   Updated: 2023/07/05 11:03:11 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "awesomePhoneBook.hpp"
#include "Contact.hpp"

/* PHONEBOOK CLASS*/
class PhoneBook {
	public :
	PhoneBook();
	~PhoneBook();
	void addContact();
	void searchContact();
	void start();
	void findContact();
	void displayContact(Contact nbr);
	
	private :
	Contact contact[8];
	int 	maxContact;
	int		idx;
	void 	fillContactTable(Contact *contact);
	void 	retrieveInfo(Contact& info, std::string type);
	void 	displaySearchMenu(int i, Contact contact);
	std::string truncInfo(std::string info);
};

#endif