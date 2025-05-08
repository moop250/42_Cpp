/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 10:15:06 by hlibine           #+#    #+#             */
/*   Updated: 2025/05/08 13:58:13 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_CLASS_HPP
# define RPN_CLASS_HPP

#include <cstdlib>
#include <cstring>
#include <stack>
#include <stdexcept>

#define WHITESPACE " \n\r\t\f\v"
#define NUMBERS "0123456789"
#define OPERATIONS "+-/*"

class RPN {
	public:
		static long calculate(const std::string in);
		virtual ~RPN() = 0;
};

#endif
