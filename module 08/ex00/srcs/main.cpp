/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 14:26:44 by hlibine           #+#    #+#             */
/*   Updated: 2025/04/29 15:02:33 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/easyfind.hpp"
#include "../utils/colors.h"
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
		std::cout << easyfind(lst, 78) << std::endl;
		std::cout << easyfind(lst, 42) << std::endl;
		std::cout << easyfind(lst, 876) << std::endl;
		std::cout << easyfind(lst, 1969) << std::endl;
		std::cout << easyfind(lst, 76) << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << C_RED << e.what() << C_RESET;
	}

}
