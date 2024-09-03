/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljospin <ljospin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 12:33:06 by ljospin           #+#    #+#             */
/*   Updated: 2023/09/14 12:33:07 by ljospin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


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

class Span{
	private :
		unsigned long int max;
	public :
		Span(int N);
		~Span();
		Span(Span const &obj);
		Span &operator=(Span const&obj);

		void addNumber(int n);
		void addNumber(std::vector<int>::iterator start, std::vector<int>::iterator end);
		int shortestSpan();
		int longestSpan();

		std::vector<int> storage;

		class SpanNotFoundException : public std::exception{
			public :
			virtual const char* what() const throw();
		};

		class FullStorageException : public std::exception{
			public :
			virtual const char* what() const throw();
		};
};

void 	print_span(std::vector<int> spansrc);