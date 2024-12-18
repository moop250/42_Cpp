/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 16:03:34 by hlibine           #+#    #+#             */
/*   Updated: 2024/12/18 16:34:08 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void)
{
	Harl		harl;
	std::string	input;

	while (!std::cin.eof()) {
		std::cout << "Please enter a level" << std::endl;
		std::getline(std::cin, input);
		if (!input.compare("exit") || std::cin.eof())
			return 0;
		harl.complain(input);
		std::cout << std::endl;
	}
	return 0;
}