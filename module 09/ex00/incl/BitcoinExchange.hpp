/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 13:58:59 by hlibine           #+#    #+#             */
/*   Updated: 2025/03/14 23:54:56 by hlibine          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <fstream>
#include <map>
#include <string>

#define WHITESPACE " \n\r\t\f\v"

class BtcEx {
	private:
		std::map<std::string, float>	data_;
		const std::string				path_;
		BtcEx(void);

	public:
		BtcEx(const std::string &path);
		BtcEx(const BtcEx &src);
		BtcEx& operator=(const BtcEx &src);
		~BtcEx();

		void	init(void);
		void	process(std::ifstream &file);
};

#endif

