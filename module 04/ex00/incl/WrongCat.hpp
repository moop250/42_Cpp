/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 16:36:41 by hlibine           #+#    #+#             */
/*   Updated: 2024/12/13 16:46:57 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCATCLASS_HPP
# define WRONGCATCLASS_HPP

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