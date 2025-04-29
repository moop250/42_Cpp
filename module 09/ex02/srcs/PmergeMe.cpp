/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:41:16 by hlibine           #+#    #+#             */
/*   Updated: 2025/04/29 16:03:58 by hlibine          ###   ########.fr       */
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

template<typename Container>
void	TPmergeMe<Container>::swapPairs_(Container &cont, size_t index1, size_t index2) {
	for (size_t i = index2 - index1; i > 0; i--) {
		std::swap(cont[index1--], cont[index2--]);
	}
}

template<typename Container>
void TPmergeMe<Container>::sortCont(const size_t recLev, Container cont) {
	
	size_t	inc = std::pow(2, recLev);
	for (size_t i = 0; i < cont.size(); i += inc * 2) {
		size_t index1 = i + inc - 1;
		size_t index2 = i + (inc * 2) - 1;
		if (index2 <= cont.size() && cont[index1] > cont[index2])
			swapPairs_(cont, index1, index2);
	}
	TPmergeMe<Container>::sortCont(recLev + 1, cont);

		// Insertion sort
/* 	while (recLev > 1) {
	} */
}

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

vi PmergeMe::avToIt_(const char **av, const int ac) {
	vi	out;

	out.reserve(ac - 1);
	for (int i = 1; i <= ac - 1; i++) {
		out.push_back(atoi(av[i]));
	}

	return out;
}

double PmergeMe::sortVector(const int ac, const char **av) {
	vi vec = avToIt_(av, ac);

	// start a timer
	clock_t	timer_start = clock();

	TPmergeMe<vi>::sortCont(0, vec);

	// save time it took to complete operation
	clock_t	timer_end = clock();
	// print the sorted list

	// return the saved time
	clock_t	timer = (timer_end - timer_start) / CLOCKS_PER_SEC;
	return timer;
}

dq PmergeMe::avToDq_(const char **av, const int ac) {
	dq	out;

	for (int i = 1; i <= ac - 1; i++) {
		out.push_back(atoi(av[i]));
	}

	return out;
}

double PmergeMe::sortDeque(const int ac, const char **av) {

	dq deq = avToDq_(av, ac);

	// start a timer
	clock_t	timer_start = clock();

	TPmergeMe<dq>::sortCont(0, deq);

	// save time it took to complete operation
	clock_t	timer_end = clock();
	// print the sorted list

	// return the saved time
	clock_t	timer = (timer_end - timer_start) / CLOCKS_PER_SEC;
	return timer;
}