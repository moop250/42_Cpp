/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:00:33 by hlibine           #+#    #+#             */
/*   Updated: 2024/11/26 15:22:41 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fragtrap.hpp"

// Constructors and destructors

FragTrap::FragTrap(const std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap " << name_ << " stumbles in after having been constructed" << std::endl;
	this->name_ = name;
	this->hp_ = 100;
	this->energyPoints_ = 100;
	this->attackDamage_ = 30;
}

FragTrap::FragTrap(const FragTrap &src) : ClapTrap(src.name_)
{
	std::cout << "FragTrap " << name_ << " has been cloned by the copy constructor" << std::endl;
	this->name_ = src.name_;
	this->hp_ = src.hp_;
	this->energyPoints_ = src.energyPoints_;
	this->attackDamage_ = src.attackDamage_;
}

FragTrap& FragTrap::operator=(const FragTrap &src)
{
	std::cout << "FragTrap " << name_ << " has been cloned by the copy assignment constructor" << std::endl;
	if (this != &src)
	{
		this->name_ = src.name_;
		this->hp_ = src.hp_;
		this->energyPoints_ = src.energyPoints_;
		this->attackDamage_ = src.attackDamage_;
	}
	return *this;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap " << name_ << " has been atomized" << std::endl;
}

// Class member functions

void FragTrap::highFiveGuys(void)
{
	std::cout << "FragTrap " << name_ << " calls for a high five" << std::endl;
}