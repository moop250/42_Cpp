/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fragtrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:00:41 by hlibine           #+#    #+#             */
/*   Updated: 2024/11/26 15:18:09 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAPCLASS_HPP
# define FRAGTRAPCLASS_HPP

#include "ScavTrap.hpp"

class FragTrap : public ClapTrap
{
	private:

	public:
	// Constructors and Destructors
		FragTrap(const std::string name);
		FragTrap(const FragTrap &src);
		FragTrap& operator=(const FragTrap&);
		~FragTrap(void);
	// Class Functions
		void highFiveGuys(void);
};

#endif