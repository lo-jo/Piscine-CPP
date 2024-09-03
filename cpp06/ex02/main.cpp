/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 12:25:35 by ljospin           #+#    #+#             */
/*   Updated: 2023/09/11 12:25:36 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"


int main(){
	std::cout << "Generating a random class between A, B or C :" << std::endl;
	Base *RandomBase = generate();
	std::cout << "Identifying the randomly generated class from its pointer :" << std::endl;
	identify(RandomBase);

	std::cout << "Identifying the randomly generated class from its reference :" << std::endl;
	identify(*RandomBase);

	std::cout << "deleting" << std::endl;
	delete RandomBase;
	return 0;
}