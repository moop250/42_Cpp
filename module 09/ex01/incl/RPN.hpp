/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 10:15:06 by hlibine           #+#    #+#             */
/*   Updated: 2025/03/26 16:17:18 by hlibine          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_CLASS_HPP
# define RPN_CLASS_HPP

#include <string>

#define WHITESPACE " \n\r\t\f\v"
#define NUMBERS "0123456789"
#define OPERATIONS "+-/*"

class RPN {
	public:
		static size_t calculate(const std::string in);
};

#endif
