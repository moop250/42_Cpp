/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:32:56 by hlibine           #+#    #+#             */
/*   Updated: 2025/04/15 17:07:10 by hlibine          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Array.tpp"
#include <exception>
#include <iostream>

int	main(void) {

	{
		Array<int>	int1;
		Array<char>	str(0);
		Array<int>	int2(4);
	
		for (int i = 0; i < 4; i++) {
			try {
				str[i] = i * 2;
				std::cout << "\"" << str[i] << "\"";
			}
			catch(const std::exception& e) {
				std::cerr << e.what();
			}
		}
		std::cout << std::endl;
		try {
			std::cout << int1[0] << std::endl;
		}
		catch(const std::exception& e) {
			std::cerr << e.what();
		}
		std::cout << std::endl;
		for (int i = 0; i < 3; i++) {
			try {
				int2[i] = i * 2;
				std::cout << int2[i] << std::endl;
			}
			catch(const std::exception& e) {
				std::cerr << e.what();
			}
		}
		std::cout << std::endl;
		int1 = int2;
		for (int i = 0; i < 3; i++) {
			try {
				int1[i] = i * 2;
				std::cout << int2[i] << std::endl;
			}
			catch(const std::exception& e) {
				std::cerr << e.what();
			}
		}
	}
	std::cout << std::endl;
	{
		Array<int>	i(200);
		int *j = new int[200];

		try {
			for (int k = 0; k < 200; k++) {
				i[k] = k;
				j[k] = k;
			}
			for (int k = 0; k < 200; k++) {
				std::cout << "i: " << i[k] << std::endl;
				std::cout << "j: " << j[k] << std::endl;
			}
			std::cout << std::endl;
		}
		catch(const std::exception &e) {
			std::cerr << e.what();
		}
		try {
			i[-1] = 42;
		}
		catch(const std::exception& e) {
			std::cerr << e.what();
		}

		delete [] j;
	}
}
