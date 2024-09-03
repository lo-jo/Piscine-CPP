/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 14:52:27 by ljospin           #+#    #+#             */
/*   Updated: 2024/09/03 14:49:57 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP


#include <string>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <deque>
#include <ctime>

// ANSI COLORS
#define WBG "\x1B[47m"
#define RBG "\e[41m"
#define RESET "\x1B[0m"
#define BOLD "\x1B[1m"
#define MAG "\x1B[35m"
#define YEL "\x1B[33m"
#define RED "\x1B[31m"
#define BLK "\e[0;30m"
#define GREEN "\e[0;32m"
#define BLUE "\e[0;34m"


class PmergeMe{
	public :
		PmergeMe(unsigned int *arr, int size);
		~PmergeMe();
		PmergeMe(PmergeMe const &obj);
		PmergeMe &operator=(PmergeMe const &obj);

		// ATTRIBUTES //
		int 		size;

		/// METHODS //
		void processWithVector();
		void processWithDeque();

		// VECTOR FUNCTIONS //
		void groupIntoPairs(); // step 1
		void sortPairs();  // step 2
		void insertionSortSequence(); // step 4

		// DEQUE FUNCTIONS
		void groupIntoPairedDeq(); // step 1
		void sortDeqPairs();  // step 2
		void insertionSortDeqSequence(); // step 4

		// DISPLAY
		void displayArr();
		void displayvec();
		void displaySimpleVec();
		void displaySort();
		void displayPairedDeq();
		void displaySimpleDeq();
		
	private :
		unsigned int *arr;
		bool		 is_odd;
		int			 outcast;
		std::vector <std::pair<int, int> > vec;
		std::vector <int> sequence;

		std::deque <std::pair<int, int> > deq;
		std::deque <int> deqseq;
};










#endif