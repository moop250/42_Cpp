/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 16:04:54 by hlibine           #+#    #+#             */
/*   Updated: 2024/12/23 14:42:12 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_CLASS_H
# define HARL_CLASS_H

#include <string>
#include <iostream>

class Harl {
	private:
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);

	public:
		Harl(void);
		~Harl(void);

	void	complain(std::string level);
};

enum {
	DEBUG,
	INFO,
	WARNING,
	ERROR
};

#endif