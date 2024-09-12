/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:42:07 by hlibine           #+#    #+#             */
/*   Updated: 2024/09/11 19:24:21 by hlibine          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string str) : name_(str) {
}

Zombie::~Zombie(void) {
	std::cout << name_ << " destroyed" << std::endl;
	return ;
}

void	Zombie::announce(void) {
	std::cout << name_ << ": BraiiiiiiinnnzzzZ..." << std::endl;
	return ;
}
