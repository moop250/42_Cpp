/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:41:31 by hlibine           #+#    #+#             */
/*   Updated: 2024/11/26 12:52:24 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAPCLASS_HPP
# define CLAPTRAPCLASS_HPP

# include <string>
# include <iostream>

# define uint unsigned int

class ClapTrap
{
	protected:
		std::string	name_;
		uint		hp_;
		uint		energyPoints_;
		uint		attackDamage_;

	public:
	// Constructors and Destructors
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &src);
		ClapTrap& operator=(const ClapTrap&);
		~ClapTrap(void);
	// Class Functions
		void	attack(const std::string& target);
		void	takeDamage(uint amount);
		void	beRepaired(uint amount);
};

#endif