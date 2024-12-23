/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:27:20 by hlibine           #+#    #+#             */
/*   Updated: 2024/12/19 16:40:40 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Brain.hpp"


Brain::Brain()
{
	std::cout << "Brain Default constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas_[i] = "Empty";
}

Brain::Brain(const Brain &src)
{
	std::cout << "Barin Copy Constructor called" << std::endl;
	for(int i = 0; i < 100; i++)
		this->ideas_[i] = src.ideas_[i];
}

Brain& Brain::operator=(const Brain &src)
{
	std::cout << "Brain Assignation constructor called" << std::endl;
	if (this != &src)
	{
		for (int i = 0; i < 100; i++)
			this->ideas_[i] = src.ideas_[i];
	}
	return *this;
}

Brain::~Brain(void)
{
	std::cout << "Brain destructor called" << std::endl;
}

std::string Brain::getIdea(int index) const
{
	if (index < 0 || index >= 100)
		return "Index out of range";
	return this->ideas_[index];
}