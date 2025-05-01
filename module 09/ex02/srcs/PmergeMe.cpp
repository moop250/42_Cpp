/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:41:16 by hlibine           #+#    #+#             */
/*   Updated: 2025/05/01 16:22:59 by hlibine          ###   ########.fr       */
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
TPmergeMe<Container>::TPmergeMe(void) : comparisons_(0) {};

template<typename Container>
TPmergeMe<Container>::~TPmergeMe(void) {};

template<typename Container>
void	TPmergeMe<Container>::swapPairs_(Container &cont, size_t index1, size_t index2) {
	++comparisons_;
	if (cont.at(index1) > cont.at(index2))
		for (size_t i = index2 - index1; i > 0; i--) {
			std::swap(cont.at(index1--), cont.at(index2--));
		}
}

template<typename Container>
void	TPmergeMe<Container>::moveTo_(Container &src, Container &dst, const size_t len) {
/* 	std::cout << "size: " << src.size() << std::endl;
	std::cout << "len: " << len << std::endl; */
	for (size_t i = 0; i < len; i++) {
/* 		std::cout << "i: " << i << std::endl; */
		
		dst.push_back(src.at(0));
		src.erase(src.begin());
	}
}

template<typename Container>
void TPmergeMe<Container>::sortCont(const size_t recLev, Container &cont, const int isOdd) {
	size_t inc = std::pow(2, recLev);
	size_t inc2 = 2 * inc;
	if (cont.size() < inc2)
		return;
	size_t limit = cont.size() - inc2 + 1;
	for (size_t i = 0; i < limit; i += inc2) {
		size_t index1 = i + inc - 1;
		size_t index2 = i + inc2 - 1;
		swapPairs_(cont, index1, index2);
	}
	TPmergeMe<Container>::sortCont(recLev + 1, cont, isOdd);

	// Split numbers into main and pend

	for (size_t i = 0; i < inc2; i++) {
		main_.push_back(cont.at(0));
		cont.erase(cont.begin());
	}

	for (size_t i = 0, b = 0; i + inc < limit; i += inc) {
		if (++b % 2)
			moveTo_(cont, pend_, inc);
		else
			moveTo_(cont, main_, inc);
	}
	moveTo_(cont, non_, cont.size());


	// push everything back into cont
	moveTo_(main_, cont, main_.size());
	moveTo_(pend_, cont, pend_.size());
	moveTo_(non_, cont, non_.size());

	return ;
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
	TPmergeMe<vi> visort;

	// start a timer
	clock_t	timer_start = clock();

	visort.sortCont(0, vec, (ac - 1) % 2);

	// save time it took to complete operation
	clock_t	timer_end = clock();
	// print the sorted list
	for (size_t i = 0; i < vec.size(); i++) {
		std::cout << vec.at(i) << " ";
	}
	std::cout << std::endl;

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
	TPmergeMe<dq> dqsort;
	
	// start a timer
	clock_t	timer_start = clock();

	dqsort.sortCont(0, deq, deq.size() % 2);

	// save time it took to complete operation
	clock_t	timer_end = clock();
	// print the sorted list

	// return the saved time
	clock_t	timer = (timer_end - timer_start) / CLOCKS_PER_SEC;
	return timer;
}