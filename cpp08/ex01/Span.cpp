/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 12:33:03 by ljospin           #+#    #+#             */
/*   Updated: 2023/09/15 12:49:33 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(int N) : max(N){
	std::cout << "Span constructor called, class can store " << max << " integers" << std::endl;
}

Span::Span(Span const &obj) : max(obj.max){
	*this = obj;
}

Span& Span::operator=(Span const &obj){
	if (this != &obj){
		max = obj.max;
		storage = obj.storage;
	}
	return *this;
}

Span::~Span(){
	std::cout << "Span destructed" << std::endl;
}

// adds one single number to the class
void	Span::addNumber(int number){
	if (this->storage.size() >= max)
		throw Span::FullStorageException();
	else
		storage.push_back(number);

}


void 	print_span(std::vector<int> spansrc){
	std::cout << std::endl << "***** SPAN *****" << std::endl;
	for(std::vector<int>::iterator it = spansrc.begin(); it != spansrc.end(); it++){
		std::cout<< *it << std::endl;
	}
}

int Span::shortestSpan(){ // returns shortest distance between all the numbers stored
	if (storage.size() <= 1) // if there are no numbers stored or only one
		throw Span::SpanNotFoundException();
	std::vector<int> sorted = storage;
	std::sort(sorted.begin(), sorted.end());
	int shortest = sorted[1] - sorted[0];

	for (std::vector<int>::iterator i = sorted.begin()+2; i < sorted.end() - 1; ++i){
		if (*(i +1) - *i < shortest)
			shortest = *(i + 1) - *i;
	}
	return shortest;
}

int Span::longestSpan(){
	if (storage.size() <= 1)
		throw Span::SpanNotFoundException();
	std::vector<int> sorted = storage;
	std::sort(sorted.begin(), sorted.end());

	// std:: max(sorted.begin()) et min
	//return max-min
	int longest = sorted[sorted.size()-1] - sorted[0];
	return longest;
}


// adding back a range of data to a vector
void Span::addNumber(std::vector<int>::iterator start, std::vector<int>::iterator end){
	if (storage.size() + std::distance(start, end) > max)
		throw Span::FullStorageException();
	// container.insert(pos, rg.cbegin(), rg.cend());
	storage.insert(storage.end(), start, end); // adding back new values
}





const char* Span::FullStorageException::what() const throw(){
	return "Max storage capacity exceeded";
}

const char* Span::SpanNotFoundException::what() const throw(){
	return "Span not found";
}

















// /**
//  * @brief Getter for the _n attribute.
//  * 
//  * @return int _n
//  */
// int Span::getN() const {
//     return this->_n;
// }

// /**
//  * @brief Getter for the _numbers attribute.
//  * 
//  * @return const std::vector<int>& _numbers
//  */
// const std::vector<int> &Span::getNumbers() const {
//     return this->_numbers;
// }