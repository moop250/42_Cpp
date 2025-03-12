/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 13:59:01 by hlibine           #+#    #+#             */
/*   Updated: 2025/03/12 17:30:23 by hlibine          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/BitcoinExchange.hpp"
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>

BtcEx::BtcEx() {std::cerr << "you should not be able to call this" << std::endl;}

BtcEx::BtcEx(std::string &path) : path_(path) {}

BtcEx::BtcEx(const BtcEx &src) : data_(src.data_), path_(src.path_) {}

BtcEx& BtcEx::operator=(const BtcEx &src) {

	if (this != &src)
		this->data_ = src.data_;

	return *this;
}

BtcEx::~BtcEx() {}

bool isLeapYear(int year) {
	return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

bool checkDate(std::string in) {
	int	year, month, day, pos, pos2;
	int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	pos = in.find('-');
	year = atoi(in.substr(0, pos).c_str());
	pos2 = in.find('-', pos + 1);
	month = atoi(in.substr(pos + 1, 2).c_str());
	day = atoi(in.substr(pos2 + 1).c_str());

	if (year < 1)
		return false;
	if (month < 1 || month >12)
		return false;

	if (isLeapYear(year))
		daysInMonth[1] = 29;
	if (day < 1 || day > daysInMonth[month - 1])
		return false;

	return true;
}

void BtcEx::init() {
	std::ifstream	file;
	std::string		line, date, num;
	std::size_t		pos;
	float			val;
	char*			end;

	file.open(this->path_.c_str(), std::ios::in);
	if (!file.is_open())
		throw std::invalid_argument("Could not find / open databse file.\n");
	while (getline(file, line)) {
		pos = line.find(',');
		if (pos == std::string::npos) {
			std::cerr << "Invalid data format" << std::endl;
			continue ;
		}
		try {
			date = line.substr(0, pos - 1);
			checkDate(date);
		}
		catch (const std::exception &e) {
			(void)e;
			continue ;
		}
		end = NULL;
		num = line.substr(pos + 1);
		val = std::strtof(num.c_str(), &end);
		if (val >= 0 && end != NULL && *end != '\0')
			this->data_[date] = val;
		else
			std::cerr << "Error: \"" << num << "\" invalid" << std::endl; 
	}
	file.close();
}
