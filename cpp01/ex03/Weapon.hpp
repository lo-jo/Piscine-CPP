/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:54:52 by ljospin           #+#    #+#             */
/*   Updated: 2023/07/05 10:54:53 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream> 
#include <string>

class Weapon{
	public:
		Weapon(std::string type);
		~Weapon();
		const std::string& getType();
		void	setType(std::string type);
	private:
		std::string type;
};

#endif