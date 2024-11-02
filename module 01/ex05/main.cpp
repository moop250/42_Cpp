/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 16:03:34 by hlibine           #+#    #+#             */
/*   Updated: 2024/11/02 13:43:30 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void)
{
	Harl		harl;
	std::string	input;

	do {
		std::cout << "Please enter a level" << std::endl;
		std::cin >> input;
		harl.complain(input);
		std::cout << std::endl;
	}while (input.compare("exit"));
	
	return 0;
}