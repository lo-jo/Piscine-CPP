/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 12:32:28 by ljospin           #+#    #+#             */
/*   Updated: 2023/09/15 12:27:16 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"


int main()
{
MutantStack<int> mstack;
mstack.push(5);
mstack.push(17);
std::cout << "top : " << mstack.top() << std::endl;
mstack.pop();
std::cout << "size : " << mstack.size() << std::endl;
mstack.push(3);
mstack.push(5);
mstack.push(737);
//[...]
mstack.push(0);
MutantStack<int>::iterator it = mstack.begin();
MutantStack<int>::iterator ite = mstack.end();
std::cout << "begin : " << *it << std::endl;
std::cout << "end : " << *ite << std::endl;

++it;
std::cout << "++begin : " << *it << std::endl;
--it;
std::cout << "--begin : " << *it << std::endl;
while (it != ite)
{
std::cout << *it << std::endl;
++it;
}
std::cout << std::endl << "****** ADDITIONAL TESTS ******* "<< std::endl;
std::cout << "mutant stack top " << mstack.top() << std::endl;
std::cout << "mutant stack size : " << mstack.size() << std::endl;
std::cout << "std::stack copy constructor : " << std::endl;
std::stack<int> s(mstack); 
std::cout << "testing stack top " << s.top() << std::endl;
std::cout << "s size : " << s.size() << std::endl;

std::cout << "TESTING MUTANT STACK COPY CONSTRUCTOR: " << std::endl;
MutantStack<int> MutantCopy(mstack);
MutantStack<int>::iterator itt = MutantCopy.begin();
MutantStack<int>::iterator itte = MutantCopy.end();
std::cout << "Copy should be like the original: " << std::endl;
while (itt != itte)
{
	std::cout << *itt << std::endl;
	++itt;
}



{
	std::cout << "*** testing with list container ***" << std::endl;
	std::list<int> mlist;
	mlist.push_back(5);
	mlist.push_back(17);
	std::cout << "top " << mlist.back() << std::endl;
	mlist.pop_back();

	std::cout << "size : " << mlist.size() << std::endl;
	mlist.push_back(3);
	mlist.push_back(5);
	mlist.push_back(737);
	//[...]
	mlist.push_back(0);
	std::list<int>::iterator it = mlist.begin();
	std::list<int>::iterator ite = mlist.end();
	std::cout << "begin : " << *it << std::endl;
	std::cout << "end : " << *ite << std::endl;
	++it;
	std::cout << "++begin : " << *it << std::endl;
	--it;
	std::cout << "--begin : " << *it << std::endl;

	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	
}


return 0;
}