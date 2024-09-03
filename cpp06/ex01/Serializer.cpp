/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 10:53:36 by ljospin           #+#    #+#             */
/*   Updated: 2023/09/11 10:53:22 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(){
	std::cout << "Serializer Default constructor called" << std::endl;
}

Serializer::~Serializer(){
	std::cout << "Serializer destructor called" << std::endl;
}

Serializer::Serializer(Serializer const &obj){
	*this=obj;
}

Serializer &Serializer::operator=(Serializer const &obj){
	(void)obj;
	return *this;
}

// Takes a ppointer to a data struct as parameter and returns a uintptr_t
// that contains the adress of the data struct
// reinterpret_cast can be used to convert between pointer and integer types,
// between unrelated pointer types, between pointer-to-member types, 
// and between pointer-to-function types

uintptr_t Serializer::serialize(Data *ptr){
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw){
	return reinterpret_cast<Data*>(raw);
}
