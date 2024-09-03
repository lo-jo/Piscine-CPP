/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typeConversion.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 11:17:22 by ljospin           #+#    #+#             */
/*   Updated: 2023/09/11 12:23:52 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void	convertChar(char c){
	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast< int >(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast< double >(c) << ".0" << std::endl;
}

void convertInt(int lit){
	displayChar(lit);
	std::cout << "int: " << lit << std::endl;
	std::cout << "float: " << static_cast< float >(lit) << ".0f" << std::endl;
	std::cout << "double: " << static_cast< double >(lit) << ".0" << std::endl;
}

void convertFloat(float lit, std::string value){
	int fidx = value.find('f');

	// dismiss inputs such as 55.95f0f
	if (static_cast<const unsigned long>(fidx) != std::string::npos ){
		if (value[fidx + 1] != 'f' && value[fidx +1] != '\0'){
			std::cout << "type not found" << std::endl;
			exit (1);
		}
	}
	displayChar(lit);
	if (static_cast<int>(lit) > INT_MAX || static_cast<int>(lit) < INT_MIN || isPseudo(value))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(lit) << std::endl;
	displayFloat(lit, value);
	
}

void convertDouble(double lit, std::string value){
	int prec = value.size() - value.find(".") - 1;
	
	displayChar(lit);
	std::cout << "int: " << static_cast<int>(lit) << std::endl;
	std::cout << std::fixed << "float: " << std::setprecision(prec)  << static_cast<float>(lit) << std::endl;
	std::cout << std::fixed << "double: " << std::setprecision(prec) << lit << std::endl;
}

void	convertPseudo(std::string value){
	float neginf = -1.0f / 0.0f;
	float posinf = 1.0f / 0.0f;
	float nanf = 0.0f / 0.0f;

	if (value == "+inff")
		convertFloat(static_cast<double>(posinf), value);
	else if (value == "-inff")
		convertFloat(static_cast<double>(neginf), value);
	else if (value == "+inf")
		convertFloat(posinf, value);
	else if (value == "-inf")
		convertFloat(neginf, value);
	else if (value == "nan" || value == "nanf")
		convertFloat(nanf, value);
}

