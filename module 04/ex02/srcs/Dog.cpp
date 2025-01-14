/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:52:00 by hlibine           #+#    #+#             */
/*   Updated: 2025/01/14 15:50:12 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Dog.hpp"

/*  Contstructors and Destructors  */

Dog::Dog(void)
{
	std::cout << "Dog Default constructor called" << std::endl;
	this->type_ = "Dog";
		try {
		this->brain_ = new Brain();
	}
	catch (std::bad_alloc &e) {
		std::cerr << "Memory Allocation for brain failed : " << e.what() << std::endl;
	}
}

Dog::Dog(const Dog &src) : abAnimal(src)
{
	std::cout << "Dog Copy constructor called" << std::endl;
	this->type_ = src.type_;
	try {
		this->brain_ = new Brain(*src.brain_);
	}
	catch (std::bad_alloc &e) {
		std::cerr << "Memory Allocation for brain failed : " << e.what() << std::endl;
	}
}

Dog& Dog::operator=(const Dog& src)
{
	std::cout << "Dog Assignation constructor called" << std::endl;
	if (this != &src) {
		this->type_ = src.type_;
		delete this->brain_;
		try {
			this->brain_ = new Brain(*src.brain_);
		}
		catch (std::bad_alloc &e) {
			std::cerr << "Memory Allocation for brain failed : " << e.what() << std::endl;
		}
	}
	return *this;
}

Dog::~Dog(void)
{
	delete this->brain_;
	std::cout << "Dog destructor called" << std::endl;
}

/*  Class Functions  */

void Dog::makeSound(void) const
{
	std::cout << "Le Bark" << std::endl;
}
