/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:55:06 by ljospin           #+#    #+#             */
/*   Updated: 2023/07/05 10:55:07 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream> 
#include <string>
#include "Weapon.hpp"

class HumanB{
	public :
		HumanB(std::string name);
		~HumanB();
		void attack();
		void setWeapon(Weapon& weapon);
	private :
		std::string name;
		Weapon *weapon; // pointers may point to nothing whereas refs cannot
};

#endif