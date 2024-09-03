/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displayResults.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 11:18:14 by ljospin           #+#    #+#             */
/*   Updated: 2023/09/08 11:37:08 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void	displayChar(int lit)
{
	std::cout << "char: ";
	if (lit <= 32 || lit == 127)
		std::cout << "Non displayable" << std::endl;
	else if (lit < 0 || lit > 127)
		std::cout << "impossible" << std::endl;
	else
		std::cout << "'" << static_cast< char >(lit) << "'" << std::endl;
}


void displayFloat(float lit, std::string value){
	int fidx = value.find("f");
	std::string fstring = "f";
	int prec = value.size() - value.find(".") - 1;
	
	// when string has an f (float)
	if (static_cast<const unsigned long>(fidx) != std::string::npos ){
		
		fstring = value.substr(fidx, value.size());
		prec = value.size() - value.find(".") - (value.size() - fidx) - 1;
	}
	if (value == "+inff" || value == "-inf")
		fstring = "f";
	std::cout << std::fixed << "float: " << std::setprecision(prec)  << lit << fstring << std::endl;
	std::cout << std::fixed << "double: " << std::setprecision(prec) << static_cast<double>(lit) << std::endl;
}

