/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:11:29 by hlibine           #+#    #+#             */
/*   Updated: 2024/12/21 16:06:48 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Animal.hpp"


/*   Constructors and Destructors   */

abAnimal::abAnimal()
{
	this->type_ = "Boring Animal";
	std::cout << "Default Animal constructor called" << std::endl;
}

abAnimal::abAnimal(const abAnimal &src)
{
	this->type_ = src.type_;
	std::cout << "Animal Copy constructor called" << std::endl;
}

abAnimal& abAnimal::operator=(const abAnimal& src)
{
	std::cout << "Animal Assignation constructor called" << std::endl;
	if (this != &src)
		this->type_ = src.type_;
	return *this;
}

abAnimal::~abAnimal(void)
{
	std::cout << "Animal destructor called" << std::endl;
}

/*   Class Functions   */

std::string abAnimal::getType(void) const
{
	return this->type_;
}

void abAnimal::makeSound(void) const
{
	std::cout << this->type_ << " makes a sound " << std::endl;
}