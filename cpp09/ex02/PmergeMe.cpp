/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 14:52:23 by ljospin           #+#    #+#             */
/*   Updated: 2024/09/03 14:50:05 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

///////////////////////// CANONICAL /////////////////////////////
PmergeMe::PmergeMe(unsigned int *arr, int size) : size(size){
	
	this->arr = arr;
	this->is_odd = 0;
	//new unsigned int[argc -1]
	std::cout << "PmergeMe object created" << std::endl;
}

PmergeMe::~PmergeMe(){
	std::cout << "PmergeMe object destructed" << std::endl;
	//delete[] arr;
}

PmergeMe::PmergeMe(PmergeMe const &obj) : arr(obj.arr), vec(obj.vec), sequence(obj.sequence){
	*this = obj;
}

PmergeMe& PmergeMe::operator=(PmergeMe const &obj){
	if (this != &obj){
		arr = obj.arr;
		vec = obj.vec;
		sequence = obj.sequence;
	}
		
	return *this;
}

////////////////////////// METHODS /////////////////////////////

void PmergeMe::displayArr(){
	for (int i = 0; i < size; i++)
		std::cout << YEL << arr[i] << RESET << " ";
	//displaySimpleVec();
	std::cout << std::endl;
}

void PmergeMe::displaySort(){
	std::cout << "Before         | ";
	displayArr();
	std::cout << "After (vector) | " BLUE;
	displaySimpleVec();
	std::cout << RESET;
}
