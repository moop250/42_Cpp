/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:12:07 by hlibine           #+#    #+#             */
/*   Updated: 2024/12/23 14:25:01 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon)
		: name_(name), weapon_(weapon) {
}

HumanA::~HumanA(void) {
	std::cout << this->name_ << " destroyed" << std::endl;
	return ;
}

void HumanA::attack(void) {
	std::cout << this->name_ << " attacks with their "
		<< this->weapon_.getType() << std::endl;
	return ;
}

void HumanA::setWeapon(Weapon& weapon) {
	this->weapon_ = weapon;
	return ;
}