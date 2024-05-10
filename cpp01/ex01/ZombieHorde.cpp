/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 16:05:43 by ljospin           #+#    #+#             */
/*   Updated: 2023/07/05 10:50:57 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*
Implement the following function in the appropriate file:
Zombie* zombieHorde( int N, std::string name );*/

Zombie* zombieHorde( int N, std::string name) {
	Zombie* horde = new Zombie[N]; // first will allocate N zombies

	for(int i = 0; i < N; i++){
		horde[i].giveName(name); // then will give name
	}
	return horde;
}
