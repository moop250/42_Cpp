/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:12:11 by hlibine           #+#    #+#             */
/*   Updated: 2024/09/12 21:25:58 by hlibine          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_CLASS_H
# define WEAPON_CLASS_H

#include <string>
class Weapon {
private:
	std::string	type_;

public:
	Weapon(std::string type);
	~Weapon(void);

	const std::string	&getType(void) const;
	void		setType(std::string weapon);
};

#endif // !WEAPON_CLASS_H