/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parsing.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 14:52:03 by ljospin           #+#    #+#             */
/*   Updated: 2023/09/25 12:33:31 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parsing.hpp"

bool	is_empty_file(std::string path){
	int i = 0;
	std::ifstream myfile(path.c_str());
	std::string line;

	while(std::getline(myfile, line))
		i++;
	if (i == 0){
		std::cout << "Error : Empty file" << std::endl;
		return 1;
	}
	return 0;
}

bool	is_valid_format(std::string line){

	
	if (line.size() < 14 || line.find("|") == std::string::npos || line.find("|") != 11){
		std::cout << RED "Error : bad input > " RESET << line << std::endl;
		return 0;
	}

	return 1;
}

bool	is_digits(std::string &str){

	for (unsigned long i = 0; i < str.size(); i++){
		if (str[i] == '.' || str[i] == '-' || isspace(str[i]))
			i++;
		if (!isdigit(str[i]))
			return 0;
	}
	return 1;
}

int    isvalid_dateval(int year, int month, int day)
{
	bool is_leapyear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    if (month >= 1 && month <= 12){
        if (month == 2){
            if (day >= 1 && day <= (is_leapyear ? 29 : 28))
                return (1);
            }
        else if (month == 4 || month == 6 || month == 9 || month == 11){
            if (day >= 1 && day <= 30)
                return (1);
            }
        else{
        	 if (day >= 1 && day <= 31)
            	 return (1);
            }
        }
    return (0);
}

bool	is_valid_date(std::string const line){
	int yearv, monthv, dayv;
	std::string year, month, day;
	if (line[7] != '-' || line[4] != '-'){
		std::cout << RED "Error : invalid date format > " RESET << line << std::endl;
		return 0;
	}
	year = line.substr(0, 4);
	month = line.substr(5, 2);
	day = line.substr(8, 2);

	yearv = atof(year.c_str());
	monthv = atof(month.c_str());
	dayv = atof(day.c_str());

	if (is_digits(year) && is_digits(month) && is_digits(day) && isvalid_dateval(yearv, monthv, dayv))
		return 1;
	std::cout << RED "Error : invalid date > " RESET << line << std::endl;
	return 0;
}

bool is_valid_value(std::string const line){
	std::string value = line.substr(line.find("|") + 2, line.size()  - 1);
	if (!is_digits(value)){
		std::cout << RED "Error : invalid value (not a digit) > " RESET << line << std::endl;
		return 0;
	}
		
	else if(atof(value.c_str()) < 0 || atof(value.c_str()) > 1000)
	{
		std::cout << RED "Error : invalid value (out of range) > " RESET << line << std::endl;
		return 0;
	}	
	return 1;
}

