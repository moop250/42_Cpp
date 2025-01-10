/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:44:44 by hlibine           #+#    #+#             */
/*   Updated: 2025/01/10 15:24:55 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAPCLASS_HPP
# define SCAVTRAPCLASS_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	private:
		bool isGuarding_;

	public:
	// Constructors and Destructors
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &src);
		ScavTrap& operator=(const ScavTrap&);
		~ScavTrap(void);
	// Class Functions
		void	attack(const std::string& target);
		void	guardGate(void);
};

#endif