/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:12:12 by hlibine           #+#    #+#             */
/*   Updated: 2024/09/12 22:06:28 by hlibine          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : type_(type) {
}

Weapon::~Weapon(void) {
}

const std::string	&Weapon::getType(void) const {
	return this->type_;
}

void	Weapon::setType(std::string weapon) {
	this->type_ = weapon;
	return ;
}
