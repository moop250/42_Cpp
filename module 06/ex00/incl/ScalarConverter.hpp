/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:25:22 by hlibine           #+#    #+#             */
/*   Updated: 2025/02/05 18:36:34 by hlibine          ###   LAUSANNE.ch       */
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
		ScalarConverter(const ScalarConverter  &src);
		ScalarConverter& operator=(const ScalarConverter &src);
		~ScalarConverter();

	public:
		static void convert(const std::string src);
};

#endif
