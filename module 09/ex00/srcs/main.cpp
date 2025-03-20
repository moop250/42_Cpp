/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 13:53:06 by hlibine           #+#    #+#             */
/*   Updated: 2025/03/20 17:19:40 by hlibine          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/BitcoinExchange.hpp"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>


int main(int ac, char **av) {
	(void)ac;

	BtcEx	btc("./data.csv");
	std::ifstream file;

	try {
		btc.init();
	}
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what();
		return 2;
	}
	file.open(av[1]);
	if (!file.is_open()) {
		std::cerr << "Error: could not open file." << std::endl;
		return 3;
	}
	try {
		btc.process(file);
	}
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what();
		return 4;
	}
	return 0;
}
