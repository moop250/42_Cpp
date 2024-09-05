/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 13:38:34 by hlibine           #+#    #+#             */
/*   Updated: 2024/09/05 23:17:59 by hlibine          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

#include <iostream>
#include <iomanip>
#include <string>

class	Contact {

private:
	
	std::string	_firstName;
	std::string	_lastName;
	std::string	_nickname;
	std::string	_phoneNumber;
	std::string	_darkestSecret;
	int			_index;

	std::string	_getInput(std::string str) const;
	std::string	_truncator(std::string str) const;

public:

	Contact( void );
	~Contact( void );

	void	init(void);
	void	setIndex(int i);
	void	show(void);
	void	displayContact(int i) const;
	bool	vaild;
};

#endif // !CONTACT_H
