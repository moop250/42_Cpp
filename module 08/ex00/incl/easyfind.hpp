/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 14:37:01 by hlibine           #+#    #+#             */
/*   Updated: 2025/04/16 16:18:56 by hlibine          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_TEMPLATE_HPP
# define EASYFIND_TEMPLATE_HPP

#include <algorithm>
#include <iostream>

template<class T>
int	easyfind(T& cont, int target) {
	if (std::find(cont.begin(), cont.end(), target) == cont.end())
		throw std::runtime_error("Error: requested value was not found in the provided container\n");
	return target;
}

template<class T>
int	easyfind(const T& cont, const int target) {
	if (std::find(cont.begin(), cont.end(), target) == cont.end())
		throw std::runtime_error("Error: requested value was not found in the provided container\n");
	return target;
}

#endif
