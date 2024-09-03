/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:56:41 by ljospin           #+#    #+#             */
/*   Updated: 2023/09/11 12:23:35 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"


// CANONICAL
// default
ScalarConverter::ScalarConverter(){
	std::cout << "ScalarConverter Constructor Called" << std::endl;
}

//copy
ScalarConverter::ScalarConverter(ScalarConverter const &obj){
	*this = obj;
	std::cout << "Scalar Converter Copy constructor" << std::endl;
}

//assignment
ScalarConverter &ScalarConverter::operator=(ScalarConverter const &obj){
	(void) &obj;
	return (*this);
}

//destructor
ScalarConverter::~ScalarConverter(){
	std::cout << "ScalarConverter Destructed" << std::endl;
}

// METHODS
	// detect the literal passed as parameter
	// convert from string to actual type
	// convert it explicitely to the 3 other data types
	// display results

void	ScalarConverter::convert(std::string value)
{
	char *end;
	
	if (isChar(value))
		convertChar(value[0]);
	else if (isInt(value))
		convertInt(atol(value.c_str()));
	else if (isDouble(value))
		convertDouble(strtod(value.c_str(), &end), value);
	else if (isFloat(value))
		convertFloat(atof(value.c_str()), value);
	else if (isPseudo(value))
		convertPseudo(value);
	else
		std::cout << RED << "TYPE NOT FOUND" << RESET << std::endl;
}



