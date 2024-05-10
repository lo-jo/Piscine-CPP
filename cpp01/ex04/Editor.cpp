/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Editor.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:01:29 by ljospin           #+#    #+#             */
/*   Updated: 2023/07/12 16:34:41 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Stream.hpp"

void	editLine(std::ofstream &newFile, std::string s1, std::string s2, std::string line)
{
	size_t	pos = line.find(s1);
	size_t	newPos;

	if (pos != std::string::npos){
		newFile << line.substr(0, pos);
		newFile << s2;
		newPos = pos + s1.length();
		editLine(newFile, s1, s2, line.substr(newPos));
	}
	else { // if no match was found on the current line, then just paste as is
		newFile << line;
		return ;
	}
}

bool	is_empty_arg(std::string s1, std::string s2){
	if (s1 == "" || s2 == ""){
		std::cout << "Cannot replace empty string" << std::endl;
		return 1;
	}
	return 0;
}

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