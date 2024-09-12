/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:42:14 by hlibine           #+#    #+#             */
/*   Updated: 2024/09/12 13:46:56 by hlibine          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	newZombie(std::string str);
void	randomChump(std::string str);

int	main() {

	std::cout << "- Create the zombie \"james\"" << std::endl;
	Zombie james = Zombie("james");

	std::cout << "- Create zombie \"geoff\" with newZombie()" << std::endl;
	Zombie* geoff = newZombie("geoff");
	geoff->announce();
	delete geoff;

	std::cout << "- Create zombie \"Jane\" with randomChump()" << std::endl;
	randomChump("jane");

	return (0);
}
