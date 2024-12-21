/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:29:21 by hlibine           #+#    #+#             */
/*   Updated: 2024/12/21 16:15:19 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Cat.hpp"

/*  Contstructors and Destructors  */

Cat::Cat()
{
	this->type_ = "Cat";
	this->brain_ = new Brain();
	std::cout << "Cat Default constructor called" << std::endl;
}

Cat::Cat(const Cat &src) : abAnimal(src)
{
	std::cout << "Cat Copy constructor called" << std::endl;
	this->type_ = src.type_;
	this->brain_ = new Brain(*src.brain_);
}

Cat& Cat::operator=(const Cat& src)
{
	std::cout << "Cat Assignation constructor called" << std::endl;
	if (this != &src) {
		this->type_ = src.type_;
		delete this->brain_;
		this->brain_ = new Brain(*src.brain_);
	}
	return *this;
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
	delete this->brain_;
}

/*  Class Functions  */

void Cat::makeSound(void) const
{
	std::cout << "Meow Meow" << std::endl;
}

void Cat::printIdeas(void) const
{
	std::cout << this->type_ << "'s ideas:" << std::endl;
	for (int i = 0; i < 100; i++)
		std::cout << this->brain_->getIdea(i) << std::endl;
}