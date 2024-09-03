/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 11:45:19 by ljospin           #+#    #+#             */
/*   Updated: 2023/09/08 11:46:49 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_HPP
#define CONVERT_HPP

//LIBS
#include <iostream>
#include <string>
#include <ctype.h> //isalpha
#include <climits> //intminmax
#include <stdlib.h>
#include <stdio.h>
#include <cstdlib> //atoi
#include <iomanip> // setprcision


// ANSI COLORS
#define WBG "\x1B[47m"
#define RBG "\e[41m"
#define RESET "\x1B[0m"
#define BOLD "\x1B[1m"
#define MAG "\x1B[35m"
#define YEL "\x1B[33m"
#define RED "\x1B[31m"
#define BLK "\e[0;30m"
#define GREEN "\e[0;32m"
#define BLUE "\e[0;34m"

// TYPE DETECTION
bool	isChar(std::string lit);
bool	isInt(std::string lit);
bool	isFloat(std::string lit);
bool	isDouble(std::string lit);
bool	isPseudo(std::string lit);

//TYPE CONVERSION
void	convertChar(char c);
void	convertInt(int lit);
void	convertFloat(float lit, std::string value);
void	convertDouble(double lit, std::string value);
void	convertPseudo(std::string value);

// DISPLAY TYPE
void	displayChar(int c);
void	displayFloat(float lit, std::string value);


#endif
