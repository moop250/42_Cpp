/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 13:38:34 by hlibine           #+#    #+#             */
/*   Updated: 2024/09/04 14:41:09 by hlibine          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

#include <iostream>

class	Contact {

private:
	
	std::string	firstName;
	std::string	lastName;
	std::string	nickName;
	std::string	phoneNumber;
	std::string	darkestSecret;
	std::string	index;

public:

	Contact( void );
	~Contact( void );
};

#endif // !CONTACT_H
