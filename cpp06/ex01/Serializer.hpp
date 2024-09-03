/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 10:55:10 by ljospin           #+#    #+#             */
/*   Updated: 2023/09/11 10:55:11 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP


#include <iostream>
#include <string>
#include <stdint.h>

// creating a data with member variables
struct Data {
	std::string str;
	std::string msg;
	int nbr;
};


class Serializer {
 private:
	Serializer();
	Serializer(Serializer const &obj);
	~Serializer();
	Serializer &operator=(Serializer const &obj);

 public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};

#endif