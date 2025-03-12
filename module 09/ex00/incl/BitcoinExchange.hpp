/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 13:58:59 by hlibine           #+#    #+#             */
/*   Updated: 2025/03/11 14:14:05 by hlibine          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
class BtcEx {
	private:
		std::map<std::string, float>	data_;
		const std::string				path_;
		BtcEx(void);

	public:
		BtcEx(std::string &path);
		BtcEx(const BtcEx &src);
		BtcEx& operator=(const BtcEx &src);
		~BtcEx();

		void	init(void);
};

#endif

