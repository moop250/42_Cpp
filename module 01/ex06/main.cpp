/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 16:03:34 by hlibine           #+#    #+#             */
/*   Updated: 2024/11/04 16:56:56 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av)
{
	Harl		harl;
	std::string upper;

	if (ac < 2)
		return 1;

	for (int i = 0; av[1][i]; i++)
		upper += std::toupper(av[1][i]);

	harl.complain(upper);
	return 0;
}