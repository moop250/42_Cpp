/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:08:05 by hlibine           #+#    #+#             */
/*   Updated: 2025/03/05 19:19:23 by hlibine          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Span.hpp"
#include <algorithm>
#include <climits>
#include <cstdlib>
#include <ctime>
#include <ostream>
#include <vector>

Span::Span(void) : _maxSize(0), _count(0) {std::cerr << "you should not be able to see this" << std::endl;};

Span::Span(unsigned int N) : _maxSize(N),  _count(0) {
	if (N < 2)
		throw UnSpanException();
};

Span::Span(const Span &src) {
	this->_N = src._N;
	this->_maxSize = src._maxSize;
	this->_count = src._count;
}

Span& Span::operator=(const Span &src) {
	if (this != &src) {
		this->_N = src._N;
		this->_maxSize = src._maxSize;
		this->_count = src._count;
	}

	return *this;
}

Span::~Span() {};

void Span::addNumber(const unsigned int N) {
	if (this->_count < this->_maxSize) {
		++this->_count;
		this->_N.push_back(N);
	}
	else {
		throw Span::OverCountException();
	}
}

void Span::fillList(const unsigned int count, const int max) {
	srand(time(0));
	for (unsigned int i = 0; i < count; i++) {
		if (this->_count  > this->_maxSize)
			throw Span::OverCountException();
		++this->_count;
		this->_N.push_back(rand() % (max + 1));
		std::cout << this->_N[i] << std::endl;
	}
}

unsigned int	Span::longestSpan(void) {
	int Imax = *std::max_element(this->_N.begin(), this->_N.end());
	int Imin = *std::min_element(this->_N.begin(), this->_N.end());
	
	return Imax - Imin;
}

unsigned int	Span::shortestSpan(void) {
	unsigned int		out = UINT_MAX;
	std::vector<int>	srt(this->_N);

	std::sort(srt.begin(), srt.end());
	for (unsigned int i = 0; &srt[i] < &srt.back(); i++) {
		unsigned int diff = static_cast<unsigned int>(srt[i + 1] - srt[i]);
		if (diff < out )
			out = diff;
	}
	return out;
}
