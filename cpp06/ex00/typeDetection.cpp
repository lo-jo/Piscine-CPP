/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typeDetection.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:05:26 by ljospin           #+#    #+#             */
/*   Updated: 2023/09/11 12:24:00 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

bool	isChar(std::string lit)
{
	if (lit.size() > 1 || !isalpha(lit[0]))
		return false;
	return true;
}

bool	isInt(std::string lit){
	if ( atol(lit.c_str()) > INT_MAX || atol(lit.c_str()) < INT_MIN)
		return false;
	for (int i = 0; lit[i]; i++){
		if (lit[i] == '-')
			i++;
		if (!isdigit(lit[i]))
			return false;
	}
	return true;
}

bool	isFloat(std::string lit){
	for (int i = 0; lit[i]; i++){
		if (!isdigit(lit[i]) && lit[i] != '.' && lit[i] != 'f' && lit[0] != '-')
			return (false);
	}
	if (lit.find('.') == std::string::npos || lit.find('.') == 0 || lit.find('.') == lit.size() - 1)
		return (false);
	if (lit.find('.') != lit.rfind('.'))
		return (false);
	return (true);
}
// same as float except no f
bool	isDouble(std::string lit)
{
	for (int i = 0; lit[i]; i++){
		if (!isdigit(lit[i]) && lit[i] != '.' && lit[0] != '-')
			return (false);
	}
	if (lit.find('.') == std::string::npos || lit.find('.') == 0 || lit.find('.') == lit.size() - 1)
		return (false);
	if (lit.find('.') != lit.rfind('.'))
		return (false);

	return (true);
}

bool isPseudo(std::string lit){
	if (lit == "-inff" || lit == "+inff" || lit == "-inf" || lit == "+inf")
		return(true);
	if (lit == "nanf" || lit=="nan")
		return(true);
	return (false);
	
}

