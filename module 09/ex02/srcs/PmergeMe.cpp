/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:41:16 by hlibine           #+#    #+#             */
/*   Updated: 2025/05/07 16:48:12 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/PmergeMe.hpp"

void PmergeMe::intake(int ac, const char **av) {
	long		num;

	for (int i = 1; i < ac; i++) {
		num = atoi(av[i]);
		if (num > INT_MAX || num < 0) {
			std::ostringstream errorMessage;
			errorMessage << av[i] << " is too large, or below 0" << std::endl;
			throw std::runtime_error(errorMessage.str());
		}
		for (size_t a = 0; av[i][a]; a++)
		{
			if (!std::isdigit(av[i][a]))
			{
				std::ostringstream errorMessage;
				errorMessage << "\"" << av[i] << "\" contains an invalid value" << std::endl;
				throw std::runtime_error(errorMessage.str());
			}
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
	TPmergeMe<vi> visort(vec);

	std::cout << "Before:\t";
	visort.printCont();

	// start a timer
	clock_t	timer_start = clock();

	visort.sortCont(0);

	// save time it took to complete operation
	clock_t	timer_end = clock();
	
	// make sure the list is sorted
	try {
		visort.isSorted();
	}
	catch(std::exception &e) {
		std::cerr << e.what() << std::endl;
		exit(EXIT_FAILURE);
	}

	// print the sorted list
	std::cout << "After:\t";
	visort.printCont();

	// std::cout << "Comparisons:\t" << visort.getComparisons() << std::endl;

	// return the saved time
	double	timer = timer_end - timer_start;
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
	TPmergeMe<dq> dqsort(deq);

	// start a timer
	clock_t	timer_start = clock();

	dqsort.sortCont(0);

	// save time it took to complete operation
	clock_t	timer_end = clock();

	// make sure the list is sorted
	try {
		dqsort.isSorted();
	}
	catch(std::exception &e) {
		std::cerr << e.what() << std::endl;
		exit(EXIT_FAILURE);
	}

	// std::cout << "Comparisons:\t" << dqsort.getComparisons() << std::endl;

	// return the saved time
	clock_t	timer = timer_end - timer_start;
	return timer;
}