/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 12:32:44 by ljospin           #+#    #+#             */
/*   Updated: 2023/09/15 13:20:51 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP


#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include <list>
#include <iterator>
#include <algorithm> // find


class NumberNotFoundException : public std::exception{
	public :
	virtual const char* what() const throw(){
		return "No match found";
	}
};


// easyfind function : find the int value in the T(container) passed as argument
// container = collection of objects
// the data stored in the container can be accessed through iterators
// iterators = references to elements of the containers
// std::find template <class InputIterator, class T>   InputIterator find (InputIterator first, InputIterator last, const T& val);
// Returns an iterator to the first element in the range [first,last) that compares equal to val. If no such element is found, the function returns last.

template <typename T>
typename T::const_iterator	easyfind(T container, int val){
typename T::const_iterator target = find(container.begin(), container.end(), val);
if (target == container.end())
	throw NumberNotFoundException();

return target;
}

#endif