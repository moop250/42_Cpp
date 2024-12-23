/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:42:07 by hlibine           #+#    #+#             */
/*   Updated: 2024/12/23 14:11:47 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void) : name_("Default"), id_(0) {
	std::cout << "Default contstructor called" << std::endl; 
}

Zombie::~Zombie(void) {
	std::cout << this->name_ << " [" << this->id_ << "] destroyed" << std::endl;
}

void	Zombie::announce(void) {
	std::cout << this->name_ << " [" << this->id_
		<< "] : BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setInfo(std::string &str, size_t i) {
	this->name_ = str;
	this->id_ = i;

	std::cout << "Assigned name " << this->name_ << " with id " << this->id_ << std::endl;
}
