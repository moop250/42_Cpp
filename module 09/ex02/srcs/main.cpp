/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 10:57:58 by hlibine           #+#    #+#             */
/*   Updated: 2025/04/21 14:34:38 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/PmergeMe.hpp"
#include <climits>
#include <ctime>
#include <exception>
#include <iostream>
#include <sstream>


int	main(int ac, const char *av[]) {

	if (ac == 1) {
		std::cerr << "Program required input" << std::endl;
	}

	std::string	list;
	clock_t time1, time2;

	try {
		list = PmergeMe::intake(ac, av);
		std::cout << "Before: " << list << std::endl;
		time1 = PmergeMe::sortVector(list);
		time2 = PmergeMe::sortDeque(list);
		std::cout << "Time to process a range of " << ac - 1 << "elements with std::PmergeMe::sortVector : " << time1 << " us" << std::endl;
		std::cout << "Time to process a range of " << ac - 1 << "elements with std::PmergeMe::sortDeque : " << time2 << " us" << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
		return 2;
	}

	return 0;
}
