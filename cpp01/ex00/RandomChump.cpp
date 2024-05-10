/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RandomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:19:00 by ljospin           #+#    #+#             */
/*   Updated: 2024/04/09 12:56:35 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/* Creates a zombie, names it, and returns it
* so you can use it outside of the function
* scope.*/

Zombie* newZombie(std::string name){
	Zombie* newZomb = new Zombie(name);
	return(newZomb);
}

/*
void randomChump( std::string name );
creates a zombie, names it, and the zombie announces itself
*/

void randomChump(std::string name){
	Zombie random = Zombie(name);
	random.announce();
}