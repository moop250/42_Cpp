/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:12:09 by hlibine           #+#    #+#             */
/*   Updated: 2024/09/12 22:14:36 by hlibine          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name_(name){
	weapon_ = NULL;
}

HumanB::~HumanB(void) {
	std::cout << name_ << " destroyed" << std::endl;
	return ;
}

void HumanB::setWeapon(Weapon& weapon) {
	this->weapon_ = &weapon;
	return ;
}

void	HumanB::attack(void) {
	if (this->weapon_)
		std::cout << this->name_ << " attacks with thier " << this->weapon_->getType() << std::endl;
}
