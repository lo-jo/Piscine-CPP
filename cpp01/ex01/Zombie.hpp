/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:50:34 by ljospin           #+#    #+#             */
/*   Updated: 2023/07/05 10:53:38 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream> 
#include <string>

// ANSI COLORS
#define WBG "\x1B[47m"
#define RESET "\x1B[0m"
#define BOLD "\x1B[1m"
#define MAG "\x1B[35m"
#define YEL "\x1B[33m"
#define RED "\x1B[31m"
#define GREEN "\e[0;32m"

class Zombie{
	public :
	Zombie();
	~Zombie();
	void announce();
	void giveName(std::string name);

	private :
	std::string name;
};

Zombie* zombieHorde(int N, std::string name);

#endif