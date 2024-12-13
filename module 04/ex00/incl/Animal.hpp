/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:11:30 by hlibine           #+#    #+#             */
/*   Updated: 2024/12/13 15:42:16 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMALCLASS_HPP
# define ANIMALCLASS_HPP

#include <iostream>

class Animal
{
	protected:
		std::string type_;

	public:
	// Constructors and Destructors
		Animal();
		Animal(std::string type);
		Animal &operator=(const Animal &src);
		virtual ~Animal(void);
	// Class Functions
		std::string getType(void) const;
		virtual void makeSound(void) const;
};

#endif // ANIMAL_HPP //