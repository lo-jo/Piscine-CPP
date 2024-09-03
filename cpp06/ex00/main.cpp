/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 15:00:40 by ljospin           #+#    #+#             */
/*   Updated: 2023/09/08 11:41:42 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"



int main(int argc, char **argv){
	ScalarConverter Converter;
	
	if (argc != 2){
		std::cout << "Invalid number of arguments" << std::endl;
		return 1;
	}
	Converter.convert(argv[1]);
/*
	{
		float nanf = 0.0f / 0.0f;
		double nan = nanf;
		
		std::cout << nanf << std::endl;
		std::cout << nan << std::endl;

		float neginf = -1.0f / 0.0f;
		std::cout << "float :" <<  neginf << std::endl;
		std::cout << static_cast<int>(neginf) << std::endl;
		std::cout << static_cast<double>(neginf) << std::endl;

		float posinf = 1.0f / 0.0f;
		std::cout << "float :" <<  posinf << std::endl;
		std::cout << "int impossible cannot be represented as an int" << static_cast<int>(posinf) << std::endl;
		std::cout << static_cast<double>(posinf) << std::endl;
	}
*/
	return 0;
}