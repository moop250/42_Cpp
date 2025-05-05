/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:41:16 by hlibine           #+#    #+#             */
/*   Updated: 2025/05/04 14:57:41 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/PmergeMe.hpp"

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

	visort.sortCont(0, vec, vec.size() % 2);

	// save time it took to complete operation
	clock_t	timer_end = clock();

	// print the sorted list
	for (size_t i = 0; i < vec.size(); i++) {
		std::cout << vec.at(i) << " ";
	}
	std::cout << std::endl;

	// return the saved time
	double	timer = double(timer_end - timer_start) / CLOCKS_PER_SEC;
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