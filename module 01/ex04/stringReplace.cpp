/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stringReplace.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 15:46:07 by hlibine           #+#    #+#             */
/*   Updated: 2024/09/13 17:25:56 by hlibine          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "stringReplace.hpp"

std::string stringReplace(std::string str, std::string s1, std::string s2) {
	std::string out;

	out = str;
	out.append("\n").append(s1).append("\n").append(s2).append("\n");
	return out;
}
