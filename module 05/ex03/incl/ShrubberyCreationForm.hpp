/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:55:28 by hlibine           #+#    #+#             */
/*   Updated: 2025/01/28 16:13:33 by hlibine          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_CREATION_FORM_CLASS
# define SHRUBBERY_CREATION_FORM_CLASS

#include "AForm.hpp"
#include <iostream>
#include <string>
#include <fstream>

class ShrubberyCreationForm : public AForm {
	private:
		std::string	target_;
		void		beExecuted_() const;

	public:
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &src);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &src);
		~ShrubberyCreationForm();
};

#endif // !SHRUBBERY_CREATION_FORM_CLASS
