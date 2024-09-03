/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 12:32:47 by ljospin           #+#    #+#             */
/*   Updated: 2023/09/15 13:21:19 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main(){
{
	std::vector<int> vec;// creating vector container
	//storing some values
	try{
		vec.push_back(0);
		vec.push_back(1);
		vec.push_back(2);
		vec.push_back(3);
		vec.push_back(666);
		for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
			std::cout << *it << std::endl;
		}
		std::cout << "easyFinding the value 666 in vector : " <<  *easyfind(vec, 666) << std::endl;
		std::cout << "easyFinding the value 777 in vector : " <<  *easyfind(vec, 777) << std::endl;
	}
	catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
}

{
//////////// SAME BUT WITH LISTS
	std::list<int> listt;
	listt.push_back(60);
	listt.push_back(70);
	listt.push_back(80);
	listt.push_back(90);
	listt.push_back(888);

// displaying the list
	for (std::list<int>::iterator lit = listt.begin(); lit != listt.end(); ++lit)
		std::cout << *lit << std::endl;
// testing easyfind function
	try{
		std::cout << "easyFinding the value 90 in list : " << *easyfind(listt, 90) << std::endl;
		std::cout <<  "easyFinding the value 777 in list : " << *easyfind(listt, 777) << std::endl;
	}
	catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
}
	return 0;
}