/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 12:32:34 by ljospin           #+#    #+#             */
/*   Updated: 2023/09/15 12:56:58 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <list>

template <typename T>
class MutantStack : public std::stack<T> {
	private:
 		std::deque<T> c; // standard container
/*
std::stack member functions :
*/
 public:
	MutantStack() : std::stack<T>(), c(std::deque<T>()){
		//By default, if no container class is specified for a particular stack class instantiation, the standard container std::deque is used.
		std::cout << "MutantStack contructor called" << std::endl;
	}

	MutantStack(const MutantStack<T> &obj) : std::stack<T>(obj){ // 
		std::cout << "MutantStack copy constructor called" << std::endl;
	} // Copy-constructs the underlying container c with the contents of cont. This is also the default constructor. (until C++11)

	MutantStack &operator=(const MutantStack &obj) {
		std::cout << "MutantStack assignment operator" << std::endl;
		if (this != &obj)
			 std::stack<T>::operator=(obj);
		return *this;
	}

	~MutantStack(){
		std::cout << "MutantStack destructor called" << std::endl;
	}

	typedef typename std::stack<T>::container_type::iterator iterator;

	iterator begin() {
		return std::stack<T>::c.begin();
	}

	iterator end() {
		return std::stack<T>::c.end();
	}
/*
/rbegin 
/rend 
also possible iterators in std::deque
can't be bothered to implement !!
*/
};