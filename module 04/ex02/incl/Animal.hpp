/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:11:30 by hlibine           #+#    #+#             */
/*   Updated: 2025/01/14 16:07:27 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_CLASS_HPP
# define ANIMAL_CLASS_HPP

#include <iostream>

class Animal
{
	protected:
		std::string type_;

	public:
	// Constructors and Destructors
		Animal();
		Animal(const Animal &src);
		Animal &operator=(const Animal &src);
		virtual ~Animal(void);
	// Class Functions
		std::string getType(void) const;
		virtual void makeSound(void) const = 0;
};

#endif