/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 16:36:41 by hlibine           #+#    #+#             */
/*   Updated: 2024/12/19 16:00:26 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_CLASS_HPP
# define WRONGCAT_CLASS_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	private:

	public:
	// Constructors and Destructors
		WrongCat(void);
		WrongCat(const WrongCat &src);
		WrongCat& operator=(const WrongCat&);
		~WrongCat(void);
	// Class Functions
		void	makeSound(void) const;
};

#endif