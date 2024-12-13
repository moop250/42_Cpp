/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:52:00 by hlibine           #+#    #+#             */
/*   Updated: 2024/12/13 16:29:56 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Dog.hpp"

/*  Contstructors and Destructors  */

Dog::Dog()
{
	this->type_ = "Dog";
	std::cout << "Dog Default constructor called" << std::endl;
}

Dog::Dog(const Dog &src) : Animal(src)
{
	std::cout << "Dog Copy constructor called" << std::endl;
	this->type_ = src.type_;
}

Dog& Dog::operator=(const Dog& src)
{
	std::cout << "Dog Assignation constructor called" << std::endl;
	if (this != &src)
		this->type_ = src.type_;
	return *this;
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called" << std::endl;
}

/*  Class Functions  */

void Dog::makeSound(void) const
{
	std::cout << "Le Bark" << std::endl;
}