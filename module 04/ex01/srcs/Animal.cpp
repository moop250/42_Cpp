/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:11:29 by hlibine           #+#    #+#             */
/*   Updated: 2024/12/19 16:02:33 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Animal.hpp"


/*   Constructors and Destructors   */

Animal::Animal()
{
	this->type_ = "Boring Animal";
	std::cout << "Default Animal constructor called" << std::endl;
}

Animal::Animal(const Animal &src)
{
	this->type_ = src.type_;
	std::cout << "Animal Copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& src)
{
	std::cout << "Animal Assignation constructor called" << std::endl;
	if (this != &src)
		this->type_ = src.type_;
	return *this;
}

Animal::~Animal(void)
{
	std::cout << "Animal destructor called" << std::endl;
}

/*   Class Functions   */

std::string Animal::getType(void) const
{
	return this->type_;
}

void Animal::makeSound(void) const
{
	std::cout << this->type_ << " makes a sound " << std::endl;
}