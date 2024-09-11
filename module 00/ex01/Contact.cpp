/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 13:57:04 by hlibine           #+#    #+#             */
/*   Updated: 2024/09/11 15:10:36 by hlibine          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact( void ) {
	this->vaild_ = false;
}

Contact::~Contact( void ) {
}

std::string Contact::getInput_(std::string str) const {
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
	this->firstName_ = this->getInput_("Please input your first name : ");
	this->lastName_ = this->getInput_("Please input your last name : ");
	this->nickname_ = this->getInput_("Please input your nickname : ");
	this->phoneNumber_ = this->getInput_("Please input your phone number : ");
	this->darkestSecret_ = this->getInput_("Please input your darkest secret : ");
	std::cout << std::endl;
	this->vaild_ = true;
}

void Contact::setIndex(int i) {
	this->index_ = i;
}

std::string Contact::truncator_(std::string str) const {
	if(str.length() > 10)
		return (str.substr(0, 9) + '.');
	return (str);
}

void Contact::show(void) {
	if (this->firstName_.empty() || this->lastName_.empty() || this->nickname_.empty())
		return ;
	std::cout << "|" << std::setw(10) << this->index_ << std::flush;
	std::cout << "|" << std::setw(10) << this->truncator_(this->firstName_) << std::flush;
	std::cout << "|" << std::setw(10) << this->truncator_(this->lastName_) << std::flush;
	std::cout << "|" << std::setw(10) << this->truncator_(this->nickname_) << std::flush;
	std::cout << "|" << std::endl;
}

void Contact::displayContact(int i) const{
	std::cout << "\nNow Showing Index: [" << i << "]\n";
	std::cout << "First Name:        [" << this->firstName_ << "]\n";
	std::cout << "Last Name:         [" << this->lastName_ << "]\n";
	std::cout << "Nickname:          [" << this->nickname_ << "]\n";
	std::cout << "Phone Number:      [" << this->phoneNumber_ << "]\n";
	std::cout << "Darkest Secret:    [" << this->darkestSecret_ << "]\n";
	std::cout << std::endl << std::flush;
}

bool Contact::getvaild(void) const {
	return this->vaild_;
}
