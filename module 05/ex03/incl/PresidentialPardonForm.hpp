/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:33:36 by hlibine           #+#    #+#             */
/*   Updated: 2025/01/29 14:55:11 by hlibine          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIAL_PARDON_FORM_CLASS
# define PRESIDENTIAL_PARDON_FORM_CLASS

#include "AForm.hpp"
#include <string>
#include <iostream>

class PresidentialPardonForm : public AForm {
	private:
		std::string	target_;
		void		beExecuted_() const;

	public:
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &src);
		PresidentialPardonForm &operator=(const PresidentialPardonForm & src);
		~PresidentialPardonForm();
};

#endif
