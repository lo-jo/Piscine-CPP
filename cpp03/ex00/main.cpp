/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 14:43:03 by ljospin           #+#    #+#             */
/*   Updated: 2023/07/31 11:22:29 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(){
	
	ClapTrap Clap1("Robot 1");
	ClapTrap Clap2("Robot 2");
	
	Clap1.attack("Robot 2");
	
	for (int a = 0; a < 10; a++)
		Clap1.attack("Robot 2");
	
	ClapTrap c = Clap2;
	ClapTrap Clap3("Robot 3");
	Clap3.attack("boss");
	Clap1.beRepaired(30);
	return 0;
}