/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:42:12 by hlibine           #+#    #+#             */
/*   Updated: 2024/09/11 19:27:59 by hlibine          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_CLASS_H
# define ZOMBIE_CLASS_H

#include <iostream>
#include <string>

class Zombie {
private:
	std::string	name_;

public:
	Zombie(std::string str);
	~Zombie(void);

	void	announce(void);
};

#endif // !ZOMBIE_CLASS_H