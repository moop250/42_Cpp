/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:01:02 by hlibine           #+#    #+#             */
/*   Updated: 2024/11/20 15:07:57 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Constructors and destructor

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
//	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value) : value_(roundf(value * (1 << this->fractionalBits_)))
{
//	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed()
{
//	std::cout << "Destructor called" << std::endl;
}

// Getters and setters

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

// Operator overloads

Fixed Fixed::operator+(const Fixed &src) const
{
	return Fixed(this->toFloat() + src.toFloat());
}

Fixed Fixed::operator-(const Fixed &src) const
{
	return Fixed(this->toFloat() - src.toFloat());
}

Fixed Fixed::operator*(const Fixed &src) const
{
	return Fixed(this->toFloat() * src.toFloat());
}

Fixed Fixed::operator/(const Fixed &src) const
{
	return Fixed(this->toFloat() / src.toFloat());
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	this->value_++;
	return tmp;
}

Fixed Fixed::operator++(void)
{
	++this->value_;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	this->value_--;
	return tmp;
}

Fixed Fixed::operator--(void)
{
	--this->value_;
	return (*this);
}

bool Fixed::operator>(const Fixed &src) const
{
	return (this->value_ > src.value_);
}

bool Fixed::operator<(const Fixed &src) const
{
	return (this->value_ < src.value_);
}

bool Fixed::operator>=(const Fixed &src) const
{
	return (this->value_ >= src.value_);
}

bool Fixed::operator<=(const Fixed &src) const
{
	return (this->value_ <= src.value_);
}

bool Fixed::operator==(const Fixed &src) const
{
	return (this->value_ == src.value_);
}

bool Fixed::operator!=(const Fixed &src) const
{
	return (this->value_ == src.value_);
}

// Static Class mehods

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return a;
	return b;
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return a;
	return b;
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return a;
	return b;
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return a;
	return b;
}

//Fixing print issue

std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
	os << obj.toFloat();
	return os;
}