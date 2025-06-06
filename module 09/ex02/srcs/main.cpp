/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 10:57:58 by hlibine           #+#    #+#             */
/*   Updated: 2025/05/08 14:16:15 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/PmergeMe.hpp"
#include <iomanip>
#include <iostream>
#include "../utils/colors.h"

int	main(int ac, const char *av[]) {

	if (ac == 1) {
		std::cerr << "Program required input" << std::endl;
		return 2;
	}

	clock_t time1, time2;

	try {
		PmergeMe::intake(ac, av);
		time1 = PmergeMe::sortVector(ac, av);
		time2 = PmergeMe::sortDeque(ac, av);
		std::cout << "Time to process a range of "
			<< C_CYAN << ac - 1 << C_RESET << " elements with std::PmergeMe::sortVector :\t"
			<< std::fixed << std::setprecision(6) << C_CYAN << (double)time1 / CLOCKS_PER_SEC * 1000
			<< C_RESET << " us" << std::endl;
		std::cout << "Time to process a range of "
			<< C_CYAN << ac - 1 << C_RESET << " elements with std::PmergeMe::sortDeque :\t"
			<< std::fixed << std::setprecision(6) << C_CYAN << (double)time2 / CLOCKS_PER_SEC * 1000
			<< C_RESET << " us" << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << C_RED << "Error: " << e.what() << C_RESET << std::endl;
		return 2;
	}

	return 0;
}
