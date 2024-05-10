/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 12:59:25 by ljospin           #+#    #+#             */
/*   Updated: 2023/07/27 13:41:12 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal{
	public:
	WrongCat();
	WrongCat(WrongCat const &obj);
	~WrongCat();

	WrongCat& operator=(const WrongCat &obj);
	
	void makeSound() const;
	private:
};

#endif