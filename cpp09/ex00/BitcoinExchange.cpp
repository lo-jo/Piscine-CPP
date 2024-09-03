/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 14:51:13 by ljospin           #+#    #+#             */
/*   Updated: 2023/09/25 11:58:45 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


//********************************** CANONICAL **********************************************//
BitcoinExchange::BitcoinExchange(){
	std::cout << "Bitcoin created" << std::endl;
}
BitcoinExchange::~BitcoinExchange(){
	std::cout << "Bitcoin destructed" << std::endl;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &obj) : data(obj.data){
	*this = obj;
}

BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange const &obj){
	if (this != &obj)
		data = obj.data;
	return *this;

}

// ******************************************************************************************//

// ********************************* MEMBER FUNCTIONS ***************************************//
// Read from data.csv
// no parsing should be done here (Not required by subject)
// extract key | value pairs from file to std::map data

void	BitcoinExchange::extractData(){
	std::ifstream 	myfile("./data.csv");
	std::string		line;
	std::string 	key;
	std::string		fvalue;
	float 			value;

	if (!myfile){
		std::cout << RED "Error : cannot open file" RESET << std::endl;
		exit (1);
		//return ;
	}
	while(std::getline(myfile, line)){
		key = line.substr(0, 10);
		fvalue = line.substr(line.find(",") + 1, line.size());
		value = atof(fvalue.c_str());
		// inserting data in std::map data
		data.insert(std::make_pair(key, value));
	}
	myfile.close();
	//printDataMap();
}

void BitcoinExchange::printDataMap(){
	std::cout << YEL "DATA CONTAINS :" RESET << std::endl;
	std::multimap<std::string, float>::iterator it;
	for (it = data.begin(); it != data.end(); ++it)
		std::cout << "* "<<it->first << " | " << it->second << std::endl;
}


void BitcoinExchange::findRate(BitcoinExchange &inpt, std::multimap<std::string, float>::iterator rinpt){
	// parcourir inpt.data
	// find key in data
	(void)inpt;
	std::multimap<std::string, float>::iterator it;
	std::multimap<std::string, float>::iterator ptr;
	
		if (data.find(rinpt->first) != data.end()){
			ptr = data.find(rinpt->first);
			std::cout << rinpt->first << " => " << rinpt->second << " = " << rinpt->second * ptr->second << std::endl;
		}
		else {
			if (data.lower_bound(rinpt->first) != data.end()) // if lower bound found
			{
				ptr = data.lower_bound(rinpt->first);
				if (ptr != data.begin())
					ptr--;
				std::cout << rinpt->first << "(" << ptr->first << ")"
				<< " => " << rinpt->second << " = " << rinpt->second * ptr->second << std::endl;
			}
			else { // else just use the last date
				std::multimap<std::string, float>::reverse_iterator rlowerit = this->data.rbegin();
				std::cout << rinpt->first << BLUE "("<< rlowerit->first << ")"RESET 
				<< " =>" << rinpt->second << " = " << rinpt->second * rlowerit->second 
				<< std::endl;
			}

		}
}


void	BitcoinExchange::extractInput(std::string line, BitcoinExchange &inpt){
	std::string	key;
	std::string	value;
	float 		fvalue;

	key = line.substr(0, 10);
	value = line.substr(line.find("|") + 2, line.size()  - 1);
	fvalue = atof(value.c_str());
	inpt.data.insert(std::pair<std::string, float>(key, fvalue));
	this->findRate(inpt, inpt.data.find(key));
}


void	BitcoinExchange::parseLine(std::string line, BitcoinExchange &inpt){
	if (is_valid_format(line) && is_valid_date(line) && is_valid_value(line)){
		extractInput(line, inpt);
	}
}

void	BitcoinExchange::parseInput(std::string path, BitcoinExchange &inpt){
	std::ifstream input(path.c_str());
	if (!input){
		std::cout << RED "Error : cannot open file" RESET << std::endl;
		return ;
	}
	else{
		if (!is_empty_file(path)){
			std::string line;
			while(std::getline(input, line)){
				parseLine(line, inpt);
			}
		}
		input.close();
	}
	//inpt.printDataMap();
}