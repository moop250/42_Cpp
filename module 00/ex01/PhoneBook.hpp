/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 13:31:46 by hlibine           #+#    #+#             */
/*   Updated: 2024/09/04 17:46:52 by hlibine          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include <iostream>
#include "Contact.hpp"

class	PhoneBook {

private:
	Contact contacts[8];

public:

	PhoneBook(void);
	~PhoneBook(void);

	void	welcome(void);
};

#endif // !PHONEBOOK_H
