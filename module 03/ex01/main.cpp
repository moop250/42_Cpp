/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:41:05 by hlibine           #+#    #+#             */
/*   Updated: 2024/11/26 14:05:13 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap jeff("Jeff");
	ClapTrap john("John");

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
	john.beRepaired(1);
	john.beRepaired(1);
	john.beRepaired(1);
	john.beRepaired(1);
	john.beRepaired(1);
	john.beRepaired(1);
	john.beRepaired(1);
	john.beRepaired(1);
	john.beRepaired(1);
	john.beRepaired(1);
	john.attack("Jeff");
	jeff.guardGate();

	return 0;
}