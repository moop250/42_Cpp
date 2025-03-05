/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:08:02 by hlibine           #+#    #+#             */
/*   Updated: 2025/03/05 19:17:47 by hlibine          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_CLASS_HPP
# define SPAN_CLASS_HPP

#include <exception>
#include <vector>
#include <iostream>

class Span {
	private:
		std::vector<int>	_N;
		unsigned int		_maxSize;
		unsigned int		_count;
		Span();

	public:
	/*  Constructors and Destructor  */
		Span(unsigned int N);
		Span(const Span &src);
		Span& operator=(const Span &src);
		~Span();
	/*  Member Functions  */
		void	addNumber(const unsigned int in);
		void	fillList(const unsigned int count, const int max);
		unsigned int shortestSpan(void);
		unsigned int longestSpan(void);

	/*  Exceptions  */
		class OOBException : public std::exception {
			public:
				virtual const char *what() const throw() {
				return "Attempted to access outside of the space alloted\n";
			}
		};
		class OverCountException : public std::exception {
			public:
				virtual const char *what() const throw() {
				return "Attempted to add a number but the container is full\n";
			} 
		};
		class UnSpanException : public std::exception {
			public:
				virtual const char *what() const throw() {
				return "Value not large enough to initiate a Span\n";
			}
		};
};

#endif
