/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 16:06:02 by ljospin           #+#    #+#             */
/*   Updated: 2023/07/05 10:49:20 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(){
	int N = 10;
	std::string name = "Uggo";
	Zombie *horde = zombieHorde(N, name);

	std::cout << YEL <<  ">>>> A horde of " << N << " zombies was created" << RESET << std::endl;
	std::cout << "Now let's introduce each one of them." << std::endl;
	for (int i = 0; i < N; i++){
		std::cout << "... Give a warm welcome to zombie No." << i << " :" <<std::endl;
		horde[i].announce();
	}
	delete[] horde;
	return(0);
}