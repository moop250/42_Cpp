/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:25:22 by hlibine           #+#    #+#             */
/*   Updated: 2025/02/04 13:00:05 by hlibine          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_CLASS
# define SCALARCONVERTER_CLASS

#include <iostream>
#include <string>
#include <cmath>

class ScalarConverter{
	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter  &src);
		ScalarConverter& operator=(ScalarConverter &src);
		~ScalarConverter();

	public:
		static void convert(const std::string src);
};

#endif
