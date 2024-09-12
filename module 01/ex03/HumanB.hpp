/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:12:10 by hlibine           #+#    #+#             */
/*   Updated: 2024/09/12 21:46:06 by hlibine          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_CLASS_H
# define HUMANB_CLASS_H

#include "Weapon.hpp"
#include <iostream>

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
