/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:57:52 by hlibine           #+#    #+#             */
/*   Updated: 2024/12/13 16:57:02 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	this->type_ = "Unspeakable Horror";
	std::cout << "WrongAnimal Default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type)
{
	this->type_ = type;
	std::cout << "WrongAnimal With Type constructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& src)
{
	std::cout << "WrongAnimal Assignation constructor called" << std::endl;
	if (this != &src)
		this->type_ = src.type_;
	return *this;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

/*   Class Functions   */

std::string WrongAnimal::getType(void) const
{
	return this->type_;
}

void WrongAnimal::makeSound(void) const
{
	std::cout << this->type_ << " Bubbles and Groans" << std::endl;
}