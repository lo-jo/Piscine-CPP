/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 14:52:14 by ljospin           #+#    #+#             */
/*   Updated: 2023/09/25 13:18:26 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <algorithm>
#include <stack>
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <limits.h>
#include <exception>

#include <cstdlib>

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

class RPN{
	public:
	RPN();
	RPN(RPN const &obj);
	RPN &operator=(RPN const &obj);
	~RPN();

	// METHODS
	void calculator(std::string const &arg);
	int makeCalculation(int a, int b, char c);
	
	private :
	std::stack<int> opstack;

};


#endif