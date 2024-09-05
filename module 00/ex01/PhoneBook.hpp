/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 13:31:46 by hlibine           #+#    #+#             */
/*   Updated: 2024/09/05 23:26:02 by hlibine          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include <iostream>
#include <cstdlib>
#include "Contact.hpp"

class	PhoneBook {

private:
	Contact		_contacts[8];

	std::string _getNum(std::string str) const;
	bool		_isNumber(std::string str) const;

public:

	PhoneBook(void);
	~PhoneBook(void);

	void	welcome(void);
	void	addContact(void);
	void	search(void);
};

#endif // !PHONEBOOK_H
