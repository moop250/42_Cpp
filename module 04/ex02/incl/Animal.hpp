/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:11:30 by hlibine           #+#    #+#             */
/*   Updated: 2024/12/21 15:32:24 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_CLASS_HPP
# define ANIMAL_CLASS_HPP

#include <iostream>

class abAnimal
{
	protected:
		std::string type_;

	public:
	// Constructors and Destructors
		abAnimal();
		abAnimal(const abAnimal &src);
		abAnimal &operator=(const abAnimal &src);
		virtual ~abAnimal(void);
	// Class Functions
		std::string getType(void) const;
		virtual void makeSound(void) const = 0;
};

#endif