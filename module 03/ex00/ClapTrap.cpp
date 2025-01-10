/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:41:21 by hlibine           #+#    #+#             */
/*   Updated: 2025/01/10 14:53:42 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// Constructors and destructors

ClapTrap::ClapTrap(std::string name) : name_(name)
{
	std::cout << "ClapTrap constructor called for " << name << std::endl;
	this->hp_ = 10;
	this->energyPoints_ = 10;
	this->attackDamage_ = 5;
}

ClapTrap::ClapTrap(const ClapTrap &src)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	this->hp_ = src.hp_;
	this->energyPoints_ = src.energyPoints_;
	this->attackDamage_ = src.attackDamage_;
	this->name_ = src.name_;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &src)
{
	std::cout << "ClapTrap copy assignment constructor called" << std::endl;
	if (this != &src)
	{
		this->hp_ = src.hp_;
		this->energyPoints_ = src.energyPoints_;
		this->attackDamage_ = src.attackDamage_;
		this->name_ = src.name_;
	}
	return *this;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap destructor called for " << this->name_ << std::endl;
}

// Class member functions

void ClapTrap::attack(const std::string &target)
{
	if (this->hp_ > 0 && energyPoints_ > 0)
	{
		std::cout << this->name_ << " attacks " << target << " causing " << this->attackDamage_ << " damage" << std::endl;
		--this->energyPoints_;
	}
	else if (this->hp_ <= 0)
		std::cout << this->name_ << " is dead, and cannot attack" << std::endl;
	else
		std::cout << this->name_ << " does not have the energy to attack" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hp_ <= 0)
	{
		std::cout << this->name_
			<< " is already dead... why are you still attacking them... you monster" << std::endl;
		return ;
	}
	if (amount > this->hp_)
		this->hp_ = 0;
	else
		this->hp_ -= amount;
	std::cout << this->name_ << " takes " << amount << " points of damage" << std::endl;
	if (this->hp_ <= 0)
		std::cout << this->name_ << " has succum to their wounds" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amonut)
{
	if (this->hp_ > 0 && energyPoints_ > 0)
	{
		this->hp_ += amonut;
		--this->energyPoints_;
		std::cout << this->name_ << " repairs themselves for "
			<< amonut << " hitpoints " << std::endl;
	}
	else if (this->hp_ <= 0)
		std::cout << this->name_ << " is dead, and cannot repair themselves" << std::endl;
	else
		std::cout << this->name_ << " is out of energy, and cannot repair themselves" << std::endl;
}