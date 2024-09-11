/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 13:38:34 by hlibine           #+#    #+#             */
/*   Updated: 2024/09/11 15:13:11 by hlibine          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

#include <iostream>
#include <iomanip>
#include <string>

class	Contact {

private:
	
	std::string	firstName_;
	std::string	lastName_;
	std::string	nickname_;
	std::string	phoneNumber_;
	std::string	darkestSecret_;
	int			index_;
	bool		vaild_;

	std::string	getInput_(std::string str) const;
	std::string	truncator_(std::string str) const;

public:

	Contact( void );
	~Contact( void );

	void	init(void);
	void	setIndex(int i);
	void	show(void);
	void	displayContact(int i) const;
	bool	getvaild(void) const;
};

#endif // !CONTACT_H
