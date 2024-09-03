/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 14:51:19 by ljospin           #+#    #+#             */
/*   Updated: 2023/09/25 11:58:06 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


int main(int argc, char **argv){
	BitcoinExchange btc;
	BitcoinExchange inpt;
	(void)argv;
	if (argc != 2){
		std::cout << RED "invalid input" RESET << std::endl;
		return 1;
	}

	btc.extractData();
	btc.parseInput(argv[1], inpt);
	return 0;
}
