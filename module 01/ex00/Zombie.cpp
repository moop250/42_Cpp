/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:42:07 by hlibine           #+#    #+#             */
/*   Updated: 2024/12/23 13:59:06 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string str) : name_(str) {
	std::cout << this->name_ << " created" << std::endl;
}

Zombie::~Zombie(void) {
	std::cout << this->name_ << " destroyed" << std::endl;
}

void	Zombie::announce(void) {
	std::cout << this->name_ << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
