/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:42:12 by hlibine           #+#    #+#             */
/*   Updated: 2024/12/18 14:02:13 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_CLASS_H
# define ZOMBIE_CLASS_H

#include <iostream>
#include <string>

class Zombie {
private:
	std::string	name_;
	size_t		id_;

public:
	Zombie(void);
	~Zombie(void);
	
	void	setInfo(std::string &str, size_t id);
	void	announce(void);
};

#endif // !ZOMBIE_CLASS_H
