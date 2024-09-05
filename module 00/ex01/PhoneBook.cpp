/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 18:12:01 by hlibine           #+#    #+#             */
/*   Updated: 2024/09/05 23:39:38 by hlibine          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

PhoneBook::PhoneBook( void ) {
}

PhoneBook::~PhoneBook( void ) {
}

bool PhoneBook::_isNumber(std::string str) const {
	for (size_t i = 0; i < str.size(); ++i)
		if (!std::isdigit(str[i]))
			return false;
	return true;
}

std::string PhoneBook::_getNum(std::string str) const {
	std::string	input = "";
	bool		valid = false;

	do {
		std::cout << str << std::flush;
		if (!std::getline(std::cin, input)) {
			std::cout << "eof" << std::endl;
			break;
		} else if (!input.empty() && _isNumber(input)) {
			int num = std::atoi(input.c_str());
			if (num >= 0 && num <= 7 ) {
				if (this->_contacts[num].vaild)
					valid = true;
				else
					std::cout << "Invalid input: there is no contact under this index\n";
			} else
				std::cout << "Invalid input: that number is not between 0-7\n";
		} else
			std::cout << "Invalid input: please enter a number between 0-7\n";
	} while (!valid);
	return (input);
}

void PhoneBook::welcome() {
	std::cout << "\n   Welcome to \"good\" phonebook\n";
	std::cout << "--------------Usage--------------\n";
	std::cout << " ADD - Adds a new contact\n";
	std::cout << " SEARCH - Searches for a contact\n";
	std::cout << " EXIT - Exits the program\n" << std::endl;
}

void PhoneBook::addContact() {
	static int	i;
	int			tmp;

	tmp = i % 8;
	this->_contacts[tmp].init();
	this->_contacts[tmp].setIndex(tmp);
	++i;
}

void PhoneBook::search() {
	if (!this->_contacts[0].vaild) {
		std::cout << "There are no contacts saved.\n";
		return ;
	}
	for (int i = 0; i < 8; ++i)
		this->_contacts[i].show();
	int tmp = std::atoi(_getNum("What index would you like to see: ").c_str());
	this->_contacts[tmp].displayContact(tmp);
}
