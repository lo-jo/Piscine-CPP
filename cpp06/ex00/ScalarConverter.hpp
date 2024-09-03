/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:56:43 by ljospin           #+#    #+#             */
/*   Updated: 2023/09/08 11:46:17 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include "convert.hpp"

class ScalarConverter{
	public :
	ScalarConverter();
	ScalarConverter(ScalarConverter const &obj);
	ScalarConverter& operator=(ScalarConverter const &obj);
	~ScalarConverter();
	
	static void convert(std::string value);
	

	private:
	
};



#endif