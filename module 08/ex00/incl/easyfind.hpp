/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 14:37:01 by hlibine           #+#    #+#             */
/*   Updated: 2025/03/03 16:37:56 by hlibine          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_TEMPLATE_HPP
# define EASYFIND_TEMPLATE_HPP

#include <algorithm>
#include <exception>
#include <iostream>

class NotExistException : public std::exception {
	public:
		virtual const char *what() const throw() {
			return ("value did not exist in the provided container\n");
	}

};

template<typename T>
void	easyfind(T& cont, int target) {
	if (std::find(cont.begin(), cont.end(), target) != cont.end()) {
		std::cout << target << " exists in the provided container" << std::endl;
	}
	else {
		std::cout << target << " was not found in the provided container" << std::endl;
		throw NotExistException();
	}
}

#endif
