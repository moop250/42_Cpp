/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:41:16 by hlibine           #+#    #+#             */
/*   Updated: 2025/04/25 17:38:09 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/PmergeMe.hpp"
#include <climits>
#include <cmath>
#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <utility>

void PmergeMe::intake(int ac, const char **av) {
	long		num;

	for (int i = 2; i < ac; i++) {
		num = atoi(av[i]);
		if (num > INT_MAX || num < 0) {
			std::ostringstream errorMessage;
			errorMessage << av[i] << " contains an invalid value" << std::endl;
			throw std::runtime_error(errorMessage.str());
		}
	}
}

// template<typename Container>
// PmergeMe<Container>::avToIt_(const char **av, const int ac) {
vi PmergeMe::avToIt_(const char **av, const int ac) {
	vi	out;

	out.reserve(ac - 1);
	for (int i = 1; i <= ac - 1; i++) {
		out.push_back(atoi(av[i]));
	}

	return out;
}

void	PmergeMe::swapPairs_(vi &vec, size_t index1, size_t index2) {
	for (size_t i = index2 - index1; i > 0; i--) {
		std::swap(vec[index1--], vec[index2--]);
	}
}

double PmergeMe::sortVector(const int ac, const char **av) {
	vi vec =	avToIt_(av, ac);
	vi base;
	vi pend;
	size_t		recLev = 0;
//	bool		isOdd = vec.size() % 2;

	// start a timer
	clock_t	timer_start = clock();

	// Dividing into pairs and sorting
	size_t	inc = 1;
	while (vec.size() > inc) {
		for (size_t i = 0; i < vec.size(); i += inc * 2) {
			size_t index1 = i + inc - 1;
			size_t index2 = i + (inc * 2) - 1;
			if (index2 <= vec.size() && vec[index1] > vec[index2])
				swapPairs_(vec, index1, index2);
		}
		++recLev;
		inc =  std::pow(2, recLev);
	}

	// Insertion sort
/* 	while (recLev > 1) {
	} */

	// save time it took to complete operation
	clock_t	timer_end = clock();
	// print the sorted list

	// return the saved time
	clock_t	timer = (timer_end - timer_start) / CLOCKS_PER_SEC;
	return timer;
}

// template<typename Container>
double PmergeMe::sortDeque(const int ac, const char **av) {

	(void)ac;
	(void)av;
	// start a timer
	clock_t	timer_start = clock();

	// sort

	// save time it took to complete operation
	clock_t	timer_end = clock();
	// print the sorted list

	// return the saved time
	clock_t	timer = (timer_end - timer_start) / CLOCKS_PER_SEC;
	return timer;
}