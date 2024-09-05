/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 18:12:01 by hlibine           #+#    #+#             */
/*   Updated: 2024/09/04 17:57:30 by hlibine          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook( void ) {
}

PhoneBook::~PhoneBook( void ) {
}

void PhoneBook::welcome() {
	std::cout << "\n   Welcome to \"good\" phonebook\n";
	std::cout << "--------------Usage--------------\n";
	std::cout << " ADD - Adds a new contact\n";
	std::cout << " SEARCH - Searches for a contact\n";
	std::cout << " EXIT - Exits the program\n" << std::endl;
}
