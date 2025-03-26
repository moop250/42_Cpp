/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 10:15:09 by hlibine           #+#    #+#             */
/*   Updated: 2025/03/26 16:26:50 by hlibine          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/RPN.hpp"
#include <exception>
#include <iostream>

int	main(int ac, char **av) {
	
	if (ac == 1) {
		std::cerr << "Error: Expected input" << std::endl;
		return 1;
	}

	std::string args = av[1];
	for (int i = 2; i < ac; i++) {
		args.push_back(' ');
		args += av[i];
	}

	try {
		std::cout << RPN::calculate(args) << std::endl;
	}
	catch (const std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return 2;
	}

	return 0;
}
