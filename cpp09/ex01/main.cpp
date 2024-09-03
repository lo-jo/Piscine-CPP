/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 14:52:09 by ljospin           #+#    #+#             */
/*   Updated: 2023/09/22 14:15:52 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "RPN.hpp"

int main(int argc, char **argv){
	RPN	operation;
	
	if (argc != 2){
		std::cout << "Error : wrong number of arguments" << std::endl;
		return 1;
	}
	operation.calculator(argv[1]);
	return 0;
}


