/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 13:58:59 by hlibine           #+#    #+#             */
/*   Updated: 2025/03/19 16:24:55 by hlibine          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <fstream>
#include <map>
#include <string>
#include <climits>
#include <iostream>
#include <iomanip>

#define WHITESPACE " \n\r\t\f\v"

class BtcEx {
	private:
		std::map<std::string, float>	data_;
		const std::string				path_;
		BtcEx(void);
		void	printMult(const std::string &date, const float num);

	public:
		BtcEx(const std::string &path);
		BtcEx(const BtcEx &src);
		BtcEx& operator=(const BtcEx &src);
		~BtcEx();

		void	init(void);
		void	process(std::ifstream &file);
};

#endif

