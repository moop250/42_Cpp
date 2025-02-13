/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:01:02 by hlibine           #+#    #+#             */
/*   Updated: 2025/01/07 13:40:47 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : value_(0)
{
//	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src)
{
//	std::cout << "Copy constructor called" << std::endl;
	this->setRawBits(src.getRawBits());
}

Fixed& Fixed::operator=( const Fixed &src)
{
//	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		this->setRawBits(src.getRawBits());
	return *this;
}

Fixed::Fixed(const int value) : value_(value << this->fractionalBits_)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value) : value_(roundf(value * (1 << this->fractionalBits_)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed()
{
//	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	return this->value_;
}

void Fixed::setRawBits(int const raw)
{
	this->value_ = raw;
}

int Fixed::toInt(void) const
{
	return this->value_ >> this->fractionalBits_;
}

float Fixed::toFloat(void) const
{
	return (float)this->value_ / (1 << this->fractionalBits_);
}

//Fixing print issue

std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
	os << obj.toFloat();
	return os;
}