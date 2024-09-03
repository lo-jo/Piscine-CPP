/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 12:54:38 by ljospin           #+#    #+#             */
/*   Updated: 2023/09/05 12:55:05 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void	basic_tests(){
	try{
	std::cout << GREEN << "************* BASIC TESTS ************" << std::endl;
	std::cout << YEL << ">> Default constructor" << std::endl;
	Bureaucrat B;
	std::cout << YEL << ">> \"<<\" Operator overloader test" << std::endl;
	std::cout << B;
	std::cout << YEL << ">> Promotion test" << std::endl;
	B.upGrade();
	std::cout << B;
	std::cout << YEL << ">> Demotion test" << std::endl;
	B.downGrade();
	std::cout << B;
	std::cout << YEL << ">> getName(), getGrade() tests" << RESET << std::endl;
	std::cout << B.getName() << " " <<  B.getGrade() << std::endl;
	std::cout << YEL << ">> Demotion test (should fail)" << std::endl;
	B.downGrade();
	std::cout << YEL << ">> Destructor" << std::endl;
	}
	catch (std::exception &e){
	std::cout << RED<< e.what() << std::endl;
}
}

void	failed_constructor(){
	try{
	std::cout << std::endl << GREEN << "************* FAILED CONSTRUCTOR TEST *************" << RESET << std::endl;
	std::cout << YEL << ">> Creating Big Boss Bureaucrat Bob, grade 0 (should fail)" << RESET << std::endl;
	Bureaucrat Bob("Bob", 0);
	std::cout << Bob;
	}
	catch (std::exception &e){
	std::cout << RED<< e.what() << std::endl;
}

}

void	more_tests(){
try{
	std::cout << std::endl << GREEN << "************* MORE BASIC TESTS ************" << std::endl;
	Bureaucrat Bob("Bob", 1);
	std::cout << YEL << ">> Demoting bob all the way down... to the bottom" << RESET << std::endl;
	for (int i = 0; i < 149; i++)
		Bob.downGrade();
	std::cout << Bob;
	std::cout << YEL << ">> Copy of Bob" << RESET << std::endl;
	Bureaucrat c(Bob);
	std::cout << c;
	std::cout << YEL << ">> That bob copy is working his way up... (4 levels)" << RESET << std::endl;
	c.upGrade();
	c.upGrade();
	c.upGrade();
	c.upGrade();
	std::cout << c;
	std::cout << YEL << ">> Assignment operator test..." << RESET << std::endl;
	Bob = c;
	std::cout << Bob;
}
catch (std::exception &e){
	std::cout << RED<< e.what() << std::endl;
}

}

int main(){
		basic_tests();
		failed_constructor();
		more_tests();
	return 0;
}