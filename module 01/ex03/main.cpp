/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:12:15 by hlibine           #+#    #+#             */
/*   Updated: 2024/12/23 14:23:53 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int	main(void) {
	{
		Weapon club = Weapon("crude spiked club");
		Weapon bat = Weapon("baseball bat");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
		bob.setWeapon(bat);
		bob.attack();
	}
	{
		Weapon baton = Weapon("police baton");
		Weapon sword = Weapon("sword");
		HumanB jim("Jim");
		jim.attack();
		jim.setWeapon(baton);
		jim.attack();
		baton.setType("some other type of baton");
		jim.attack();
		jim.setWeapon(sword);
		jim.attack();
	}
}
