/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Deque.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 14:52:18 by ljospin           #+#    #+#             */
/*   Updated: 2023/09/22 13:58:02 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

////////////////////// DISPLAY ///////////////////
void PmergeMe::displayPairedDeq(){
	std::cout << MAG << "**PAIRED DEQUE***" << RESET << std::endl;
	for (unsigned long i = 0; i < deq.size(); i++)
		std::cout << deq[i].first << " | " << deq[i].second << std::endl;
}

void PmergeMe::displaySimpleDeq(){
	for (unsigned long i=0; i< deqseq.size(); i++)
    {
        std::cout << deqseq[i]<< " ";
    }
	std::cout << std::endl;
}


////////////////////// MERGE SORT /////////////////////

// Recursively sort the larger elements from each pair, creating a sorted sequence  of the input elements, in ascending order.

std::deque<std::pair<int, int> > merge(const std::deque<std::pair<int, int> >& left, const std::deque<std::pair<int, int> >& right) {
	std::deque<std::pair<int, int> > result;
	size_t leftIdx = 0;
	size_t rightIdx = 0;

	while (leftIdx < left.size() && rightIdx < right.size()) {
		if (left[leftIdx].second <= right[rightIdx].second) {
			result.push_back(left[leftIdx]);
			leftIdx++;
		} else {
			result.push_back(right[rightIdx]);
			rightIdx++;
		}
	}

	// if there are any remaining elements in right or left deque, merge
	while (leftIdx < left.size()) {
		result.push_back(left[leftIdx]);
		leftIdx++;
	}
	while (rightIdx < right.size()) {
		result.push_back(right[rightIdx]);
		rightIdx++;
	}
	return result;
}

std::deque<std::pair<int, int> > mergeSort(const std::deque<std::pair<int, int> >& deq) {
	// Base case: If the deque is empty or has only one element, it is already sorted.
	if (deq.size() <= 1) {
		return deq;
	}
	// Divide the paired deque into two halves
	size_t middle = deq.size() / 2;
	std::deque<std::pair<int, int> > left(deq.begin(), deq.begin() + middle);
	std::deque<std::pair<int, int> > right(deq.begin() + middle, deq.end());

	// Recursively sort the two halves
	left = mergeSort(left);
	right = mergeSort(right);

	// Merge the sorted halves
	return merge(left, right);
}

/////////////////////// DEQUE /////////////////////
void PmergeMe::processWithDeque(){
	groupIntoPairedDeq();
	//displayPairedDeq();
	sortDeqPairs();
	//displayPairedDeq();

	std::deque<std::pair<int, int> > sortedDeque = mergeSort(deq);
	deq.clear();
	deq = sortedDeque;
	//sortedDeque.clear();
	//displayPairedDeq();
	insertionSortDeqSequence();

}

void PmergeMe::sortDeqPairs(){
	for (unsigned long i = 0; i < deq.size(); i++)
	{
		if (deq[i].first > deq[i].second){
			std::swap(deq[i].first, deq[i].second);
		}
	}
}


void PmergeMe::groupIntoPairedDeq(){
	if (!is_odd){
		for (int i = 0; i< size; i+=2)
			deq.push_back(std::make_pair(arr[i], arr[i+1]));
	}
	else {
		for (int i = 0; i < size-1; i+=2)
			deq.push_back(std::make_pair(arr[i], arr[i+1]));
	}
}


void PmergeMe::insertionSortDeqSequence(){
	deqseq.push_back(deq[0].second);
	deqseq.push_front(deq[0].first);

// push_back the rest of the second pair (biggest values)
	for (unsigned long i = 1; i != deq.size(); i++){
		deqseq.push_back(deq[i].second);
	}
// insert progressively the smallest values (first pair) into the sequence
	for (unsigned long i = 1; i != deq.size(); i++){
		deqseq.insert(lower_bound(deqseq.begin(), deqseq.end(),deq[i].first), deq[i].first);
	}

// if the list was odd then we still need to insert that lonely unpaired number
	if (is_odd)
		deqseq.insert(lower_bound(deqseq.begin(), deqseq.end(), outcast), outcast);
	
// the sequence should be sorted !!
	
}



