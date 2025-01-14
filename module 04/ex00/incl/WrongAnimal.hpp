/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 16:36:44 by hlibine           #+#    #+#             */
/*   Updated: 2025/01/14 14:46:44 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_CLASS_HPP
# define WRONGANIMAL_CLASS_HPP

#include <iostream>

class WrongAnimal
{
	protected:
		std::string type_;

	public:
	// Constructors and Destructors
		WrongAnimal();
		WrongAnimal(std::string type);
		WrongAnimal &operator=(const WrongAnimal &src);
		virtual ~WrongAnimal(void);
	// Class Functions
		std::string getType(void) const;
		void makeSound(void) const;
};

#endif