/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:25:25 by hlibine           #+#    #+#             */
/*   Updated: 2025/03/26 18:28:14 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ScalarConverter.hpp"
#include <cctype>
#include <cmath>

ScalarConverter::ScalarConverter(){};
ScalarConverter::ScalarConverter(const ScalarConverter &src){(void)src;};
ScalarConverter& ScalarConverter::operator=(const ScalarConverter &src){(void)src;return *this;};
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
	
	if (tmp && strlen(tmp) > 0) {
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
	if ((nb > 0 || nb < 128) && isprint(static_cast<char>(nb)))
		std::cout << "'" << static_cast<char>(nb) << "'" << std::endl;
	else if (!isprint(static_cast<char>(nb)) && (nb > 0 || nb < 128))
		std::cerr << "Non displayable" << std::endl;
	else
		std::cerr << "Impossible" << std::endl;
	(void)tmp;

	std::cout << "int:\t";
	if (nb <= INT_MAX && nb >= INT_MIN) {
		std::cout << static_cast<int>(nb) << std::endl;
	}
	else {
		std::cerr << "Impossible"  << std::endl;
	}

	std::cout << "float:\t";
	std::cout << nb;
	if (trunc(nb) != nb || nb == INFINITY || -INFINITY)
		std::cout << "f" << std::endl;
	else
		std::cout  << ".0f" << std::endl;

	std::cout << "double:\t";
	std::cout << nb;
	if (trunc(nb) == nb && nb != INFINITY && nb != -INFINITY)
		std::cout << ".0" << std::endl;
	else
		std::cout << std::endl;
}
