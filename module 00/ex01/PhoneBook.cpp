/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 18:12:01 by hlibine           #+#    #+#             */
/*   Updated: 2024/09/11 15:10:54 by hlibine          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook( void ) {
}

PhoneBook::~PhoneBook( void ) {
}

bool PhoneBook::isNum_(std::string str) const {
	for (size_t i = 0; i < str.size(); ++i)
		if (!std::isdigit(str[i]))
			return false;
	return true;
}

std::string PhoneBook::getNum_(std::string str) const {
	std::string	input = "";
	bool		valid = false;

	do {
		std::cout << str << std::flush;
		if (!std::getline(std::cin, input)) {
			std::cout << "eof" << std::endl;
			break;
		} else if (!input.empty() && isNum_(input)) {
			int num = std::atoi(input.c_str());
			if (num >= 0 && num <= 7 ) {
				if (this->contacts_[num].getvaild())
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
	this->contacts_[tmp].init();
	this->contacts_[tmp].setIndex(tmp);
	++i;
}

void PhoneBook::search() {
	if (!this->contacts_[0].getvaild()) {
		std::cout << "There are no contacts saved.\n";
		return ;
	}
	std::cout << "---------------------------------------------\n";
	std::cout << "|     Index|      Name| Last Name|  Nickname|\n";
	for (int i = 0; i < 8; ++i)
		this->contacts_[i].show();
	std::cout << "---------------------------------------------\n" << std::flush;
	int tmp = std::atoi(getNum_("What index would you like to see: ").c_str());
	this->contacts_[tmp].displayContact(tmp);
}
