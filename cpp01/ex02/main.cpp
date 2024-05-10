/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 09:24:14 by ljospin           #+#    #+#             */
/*   Updated: 2023/07/05 10:53:28 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream> 
#include <string>

// ANSI COLORS
#define RESET "\x1B[0m"
#define YEL "\x1B[33m"

/*
Une variable de type string initialisée à "HI THIS IS BRAIN".
• stringPTR: A pointer to the string.
• stringREF: A reference to the string.
Your program has to print:
• The memory address of the string variable.
• The memory address held by stringPTR.
• The memory address held by stringREF.
And then:
• The value of the string variable.
• The value pointed to by stringPTR.
• The value pointed to by stringREF*/

int main(){
	std::string  string = "HI THIS IS BRAIN";
	std::string* stringPTR = &string;
	std::string& stringREF = string;

	std::cout << YEL << "-- MEMORY ADDRESSES --" << RESET << std::endl;
	std::cout << "• The memory address of the string variable : " << &string << std::endl;
	std::cout << "• The memory address held by stringPTR  : " << stringPTR << std::endl;
	//std::cout << ". Will not be the same as its actual address " << &stringPTR << std::endl;
	std::cout << "• The memory address held by stringREF : " << &stringREF << std::endl;
	std::cout<< YEL << "-- VALUES --" << RESET << std::endl;
	std::cout << "• The value of the string variable : " << string << std::endl;
	std::cout << "• The value pointed to by stringPTR : " << *stringPTR << std::endl;
	std::cout << "• The value pointed to by stringREF : " << stringREF << std::endl;
	return(0);
}