/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:29:21 by hlibine           #+#    #+#             */
/*   Updated: 2024/12/13 16:29:37 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Cat.hpp"

/*  Contstructors and Destructors  */

Cat::Cat()
{
	this->type_ = "Cat";
	std::cout << "Cat Default constructor called" << std::endl;
}

Cat::Cat(const Cat &src) : Animal(src)
{
	std::cout << "Cat Copy constructor called" << std::endl;
	this->type_ = src.type_;
}

Cat& Cat::operator=(const Cat& src)
{
	std::cout << "Cat Assignation constructor called" << std::endl;
	if (this != &src)
		this->type_ = src.type_;
	return *this;
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
}

/*  Class Functions  */

void Cat::makeSound(void) const
{
	std::cout << "Meow Meow" << std::endl;
}