/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 16:36:49 by hlibine           #+#    #+#             */
/*   Updated: 2025/01/13 17:56:35 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/WrongCat.hpp"

/*  Contstructors and Destructors  */

WrongCat::WrongCat()
{
	this->type_ = "WrongCat";
	std::cout << "Cat Default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &src) : WrongAnimal(src)
{
	std::cout << "WrongCat Copy constructor called" << std::endl;
	this->type_ = src.type_;
}

WrongCat& WrongCat::operator=(const WrongCat& src)
{
	std::cout << "WrongCat Assignation constructor called" << std::endl;
	if (this != &src)
		this->type_ = src.type_;
	return *this;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat destructor called" << std::endl;
}

/*  Class Functions  */

void WrongCat::makeSound(void) const
{
	std::cout << "Mechanical Clunking" << std::endl;
}