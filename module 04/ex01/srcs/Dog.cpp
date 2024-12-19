/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:52:00 by hlibine           #+#    #+#             */
/*   Updated: 2024/12/19 16:54:16 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Dog.hpp"

/*  Contstructors and Destructors  */

Dog::Dog()
{
	this->type_ = "Dog";
	this->brain_ = new Brain;
	std::cout << "Dog Default constructor called" << std::endl;
}

Dog::Dog(const Dog &src) : Animal(src)
{
	std::cout << "Dog Copy constructor called" << std::endl;
	this->type_ = src.type_;
	this->brain_ = new Brain(*src.brain_);
}

Dog& Dog::operator=(const Dog& src)
{
	std::cout << "Dog Assignation constructor called" << std::endl;
	if (this != &src) {
		this->type_ = src.type_;
		delete this->brain_;
		this->brain_ = new Brain(*src.brain_);
	}
	return *this;
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called" << std::endl;
	delete this->brain_;
}

/*  Class Functions  */

void Dog::makeSound(void) const
{
	std::cout << "Le Bark" << std::endl;
}

void Dog::printIdeas(void) const
{
	std::cout << this->type_ << "'s ideas:" << std::endl;
	for (int i = 0; i < 100; i++)
		std::cout << this->brain_->getIdea(i) << std::endl;
}
