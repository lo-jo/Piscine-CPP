/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 11:03:38 by ljospin           #+#    #+#             */
/*   Updated: 2023/07/05 11:17:46 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phoneBook.hpp"

/* The constructor is called upon every object creation
* Good practice should be using it to initalise the object values,
* Which I didnt do here :/ */

PhoneBook::PhoneBook(){ // constructor
	std::cout << WBG << YEL  << "~  WELCOME 2 PHONEBOOK  ~" << RESET << std::endl;
	std::cout << "\n* Type in \"ADD\", \"SEARCH\" or\"EXIT\" to start using." << std::endl << std::endl;
	return;
}

PhoneBook::~PhoneBook(){ // destructor
	std::cout << YEL << "Thx 4 using Phonebook, see u next time ~" << RESET << std::endl;
	return;
}

void	PhoneBook::fillContactTable(Contact* contact){
	if (maxContact < 8){
		this->contact[idx] = *contact;
		maxContact++;
		idx++;}
	else {
		if (idx == 8)
			idx = 0;
		this->contact[idx] = *contact;
		idx++;
	}
}	

std::string PhoneBook::truncInfo(std::string info)
{
	if (info.length() > 10)
		return(info.substr(0, 9) + ".");
	return(info);
}

void	PhoneBook::displaySearchMenu(int index, Contact contact){
	std::cout << std::setw(10) << index << "|";
	std::cout << std::setw(10) << truncInfo(contact.getInfo(FN_MSG)) << "|";
	std::cout << std::setw(10) << truncInfo(contact.getInfo(LN_MSG)) << "|";
	std::cout << std::setw(10) << truncInfo(contact.getInfo(NN_MSG)) << std::endl;
}

void	PhoneBook::displayContact(Contact contact){
	
	std::cout << WBG << MAG  << "CONTACT INFORMATION" << RESET << std::endl;
	std::cout << "FIRST NAME: " << contact.getInfo(FN_MSG) << std::endl;
	std::cout << "LAST NAME: " << contact.getInfo(LN_MSG) << std::endl;
	std::cout << "NICKNAME: " << contact.getInfo(NN_MSG) << std::endl;
	std::cout << "PHONE NUMBER: " << contact.getInfo(PN_MSG) << std::endl;
	std::cout << "(darkest secret sssh...): " << contact.getInfo(DS_MSG) << std::endl <<std::endl;
}

void	PhoneBook::findContact(){
	std::string cmd;
	
	while(1){
	std::cout << "Enter Contact Index :" << std::endl << ">";
	std::getline(std::cin, cmd);
	
	int	id = atoi(cmd.c_str());
	if (id <= 0 || id > this->maxContact)
		std::cout << "Invalid Index" << std::endl;
	else {
		displayContact(this->contact[id - 1]);
		break;}
	}
}	

void	PhoneBook::searchContact(){
	if(this->maxContact == 0){
		std::cout << "No contacts yet" << std::endl;
		return ;
	}
	std::cout << std::setw(10) << "INDEX" << "|";
	std::cout << std::setw(10) << "FIRST NAME" << "|";
	std::cout << std::setw(10) << "LAST NAME" << "|";
	std::cout << std::setw(10) << "NICK NAME" << std::endl;
	for(int i = 0; i < this->maxContact; i++){
		displaySearchMenu(i + 1, this->contact[i]);} // i+1 to discard 0 in order to make use of atoi error case
	findContact();
}

/* Retrieves std in with getline and stores it in the corresponding field variable */
void 	PhoneBook::retrieveInfo(Contact& info, std::string type){
	std::string	str;

	std::cout << type << std::endl;
	std::getline(std::cin, str);
	if (str.length() > 0)
		info.setInfo(str, type); // Bypasses private class attribute access 
	else {
		std::cout << "Empty fields make Phonebook really unhappy :(" << std::endl;
		retrieveInfo(info, type);}
}

/* Creates a new contact object, initialises its attributes 
* and adds back the contact to the phonebook contact table*/
void	PhoneBook::addContact(){
	Contact	contact;
	std::cout << WBG << MAG  << "ADD NEW CONTACT" << RESET << std::endl;
	retrieveInfo(contact, FN_MSG);
	retrieveInfo(contact, LN_MSG);
	retrieveInfo(contact, NN_MSG);
	retrieveInfo(contact, PN_MSG);
	retrieveInfo(contact, DS_MSG);
	fillContactTable(&contact);
}

void	PhoneBook::start() {
	std::string cmd;
	maxContact = 0;
	idx = 0;
	while(1){
		std::cout << "Enter a command :" << std::endl;
		std::cout << MAG << ">" << RESET;
		std::getline(std::cin, cmd);
		if (cmd == "ADD")
			addContact();
		else if (cmd == "SEARCH")
			searchContact();
		else if (cmd == "EXIT")
			break ;
		else 
			std::cout << "Phonebook only accepts the following entries : ADD, SEARCH and EXIT" << std::endl;
	}
}