/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 14:52:21 by ljospin           #+#    #+#             */
/*   Updated: 2023/09/22 11:28:25 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PmergeMe.hpp"
bool has_dup(unsigned int *base, int size){
	for (int i =0; i <size; i++){
		for (int j = i +1; j < size; j++){
			if (base[i] == base[j])
				return 1;
		}
	}
	return 0;
}


int main(int argc, char **argv){
	if (argc < 2){
		std::cout << RED "Invalid input" RESET << std::endl;
		return 1;
	}

	uint *base = new unsigned int[argc -1];
	for (int i = 1; i < argc; i++){
		{
			if (atoi(argv[i]) < 0){
				std::cout << RED "Error : Negative number" << RESET << std::endl;
				delete[] base;
				return 1;}
			base[i-1] = atoi(argv[i]);
		}
		
	}
	if (has_dup(base, argc-1)){
		std::cout << "Error : duplicates" << std::endl;
		delete[] base;
		return 1;}

	PmergeMe A(base, argc - 1);
	clock_t start = clock();
	A.processWithVector();
	clock_t stop = clock();
	double vecDuration = static_cast<double>(stop-start) / CLOCKS_PER_SEC * 1000;
	A.displaySort();
	

	clock_t startdeq = clock();
	A.processWithDeque();
	clock_t stopdeq = clock();
	double deqDuration = static_cast<double>(stopdeq-startdeq) / CLOCKS_PER_SEC * 1000;
	std::cout << "After (deque)  | " << MAG;
	A.displaySimpleDeq();
	std::cout << RESET "Time to process a range of " << A.size << " elements with std::vector : " << vecDuration << std::endl;
	std::cout << "Time to process a range of " << A.size << " elements with std::deque : " << deqDuration << std::endl;
	delete[] base;

	return 0;
}