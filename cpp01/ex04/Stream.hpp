#ifndef STREAM_HPP
#define STREAM_HPP

#include <iostream>
#include <fstream> 
#include <string>

class Stream{
	public:
		Stream(std::string fileName, std::string s1, std::string s2);
		~Stream();
		void	readFile();

	private:
	std::string fileName;
	std::string	s1;
	std::string s2;
	std::string newFileName;
	std::string extract;
	
};

void	editLine(std::ofstream &newFile, std::string s1, std::string s2, std::string line);
bool	is_empty_file(std::string path);
bool	is_empty_arg(std::string s1, std::string s2);

#endif