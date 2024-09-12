/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:12:07 by hlibine           #+#    #+#             */
/*   Updated: 2024/09/12 22:17:29 by hlibine          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string name, Weapon& weapon)
		: name_(name), weapon_(weapon) {
}

HumanA::~HumanA(void) {
	std::cout << name_ << " destroyed" << std::endl;
	return ;
}

void HumanA::attack(void) {
	std::cout << name_ << " attacks with their " << weapon_.getType() << std::endl;
	return ;
}
