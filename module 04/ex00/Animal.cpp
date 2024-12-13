/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:11:29 by hlibine           #+#    #+#             */
/*   Updated: 2024/12/10 15:44:48 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"


/*   Constructors and Destructors   */

Animal::Animal()
{
	this->type = "Unspeakable Horror";
	std::cout << "Default Animal constructor called" << std::endl;
}

Animal::Animal(std::string type)
{
	this->type = type;
	std::cout << "Named Animal constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& src)
{
	std::cout << "Assignation Animal constructor called" << std::endl;
	if (this != &src)
		this->type = src.type;
	return *this;
}

Animal::~Animal(void)
{
	std::cout << "Animal destructor called" << std::endl;
}

/*   Class Functions   */

std::string Animal::getType(void) const
{
	return this->type;
}

void Animal::makeSound(void) const
{
	std::cout << this->type << "makes a sound" << std::endl;
}