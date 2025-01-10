/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:41:05 by hlibine           #+#    #+#             */
/*   Updated: 2025/01/10 15:28:39 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap jeff("Jeff");
	ClapTrap john("John");

	jeff.guardGate();
	jeff.guardGate();
	john.attack("Jeff");
	jeff.takeDamage(7);
	jeff.beRepaired(4);
	john.attack("Jeff");
	jeff.takeDamage(999);
	jeff.beRepaired(10);
	jeff.attack("John");
	john.beRepaired(5);
	john.attack("Jeff");
	jeff.takeDamage(3);
	for (int i = 0; i < 7; i++)
		john.beRepaired(1);
	john.attack("Jeff");
	jeff.guardGate();

	return 0;
}