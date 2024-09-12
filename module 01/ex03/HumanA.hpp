/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:12:08 by hlibine           #+#    #+#             */
/*   Updated: 2024/09/12 21:38:17 by hlibine          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_CLASS_H
# define HUMANA_CLASS_H

#include "Weapon.hpp"
#include <string>

class HumanA {
private:
	std::string	name_;
	Weapon&		weapon_;

public:
	HumanA(std::string name, Weapon& weapon);
	~HumanA(void);

	void attack(void);
};

#endif // !DEBUG
