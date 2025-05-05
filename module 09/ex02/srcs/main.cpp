/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 10:57:58 by hlibine           #+#    #+#             */
/*   Updated: 2025/05/05 16:16:00 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/PmergeMe.hpp"
#include <iomanip>
#include <iostream>

int	main(int ac, const char *av[]) {

	if (ac == 1) {
		std::cerr << "Program required input" << std::endl;
		return 2;
	}

	clock_t time1, time2;

	try {
		PmergeMe::intake(ac, av);
		std::cout << "Before:\t";
		for (int i = 1; i <= ac - 1; i++) {
			std::cout << av[i] << " ";
		}
		std::cout << std::endl;
		time1 = PmergeMe::sortVector(ac, av);
		time2 = PmergeMe::sortDeque(ac, av);
		std::cout << "Time to process a range of "
			<< ac - 1 << " elements with std::PmergeMe::sortVector :\t"
			<< std::fixed << std::setprecision(6) << (double)time1 / CLOCKS_PER_SEC
			<< " us" << std::endl;
		std::cout << "Time to process a range of "
			<< ac - 1 << " elements with std::PmergeMe::sortDeque :\t"
			<< std::fixed << std::setprecision(6) << (double)time2 / CLOCKS_PER_SEC
			<< " us" << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
		return 2;
	}

	return 0;
}
