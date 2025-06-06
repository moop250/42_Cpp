/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:44:46 by hlibine           #+#    #+#             */
/*   Updated: 2025/01/10 15:29:08 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap constructor called for " << name_ << std::endl;
	this->hp_ = 100;
	this->energyPoints_ = 50;
	this->attackDamage_ = 20;
	this->isGuarding_ = false;
}

ScavTrap::ScavTrap(const ScavTrap &src) : ClapTrap(src.name_)
{
	std::cout << "ScavTrap " << name_ << " created with copy constructor" << std::endl;
	this->hp_ = src.hp_;
	this->energyPoints_ = src.energyPoints_;
	this->attackDamage_ = src.attackDamage_;
	this->name_ = src.name_;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &src)
{
	std::cout << "ScavTrap " << name_ << " created with copy assignment constructor" << std::endl;
	if (this != &src)
	{
		this->hp_ = src.hp_;
		this->energyPoints_ = src.energyPoints_;
		this->attackDamage_ = src.attackDamage_;
		this->name_ = src.name_;
	}
	return *this;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap " << name_ << " destroyed" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (this->hp_ > 0 && energyPoints_ > 0)
	{
		std::cout << "ScavTrap " << this->name_ << " bashes " << target << " dealing " << this->attackDamage_ << " damage" << std::endl;
		--this->energyPoints_;
	}
	else if (this->hp_ <= 0)
		std::cout << "ScavTrap " << this->name_ << " is dead, and cannot attack" << std::endl;
	else
		std::cout << "ScavTrap " << this->name_ << " does not have the energy to attack" << std::endl;
}

void ScavTrap::guardGate(void)
{
	if (this->hp_ > 0 && energyPoints_ > 0 && !this->isGuarding_)
		std::cout << "ScavTrap " << this->name_ << " enters gatekeeping mode" << std::endl;
	else if (this->hp_ <= 0)
		std::cout << "ScavTrap " << this->name_ << " has died and cannot gatekeep :(" << std::endl;
	else if (this->energyPoints_ <= 0)
		std::cout << "ScavTrap " << this->name_ << " does not have the energy to gatekeep" << std::endl;
	else
		std::cout << "ScavTrap " << this->name_ << " is already gatekeeping" << std::endl;
	this->isGuarding_ = true;
}