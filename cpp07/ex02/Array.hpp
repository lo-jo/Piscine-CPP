/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:42:46 by ljospin           #+#    #+#             */
/*   Updated: 2023/09/11 14:42:47 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string>
#include <exception>
#include <cstdlib>
template <typename T>
class Array{
	public:
	Array<T>() : arr(NULL), asize(0){
		std::cout << "Array default constructor" << std::endl;
	} // creates empty arr

	Array<T>(unsigned int n) : arr(new T[n]), asize(n){
		std::cout << "Array adhoc constructor" << std::endl;
		std::cout << "Array of " << asize << " created" << std::endl;
	} // creates array of n el initialised by default

	Array<T>(Array const &obj) : 
		arr(new T[obj.asize]), 
		asize(obj.asize){
		std::cout << "Array copy constructor" << std::endl;
		for (int i = 0; i < asize; i++)
			arr[i] = obj.arr[i];
	} //copy constrrcutor


	Array<T>& operator=(const Array<T> &obj){
		std::cout << "assignment operator called" << std::endl;
		if (this != &obj){
			if (arr)
				delete[] arr;
			asize = obj.asize;
			arr = new T[asize];
			for (int i = 0; i < asize; i++)
				arr[i] = obj.arr[i];
		}
		return (*this);
	}


	~Array<T>(){
		if (arr)
			delete[] arr;
		std::cout << "Array destructor called" << std::endl;
	}

	T &operator[](int i){
		if (i >= asize)
			throw Array::OutOfBoundsArr();
		return (arr[i]);
	}


	int size(void) const{ // This member function takes no parameter and musn’t modify the current instance.
		return (asize);
	}

	class OutOfBoundsArr : public std::exception{
		public :
			virtual const char* what() const throw(){
				return "Out of bounds";
			}
	};

	private:
	T 	*arr;
	int asize;
};

#endif