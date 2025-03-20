/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 13:59:01 by hlibine           #+#    #+#             */
/*   Updated: 2025/03/20 17:19:45 by hlibine          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/BitcoinExchange.hpp"
#include <cstring>
#include <stdexcept>

BtcEx::BtcEx() {std::cerr << "you should not be able to call this" << std::endl;}

BtcEx::BtcEx(const std::string &path) : path_(path) {}

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
		throw std::exception();
	if (month < 1 || month >12)
		throw std::exception();

	if (isLeapYear(year))
		daysInMonth[1] = 29;
	if (day < 1 || day > daysInMonth[month - 1])
		throw std::exception();

	return true;
}

void	sanatize(const std::string str, int mode) {
	std::string	valid;
	int			count = 0;

	if (mode == 0)
		valid = VALID_CSV;
	else
		valid = VALID_TXT;
	for (size_t i = 0, len = str.length(); i < len; i++) {
		if (!strchr(valid.c_str(), str[i]))
			throw std::runtime_error("invalid character");
		if (strchr(",|", str[i])) {
			++count;
			if (count >= 2)
				throw std::runtime_error("mutliple seperators");
		}
	}
}

std::string rtrim(const std::string &s) {
    size_t end = s.find_last_not_of(WHITESPACE);
    return (end == std::string::npos) ? "" : s.substr(0, end + 1);
}

void BtcEx::init() {
	std::ifstream	file;
	std::string		line, date, num, tmp;
	std::size_t		pos;
	float			val;
	char*			end;

	file.open(this->path_.c_str(), std::ios::in);
	if (!file.is_open())
		throw std::invalid_argument("Could not find / open databse file.\n");
	while (getline(file, line)) {
		try {
			sanatize(line, 0);
		}
		catch (const std::exception &e) {
			std::cerr << "Error: " << e.what() << " " << line << std::endl;
			continue ;
		}
		pos = line.find(',');
		if (pos == std::string::npos) {
			std::cerr << "Invalid data format: " << line << std::endl;
			continue ;
		}
		tmp = rtrim(line);
		if (pos == tmp.length() - 1) {
			std::cerr << "Invalid data format: " << line << std::endl;
			continue ;
		}
		try {
			date = line.substr(0, pos);
			checkDate(date);
		}
		catch (const std::exception &e) {
			std::cerr << "Invalid date: " << date << std::endl;
			(void)e;
			continue ;
		}
		end = NULL;
		num = line.substr(pos + 1);
		std::cout << num << std::endl;
		val = std::strtod(num.c_str(), &end);
		if (val >= 0 && end != NULL && *end == '\0')
			this->data_[date] = val;
		else
			std::cerr << "Error: \"" << num << "\" invalid" << std::endl; 
		std::cout << this->data_[date] << std::endl;
	}
	file.close();
}

void BtcEx::printMult(const std::string &date, const float num) {
	std::map<std::string, float>::iterator it	= this->data_.begin();
	std::map<std::string, float>::iterator iti	= this->data_.end();
	
	while (it != iti && it->first < date) {
		++it;
	}
	if (date < this->data_.begin()->first)
		std::cerr << "Date " << date << " is before any date in the database" << std::endl;
	else if (it->first == date) 
		std::cout << date << " => " << num << " = " << std::setprecision(8) << it->second * num << std::endl;
	else {
		--it;
		std::cout << it->first << " => " << num << " = " << std::setprecision(8) << it->second * num << std::endl;
	}
}

void BtcEx::process(std::ifstream &file) {
	
	std::string	line, date, closestDate, tmp;
	size_t		pos = -1;
	double		num = -1;
	char*		end;

	while (getline(file, line)) {
		try {
			sanatize(line, 1);
		}
		catch (const std::exception &e) {
			std::cerr << "Error: " << e.what() << " " << line << std::endl;
			continue ;
		}
		pos = line.find('|');
		if (pos  == std::string::npos) {
			std::cerr << "Error: Bad input => " << line << std::endl;
			 continue ;
		}
		if (rtrim(line)[pos + 1] == '\0') {
			std::cerr << "Error: Bad input => " << line << std::endl;
			continue ;
		}
		try {
			date = line.substr(0, pos);
			checkDate(date);
		}
		catch (const std::exception &e) {
			std::cerr << "Error: Bad date => " << line.substr(0, pos) << std::endl;
			(void)e;
			continue ;
		}
		num = std::strtod(line.substr(pos + 1).c_str(), &end);
		if (end == NULL && *end != '\0') {
			std::cerr << "Error: Bad number => " << line.substr(pos + 1) << std::endl;
			continue ;
		}
		if (num < 0) {
			std::cerr << "Error: not a positive number" << std::endl;
			continue ;
		}
		if (num > INT_MAX) {
			std::cerr << "Error: too large a number" << std::endl;
			continue ;
		}
		printMult(date, num);
	}
	file.close();
}
