/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 18:12:01 by hlibine           #+#    #+#             */
/*   Updated: 2024/09/04 16:01:25 by hlibine          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include <cstring>
#include <iostream>
#include <ostream>
#include <string>
#include "PhoneBook.hpp"

int main(void) {

	PhoneBook	book;
	std::string	input = "";
	
	book.welcome();
	while (input.compare("EXIT")) {
		std::cout << "# " << std::flush;
		std::cin >> input;
		std::cout << "you input: " << input << std::endl;
	}
	return (0);
}
