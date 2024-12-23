/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stringReplace.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 15:46:07 by hlibine           #+#    #+#             */
/*   Updated: 2024/12/23 14:26:51 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stringReplace.hpp"

std::string stringReplace(const std::string str, const std::string s1, const std::string s2) {
	size_t		pos = 0;
	size_t		s1Len = s1.length();
	size_t		s2Len = s2.length();
	std::string	out;

	out = str;
	while(pos = out.find(s1, pos), pos != std::string::npos) {
		out.erase(pos, s1Len);
		out.insert(pos, s2);
		pos += s2Len;
	}
	return out;
}


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
