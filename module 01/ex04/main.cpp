/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 14:48:50 by hlibine           #+#    #+#             */
/*   Updated: 2024/10/22 17:37:17 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <ostream>
#include <string>
#include "stringReplace.hpp"

int	main(int ac, char **av) {
	std::string	buff;
	std::string	toReplace = "";

	if (ac != 4) {
		std::cout << "Invalid input" << std::endl;
		return 1;
	}
	std::ifstream infile(av[1]);
	if (!infile) {
		std::cout << "Invalid Infile" << std::endl;
		return 2;
	}

	while (getline(infile, buff))
		toReplace.append(buff).append("\n");
	std::string tmp = av[1];
	tmp.append(".replace");
	std::ofstream outfile(tmp.c_str());
	outfile << stringReplace(toReplace, av[2], av[3]);

	infile.close();
	outfile.close();
}
