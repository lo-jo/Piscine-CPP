/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 10:55:00 by ljospin           #+#    #+#             */
/*   Updated: 2023/09/11 10:55:01 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(){
	Data *ptr = new Data;

	ptr->str = "testing";
	ptr->msg = "MORE TESTING";
	ptr->nbr = 666;

	std::cout << "********************" << std::endl;
	std::cout << "Data: " << std::endl;
	std::cout << ptr->str << std::endl << ptr->msg << std::endl << ptr->nbr << std::endl;	
	std::cout << "********************" << std::endl;




	// utilisez serialize( ) sur ladresse de l4objet data
	// passew la valeur de retour obtenue a deserialize
	// assurez vous que le retour de deserialize est identique au ptr dorigine
	std::cout << "original pointer to data" << std::endl;
	std::cout << ptr << std::endl;
	std::cout << "Use serialize() on the address of the data object" << std::endl;
	std::cout << ptr << Serializer::serialize(ptr) << std::endl;
	std::cout << "Pass its return value to deserialize()" << std::endl;
	std::cout << Serializer::deserialize(Serializer::serialize(ptr)) << std::endl;
	std::cout << "> does it compare equal to the original pointer ? (yes)" << std::endl;
	std::cout << "********************" << std::endl;
	std::cout << "More tests" << std::endl;
	

	Data *ptr2;
	std::cout << std::endl << "convert uinptr to pointer to data:" << std::endl;
	//
	ptr2 = Serializer::deserialize(Serializer::serialize(ptr));
	std::cout << "str: " << ptr2->str << std::endl;
	std::cout << "msg: " << ptr2->msg << std::endl;
	std::cout << "nbr: " << ptr2->nbr << std::endl;


	delete ptr;
	return 0;
}