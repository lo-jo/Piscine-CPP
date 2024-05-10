#ifndef CONTACT_HPP
#define CONTACT_HPP

#include "awesomePhoneBook.hpp"

class Contact {
	public :
	Contact();
	~Contact();
	void setInfo(std::string str, std::string info);
	std::string getInfo(std::string str) const;

	private :
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string phoneNbr;
	std::string darkestSecret;
};

#endif