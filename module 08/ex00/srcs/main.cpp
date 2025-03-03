/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 14:26:44 by hlibine           #+#    #+#             */
/*   Updated: 2025/03/03 16:39:32 by hlibine          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/easyfind.hpp"
#include <list>

std::list<int> lstInit(void) {
	std::list<int>	lst;

	lst.push_back(78);
	lst.push_back(876);
	lst.push_back(42);
	lst.push_back(1978);
	lst.push_back(2000);
	lst.push_back(76);

	return lst;
}

int	main(void) {
	std::list<int>	lst;

	lst = lstInit();
	
	try {
		easyfind(lst, 78);
		easyfind(lst, 42);
		easyfind(lst, 876);
		easyfind(lst, 1969);
	}
	catch(const std::exception& e) {
		std::cerr << e.what();
	}

}
