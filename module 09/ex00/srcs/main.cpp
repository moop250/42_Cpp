/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 13:53:06 by hlibine           #+#    #+#             */
/*   Updated: 2025/03/12 17:30:37 by hlibine          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/BitcoinExchange.hpp"
#include <cstdlib>
#include <iostream>
#include <string>


int main(int ac, char **av) {
	
	if (ac != 2) {
		std::cerr << "This program only accpets a single parameter, you input: " << ac - 1 << std::endl;
		return 0;
	}

	std::string	in = av[1];

	return 1;
}
