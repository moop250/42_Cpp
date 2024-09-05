/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 18:12:01 by hlibine           #+#    #+#             */
/*   Updated: 2024/09/05 21:50:29 by hlibine          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include <cstring>
#include <iostream>
#include <string>
#include "PhoneBook.hpp"

int main(void) {
	
	PhoneBook	book;
	std::string	input = "";
	
	book.welcome();
	while (input.compare("EXIT") && !std::cin.eof()) {
		if (!input.compare("ADD"))
			book.addContact();
		else if (!input.compare("SEARCH"))
			book.search();
		std::cout << "# " << std::flush;
		std::getline(std::cin, input);
	}
	return (0);
}
