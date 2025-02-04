/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:25:25 by hlibine           #+#    #+#             */
/*   Updated: 2025/02/04 16:19:29 by hlibine          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ScalarConverter.hpp"
#include <climits>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>

ScalarConverter::ScalarConverter(){};
ScalarConverter::ScalarConverter(ScalarConverter &src){(void)src;};
ScalarConverter& ScalarConverter::operator=(ScalarConverter &src){(void)src;return *this;};
ScalarConverter::~ScalarConverter(){};


void ScalarConverter::convert(const std::string src) {
	double	nb = 0;
	char	*tmp = NULL;

	if(src.length() == 1 && !isdigit(src[0]) && isprint(src[0])) {
		nb = static_cast<double>(src[0]);
	}
	else {
		nb = strtod(src.c_str(), &tmp);
	}
	if (tmp && strlen(tmp) > 1) {
		std::cerr << "invalid characters in input: ";
		for (size_t i = 0; i < strlen(tmp); i++) {
			if (tmp[i] == 46 || (tmp[i] >= 48 && tmp[i] <= 57)) {
			}
			else {
				std::cerr << tmp[i];
			}
		}
		std::cerr << std::endl;
		return ;
	}

	std::cout << "char:\t";
	if (nb >= 0 && nb <= 128 && !isprint(nb))
		std::cerr << "Non displayable" << std::endl;
	else if (nb < 0 || nb > 128)
		std::cerr << "Impossible" << std::endl;
	else
		std::cout << "'" << static_cast<char>(nb) << "'" << std::endl;
	(void)tmp;

	std::cout << "int:\t";
	if (nb <= INT_MAX || nb >= INT_MIN) {
		std::cout << static_cast<int>(nb) << std::endl;
	}
	else {
		std::cerr << "Impossible"  << std::endl;
	}

	std::cout << "float:\t";
	std::cout << nb;
	if (trunc(nb) != nb || nb == INFINITY)
		std::cout << "f" << std::endl;
	else
		std::cout  << ".0f" << std::endl;
}
