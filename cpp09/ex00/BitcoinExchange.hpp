/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 14:51:16 by ljospin           #+#    #+#             */
/*   Updated: 2023/09/22 12:58:28 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
#include <string>
#include <cstdlib> 

#include <iterator>
#include <numeric>
#include <ctype.h>

#include "Parsing.hpp"

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

class	BitcoinExchange{
	public :
	BitcoinExchange();
	~BitcoinExchange();
	BitcoinExchange(BitcoinExchange const &obj);
	BitcoinExchange &operator=(BitcoinExchange const &obj);

	
	// MEMBER FUNCTION
	void	extractData();
	void 	printDataMap();
	void	findRate(BitcoinExchange &inpt, std::multimap<std::string, float>::iterator rinpt);
	void 	extractInput(std::string line, BitcoinExchange &inpt);
	void	parseLine(std::string line, BitcoinExchange &inpt);
	void	parseInput(std::string path, BitcoinExchange &inpt);

	private :
		std::multimap<std::string, float> data;
};



#endif