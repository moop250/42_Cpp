/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 13:31:46 by hlibine           #+#    #+#             */
/*   Updated: 2024/09/05 20:53:24 by hlibine          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include <iostream>
#include "Contact.hpp"

class	PhoneBook {

private:
	Contact _contacts[8];

public:

	PhoneBook(void);
	~PhoneBook(void);

	void	welcome(void);
	void	addContact(void);
	void	search(void);
};

#endif // !PHONEBOOK_H
