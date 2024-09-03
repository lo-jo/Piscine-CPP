/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 12:32:59 by ljospin           #+#    #+#             */
/*   Updated: 2023/09/15 12:51:21 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main(){
	Span testSp(15);

	testSp.addNumber(6);
	testSp.addNumber(3);
	testSp.addNumber(17);
	testSp.addNumber(9);
	testSp.addNumber(11);
	std::cout << "Starting with :" << std::endl;
	print_span(testSp.storage);

	std::cout << "shortest span :" << testSp.shortestSpan() << std::endl;
	std::cout << "longest span :" << testSp.longestSpan() << std::endl;


	std::cout << "Preparing values to add back:" << std::endl;
	std::vector<int> veckie(10,666);

	print_span(veckie);
	testSp.addNumber(veckie.begin(), veckie.end());

	std::vector<int>::iterator end = testSp.storage.end()-1;
	std::cout <<  *end << std::endl;
	print_span(testSp.storage);


	std::cout << "********** MORE TESTS ************" << std::endl;
	{
		std::cout << "Testing bigger storage size " << std::endl;
		Span bigSpan(10002);
		std::cout << "Preparing values to add back:" << std::endl;
		std::vector<int> veckie(10001,666);
		bigSpan.addNumber(veckie.begin(), veckie.end());
		bigSpan.addNumber(999);
		std::vector<int>::iterator end = bigSpan.storage.end()-1;
		std::cout << "last value should be 999 : " << *end << std::endl;
		std::cout << "size : " << bigSpan.storage.size() << std::endl;
		
	}
	std::cout << ">>test Max storage capacity exceeded" << std::endl;
	try {
		Span SecondSpan(2);
		SecondSpan.addNumber(0);
		SecondSpan.addNumber(1);
		SecondSpan.addNumber(2);
	}
	catch (std::exception &e){
		std::cout << RED << e.what() << RESET << std::endl;
	}
	std::cout << std::endl << ">>test shortest span" << std::endl;
	try {
		Span ThirdSpan(1);
		ThirdSpan.addNumber(0);
		ThirdSpan.shortestSpan();
	}
	catch (std::exception &e){
		std::cout << RED<<  e.what() << RESET << std::endl;
	}
	std::cout << std::endl << ">>Addnumber(it, it) max storage" << std::endl;
	try {
		Span FourthSpan(1);
		FourthSpan.addNumber(0);
		FourthSpan.addNumber(veckie.begin(), veckie.end());
	}
	catch (std::exception &e){
		std::cout << RED<<  e.what() << RESET << std::endl;
	}
	return 0;
}