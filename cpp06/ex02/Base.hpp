/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 11:23:33 by ljospin           #+#    #+#             */
/*   Updated: 2023/09/11 12:14:58 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <string>
#include <ctime>
#include <iostream>
#include <cstdlib>

class Base {
 public:
	virtual ~Base();
};

class A : public Base {
 public:
	~A();
};

class B : public Base {
 public:
	~B();
};

class C : public Base {
 public:
	~C();
};


Base* generate(void);
void identify(Base *p);
void identify(Base &p);

#endif