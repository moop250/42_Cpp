/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stringReplace.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 15:46:07 by hlibine           #+#    #+#             */
/*   Updated: 2024/10/22 17:39:39 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stringReplace.hpp"
#include <cstddef>

std::string stringReplace(const std::string str, const std::string s1, const std::string s2) {
	size_t		pos = 0;
	size_t		s1Len = s1.length();
	size_t		s2Len = s2.length();
	std::string	out;

	out = str;
	while(pos = out.find(s1, pos), pos != std::string::npos) {
		out.erase(pos, s1Len);
		out.insert(pos, s2);
		pos += s2Len;
	}
	return out;
}
