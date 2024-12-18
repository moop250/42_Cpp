/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 14:48:50 by hlibine           #+#    #+#             */
/*   Updated: 2024/12/18 16:15:40 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stringReplace.hpp"

int	main(int ac, char **av) {
	std::ofstream	outfile;
	std::ifstream	infile;
	std::string	buff;
	std::string	toReplace = "";
	std::string	path;

	if (ac != 4) {
		std::cout << "Invalid Arguments" << std::endl;
		return 1;
	}
	path = av[1];
	infile.open(path.c_str(), std::ios::in);
	if (!infile) {
		std::cout << "Error Opening Infile" << std::endl;
		return 2;
	}
	outfile.open(path.append(".replace").c_str(), std::ios::out);
	if (!outfile) {
		std::cout << "Error Opening Outfile" << std::endl;
		return 3;
	}
	while (getline(infile, buff))
		toReplace.append(buff).append("\n");
	std::string tmp = av[1];
	tmp.append(".replace");
	outfile << stringReplace(toReplace, av[2], av[3]);
	
	infile.close();
	outfile.close();
}
