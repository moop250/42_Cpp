/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:17:04 by hlibine           #+#    #+#             */
/*   Updated: 2025/01/14 16:07:30 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_CLASS_HPP
# define CAT_CLASS_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain *brain_;

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