/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:09:34 by hlibine           #+#    #+#             */
/*   Updated: 2025/02/04 14:24:26 by hlibine          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ScalarConverter.hpp"
#include <iostream>

int	main(int ac, char** av ) {

	if (ac < 2) {
		std::cerr << "\033[31merror: not enough arguments.\033[0m" << std::endl << "excpected 1 got: " << ac - 1 << std::endl;
		return 2;
	}
	else if (ac > 2) {
		std::cerr << "\033[31merror: too many arguments.\033[0m" << std::endl << "excpected 1 got << " << ac - 1 << std::endl; 
	}

	ScalarConverter::convert(av[1]);
}



