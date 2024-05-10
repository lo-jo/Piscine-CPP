/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:55:12 by ljospin           #+#    #+#             */
/*   Updated: 2023/07/05 10:55:13 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream> 
#include <string>
#include "Weapon.hpp"

class HumanA{
	public :
		HumanA(std::string name, Weapon& weapon);
		~HumanA();
		void attack();
	private :
		std::string name;
		Weapon& weapon;

};

#endif