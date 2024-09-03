/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:42:34 by ljospin           #+#    #+#             */
/*   Updated: 2023/09/11 14:42:35 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template <typename T>
void print(T& arg) {
	std::cout << arg;
}

int main(){
	int intArray[] = {1, 2, 3, 4, 5};
	char charArr[] = "life is getting quite exciting";
	int sizeint = sizeof(intArray) / sizeof(int);
	int sizechar =  sizeof(charArr)/sizeof(char);
	iter(intArray, sizeint, print<int> );
	std::cout << std::endl;
	iter(charArr, sizechar, print<char>);
	std::cout << std::endl;


	return 0;
}