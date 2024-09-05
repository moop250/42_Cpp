/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 13:57:04 by hlibine           #+#    #+#             */
/*   Updated: 2024/09/05 23:18:21 by hlibine          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact( void ) {
	this->vaild = false;
}

Contact::~Contact( void ) {
}

std::string Contact::_getInput(std::string str) const {
	std::string	input = "";
	bool	valid = false;

	do {
		std::cout << str << std::flush;
		if (!std::getline(std::cin, input)) {
			std::cout << "eof" << std::endl;
			break;
		}
		if (!input.empty())
			valid = true;
		else
			std::cout << "Invalid input, please try again." << std::endl;
	} while (!valid);
	return (input);
}

void Contact::init(void) {
	this->_firstName = this->_getInput("Please input your first name : ");
	this->_lastName = this->_getInput("Please input your last name : ");
	this->_nickname = this->_getInput("Please input your nickname : ");
	this->_phoneNumber = this->_getInput("Please input your phone number : ");
	this->_darkestSecret = this->_getInput("Please input your darkest secret : ");
	std::cout << std::endl;
	this->vaild = true;
}

void Contact::setIndex(int i) {
	this->_index = i;
}

std::string Contact::_truncator(std::string str) const {
	if(str.length() > 10)
		return (str.substr(0, 9) + '.');
	return (str);
}

void Contact::show(void) {
	if (this->_firstName.empty() || this->_lastName.empty() || this->_nickname.empty())
		return ;
	std::cout << "|" << std::setw(10) << this->_index << std::flush;
	std::cout << "|" << std::setw(10) << this->_truncator(this->_firstName) << std::flush;
	std::cout << "|" << std::setw(10) << this->_truncator(this->_lastName) << std::flush;
	std::cout << "|" << std::setw(10) << this->_truncator(this->_nickname) << std::flush;
	std::cout << "|" << std::endl;
}

void Contact::displayContact(int i) const{
	std::cout << "input: " << i << "\n";
	std::cout << "index: " << this->_index << "\n";
}
