/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:41:05 by hlibine           #+#    #+#             */
/*   Updated: 2024/11/22 16:18:05 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap jeff("Jeff");
	ClapTrap john("John");

	jeff.attack("John");
	john.takeDamage(5);
	john.attack("Jeff");
	jeff.takeDamage(7);
	jeff.beRepaired(4);
	john.attack("Jeff");
	jeff.takeDamage(7);
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

	return 0;
}