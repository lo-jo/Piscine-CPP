/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 10:59:51 by ljospin           #+#    #+#             */
/*   Updated: 2023/07/12 16:30:18 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Stream.hpp"

int main(int argc, char **argv)
{
	if (argc != 4){
		std::cout << "Wrong Number or arguments" << std::endl;
		return(1);}
	Stream stream = Stream(argv[1], argv[2], argv[3]);
	stream.readFile();
	return (0);
}
