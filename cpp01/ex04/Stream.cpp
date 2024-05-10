/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stream.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 13:52:11 by ljospin           #+#    #+#             */
/*   Updated: 2023/07/12 16:34:34 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Stream.hpp"

Stream::Stream(std::string fileName, std::string s1, std::string s2) : 
	fileName(fileName), 
	s1(s1), 
	s2(s2), 
	newFileName(fileName + ".replace"){
	return;
}

Stream::~Stream(){
	return;
}

void Stream::readFile()
{
	std::ifstream myfile(this->fileName.c_str());
	if (!myfile)
		std::cout << "Error : Cannot open file" << std::endl;
	else{
		if (!is_empty_file(this->fileName) && !is_empty_arg(this->s1, this->s2)){
			std::ofstream newFile(this->newFileName.c_str());
			std::string line;
			while(std::getline(myfile, line))
				editLine(newFile, this->s1, this->s2, line + "\n");
			myfile.close(); // ifstream destructor automatically closes but w/e
			newFile.close();
		}
	}
}
