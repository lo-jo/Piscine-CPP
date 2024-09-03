/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 14:52:30 by ljospin           #+#    #+#             */
/*   Updated: 2023/09/22 13:58:25 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
////////////////////////////// INSERTION SORT VECTOR ////////////////
// make sorted sequence
// !! deque : allows fast insertion and deletion at both its beginning and its end.
// insert at the beginning the element that was paired with the minimum of the sequence
// ex :
// 1 | 2
// 6 | 9
// 22 | 55
// 44 | 99
// 66 | 100
// sequence is : 1 2 6 9 22 55 44 99 66 100
// >> 1 is the minimum, 2 is paired with it >>> insert 2 at beginning of sequence
// SEQUENCE = 2
// We know that the number paired with s[0] est plus petit > insert it at beginning of s
// SEQUENCE = 1, 2
// remaining :
// 6 | 9
// 22 | 55
// 44 | 99
// 66 | 100
// now insert the second column (biggest values vec.second) into sequence
// progressively add the pending column (smallest values ie vec.first) according to lower bound found in sequence
void PmergeMe::insertionSortSequence(){
	sequence.push_back(vec[0].second);
	sequence.insert(sequence.begin(), vec[0].first);

// push_back the rest of the second pair (biggest values)
	for (unsigned long i = 1; i != vec.size(); i++){
		sequence.push_back(vec[i].second);
	}
// insert progressively the smallest values (first pair) into the sequence
	for (unsigned long i = 1; i != vec.size(); i++){
		sequence.insert(lower_bound(sequence.begin(), sequence.end(),vec[i].first), vec[i].first);
	}
// if the list was odd then we still need to insert that lonely unpaired number
	if (is_odd)
		sequence.insert(lower_bound(sequence.begin(), sequence.end(), outcast), outcast);
// the sequence should be sorted !!
	//displaySimpleVec();
}

///////////////////// MERGE SORT VECTOR /////////////////////////////
std::vector<std::pair<int, int> > mergeVector(const std::vector<std::pair<int, int> >& left, const std::vector<std::pair<int, int> >& right) {
	std::vector<std::pair<int, int> > result;
	size_t leftIdx = 0;
	size_t rightIdx = 0;

	while (leftIdx < left.size() && rightIdx < right.size()) {
		if (left[leftIdx].second < right[rightIdx].second) {
			result.push_back(left[leftIdx]);
			leftIdx++;}
		else {
			result.push_back(right[rightIdx]);
			rightIdx++;
		}
	}

	// if there are any remaining elements in right or left vector, merge
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

std::vector<std::pair<int, int> > mergeSortVector(const std::vector<std::pair<int, int> >& veq) {
	// If the vector is empty or has only one element, it is already sorted.
	if (veq.size() <= 1) {
		return veq;
	}
	// Divide the paired deque into two halves
	size_t middle = veq.size() / 2;
	std::vector<std::pair<int, int> > left(veq.begin(), veq.begin() + middle);
	std::vector<std::pair<int, int> > right(veq.begin() + middle, veq.end());

	// Recursively sort the two halves
	left = mergeSortVector(left);
	right = mergeSortVector(right);

	// Merge the sorted halves
	return mergeVector(left, right);
}


////////////////////////// VECTOR MAIN ///////////////////////////////
void PmergeMe::processWithVector(){
	//std::cout << "STEP 1. Group input into pairs " << std::endl;
	groupIntoPairs();
	//displayvec();
	//std::cout << "STEP 2. Left values and right values are sorted" << std::endl;
	sortPairs(); 
	//displayvec();


	// std::cout << "STEP 3. Right values are sorted in ascending order" << std::endl;
	std::vector<std::pair<int, int> > sortedVector = mergeSortVector(vec);
	vec.clear();
	vec = sortedVector;
	//displayvec();
	//sortedVector.clear();

	//std::cout << "STEP 4. Sort sequence by insertion" << std::endl;
	insertionSortSequence();
}



void PmergeMe::groupIntoPairs(){
	// identifying if input is odd or even
	if (size % 2 != 0)
		is_odd = 1;
	// storing original array inside a paired vector
	if (!is_odd){
		for (int i = 0; i< size; i+=2)
			vec.push_back(std::make_pair(arr[i], arr[i+1]));
	}
	// if the input is odd :
	// store the original array -1 inside a paired vector
	// the "lonely number" is stored inside and int for later use
	else if (is_odd){
		outcast = arr[size-1];
		for (int i = 0; i < size-1; i+=2)
			vec.push_back(std::make_pair(arr[i], arr[i+1]));

	}
}

void PmergeMe::sortPairs(){
	for (unsigned long i = 0; i < vec.size(); i++)
	{
		if (vec[i].first > vec[i].second){
			std::swap(vec[i].first, vec[i].second);
		}
	}
}



//////////////////////// DISPLAY FUNCTIONS /////////////////////////////
void PmergeMe::displaySimpleVec(){
	for (unsigned long i=0; i< sequence.size(); i++)
    {
        std::cout << sequence[i]<< " ";
    }
	std::cout << std::endl;
}

void PmergeMe::displayvec(){
	for (unsigned long i=0; i< vec.size(); i++)
    {
        std::cout << vec[i].first << " | " << vec[i].second << std::endl;
    }
}