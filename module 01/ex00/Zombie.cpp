/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:42:07 by hlibine           #+#    #+#             */
/*   Updated: 2024/12/18 14:02:58 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string str) : name_(str) {
	std::cout << this->name_ << " created" << std::endl;
	return ;
}

Zombie::~Zombie(void) {
	std::cout << this->name_ << " destroyed" << std::endl;
	return ;
}

void	Zombie::announce(void) {
	std::cout << this->name_ << ": BraiiiiiiinnnzzzZ..." << std::endl;
	return ;
}
