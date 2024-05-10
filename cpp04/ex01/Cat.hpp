/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 12:59:25 by ljospin           #+#    #+#             */
/*   Updated: 2023/07/27 18:09:06 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal{
	public:
	Cat();
	Cat(Cat const &obj);
	virtual ~Cat();

	Cat& operator=(const Cat &obj);
	virtual void makeSound(void) const;
	Brain* getBrain(void) const;
	private:
	Brain *brain;
};

#endif