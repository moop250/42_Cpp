/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:50:32 by hlibine           #+#    #+#             */
/*   Updated: 2025/01/14 16:07:45 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_CLASS_HPP
# define DOG_CLASS_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain *brain_;

	public:
	// Constructors and Destructors
		Dog(void);
		Dog(const Dog &src);
		Dog& operator=(const Dog&);
		~Dog(void);
	// Class Functions
		void	makeSound(void) const;
};

#endif