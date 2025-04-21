/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:41:16 by hlibine           #+#    #+#             */
/*   Updated: 2025/04/21 14:34:03 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/PmergeMe.hpp"
#include <climits>
#include <cstdlib>
#include <sstream>
#include <stdexcept>
#include <string>

std::string PmergeMe::intake(int ac, const char **av) {
	std::string	out;
	long		num;
	char		*ptr;

	for (int i = 2; i < ac; i++) {
		num = strtol(av[i], &ptr, 10);
		if (num > INT_MAX || num <= 0 || ptr[0] != 0) {
			std::ostringstream errorMessage;
			errorMessage << av[i] << " contains an invalid value" << std::endl;
			throw std::runtime_error(errorMessage.str());
		}

		out += av[i];
		if (i + 1 != ac)
			out.push_back(' ');
	}

	return out;
}

double PmergeMe::sortVector(const std::string in) {
	double timer = 0;


	// print the unsorted list
	// start a timer

	// sort

	// save time it took to complete operation
	// print the sorted list

	// return the saved time
	return timer;
}


double PmergeMe::sortDeque(const std::string in) {
	double timer = 0;

	// start a timer

	// sort

	// save the time it took to complete the opertation
	// print the sorted list

	// return the saved time
	return timer;
}