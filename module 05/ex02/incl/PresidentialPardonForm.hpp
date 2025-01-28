/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:33:36 by hlibine           #+#    #+#             */
/*   Updated: 2025/01/28 13:43:14 by hlibine          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIAL_PARDON_FORM_CLASS
# define PRESIDENTIAL_PARDON_FORM_CLASS

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	private:
		std::string	target_;
		void		beExecuted_() const;

	public:
		PresidentialPardonForm(std::string target);
		~PresidentialPardonForm();
};

#endif
