/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:12:10 by hlibine           #+#    #+#             */
/*   Updated: 2024/12/23 14:22:09 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_CLASS_H
# define HUMANB_CLASS_H

#include "Weapon.hpp"
#include <iostream>
#include <string>

class HumanB {
private:
	std::string	name_;
	Weapon*		weapon_;

public:
	HumanB(std::string name);
	~HumanB(void);

	void setWeapon(Weapon& weapon);
	void attack(void);
};

#endif // !HUMANB_CLASS_H
