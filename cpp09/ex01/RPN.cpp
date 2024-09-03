/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 14:52:11 by ljospin           #+#    #+#             */
/*   Updated: 2023/09/25 13:32:19 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(){
	std::cout << "RPN object created " << std::endl;
}

RPN::~RPN(){
	std::cout << "RPN object destructed " << std::endl;		
}

RPN::RPN(RPN const &obj) : opstack(obj.opstack){
	*this = obj;
}

RPN& RPN::operator=(RPN const &obj){
	if (this != &obj)
		opstack = obj.opstack;
	return *this;
}

bool isValidNumber(char c){
	return (c >= '0' && c <= '9');
}

int RPN::makeCalculation(int x, int y, char c) {
	switch (c) {
		case '+':
			return y + x;
		case '-':
			return y - x;
		case '*':
		{
			if (x != 0 && y != 0){
				if ((x > (INT_MAX) / y) || (x < INT_MIN / y))
					throw std::invalid_argument("Error : Overflow");}
			return y * x;
		}
			
		case '/':
		{
			if (x == 0) {
				throw std::invalid_argument("Error : Division by zero");
			}
			return y / x;
		}
		default:
		{
			throw std::invalid_argument("Error : Invalid operator");
		}
			
	}

}

//2147483647
// tests 
/*
./RPN  "9 0 / 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 *"
./RPN  "9 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 *"
./RPN  "9 9 y 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 *"
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
./RPN "7 7 * 7 -"
./RPN "1 2 * 2 / 2 * 2 4 - +"
./RPN "(1 + 1)"
*/

void RPN::calculator(std::string const &line){
	std::stringstream ss(line);
	std::string token;
	int x, y;
	char c;
	if (line.empty()){
		std::cout << "Error : Empty input" << std::endl;
		this->~RPN();
		ss.clear();
		exit (1);
	}
	while (!ss.eof()) {
		ss >> token;
		if (token.length() == 1 && isValidNumber(token[0])) {
			this->opstack.push(atoi(token.c_str())); // if its a number > push it to the stack
		} else if (token.length() == 1 && !isValidNumber(token[0])) { // operator detected
			if (this->opstack.size() < 2) { 
				std::cout << RED "Error: operation impossible" RESET << std::endl;
				return;
			}
			x = this->opstack.top(); // store top nb in x
			this->opstack.pop(); // empty top
			y = this->opstack.top(); // store next nb in y
			this->opstack.pop(); // empty
			c = token[0]; // operator
			try{
				this->opstack.push(makeCalculation(x, y, c)); // store result in stack top
				}
			catch (std::exception &e){
				std::cout << e.what() << std::endl;
				return ;
			}
		} else {
			std::cout << "Error: Invalid input" << std::endl;
			return;
		}
	}
	if (this->opstack.size() > 1) {
		std::cout << "Error: Operation impossible (not enough operator)" << std::endl;
		return;
	}
	std::cout << this->opstack.top() << std::endl;
}