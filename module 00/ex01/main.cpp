/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 18:12:01 by hlibine           #+#    #+#             */
/*   Updated: 2024/09/04 17:52:52 by hlibine          ###   LAUSANNE.ch       */
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
		if (!input.compare("ADD"))
			std::cout << "im here\n";
		else if (!input.compare("SEARCH"))
			std::cout << "wawa\n";
		std::cout << "# " << std::flush;
		std::cin >> input;
	}
	return (0);
}
