/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:17:04 by hlibine           #+#    #+#             */
/*   Updated: 2024/12/13 15:39:09 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CATCLASS_HPP
# define CATCLASS_HPP

#include "Animal.hpp"

class Cat : public Animal
{
	private:

	public:
	// Constructors and Destructors
		Cat(void);
		Cat(const Cat &src);
		Cat& operator=(const Cat&);
		~Cat(void);
	// Class Functions
		void	makeSound(void) const;
};

#endif