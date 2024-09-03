/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:42:24 by ljospin           #+#    #+#             */
/*   Updated: 2023/09/11 14:42:25 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATE_HPP
#define TEMPLATE_HPP

#include <iostream>
#include <string> 

template <typename T>
T min(const T& a, const T& b){
	if (a < b)
		return a;
	return b;
}

template <typename T>
T max(const T& a, const T& b){
	if (a > b)
		return a;
	return b;
}

template<typename T>
void swap(T& a, T& b){
	T temp;
	temp = a;
	a = b;
	b = temp;

}

#endif