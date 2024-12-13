/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:50:32 by hlibine           #+#    #+#             */
/*   Updated: 2024/12/13 15:51:47 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOGCLASS_HPP
# define DOGCLASS_HPP

#include "Animal.hpp"

class Dog : public Animal
{
	private:

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