/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:42:15 by hlibine           #+#    #+#             */
/*   Updated: 2024/09/11 19:23:38 by hlibine          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void randomChump(std::string name) {
	Zombie	tmp = Zombie(name);
	tmp.announce();
	return ;
}
