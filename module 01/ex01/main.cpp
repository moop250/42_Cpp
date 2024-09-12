/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:08:44 by hlibine           #+#    #+#             */
/*   Updated: 2024/09/12 16:55:19 by hlibine          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


Zombie*	zombieHorde(int N, std::string name);

int	main(void) {
	int	n = 10;

	Zombie *tmp = zombieHorde(n, "jeff");
	for (int i = 0; i < n; ++i)
		tmp[i].announce();

	delete [] tmp;
	return 0;
}
