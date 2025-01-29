/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:39:06 by hlibine           #+#    #+#             */
/*   Updated: 2025/01/29 14:07:13 by hlibine          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_CLASS
# define INTERN_CLASS

#include "AForm.hpp"
#include "../incl/PresidentialPardonForm.hpp"
#include "../incl/RobotomyRequestForm.hpp"
#include "../incl/ShrubberyCreationForm.hpp"
#include <string>
#include <iostream>

# define NUMFORMS 3

class Intern {
	private:
		AForm	*mkPresForm_(const std::string &target) const;
		AForm	*mkRobotForm_(const std::string &target) const;
		AForm	*mkShrubForm_(const std::string &target) const;

	public:
	/* Construstors and Destructors */
		Intern();
		Intern(const Intern &src);
		Intern &operator=(const Intern &src);
		~Intern();

	/*  Member Function  */
		AForm*	makeForm(const std::string form, const std::string target);

	/*  Typedef  */
		typedef AForm *(Intern::*iFunc)(const std::string &target) const;
};

#endif // !INTERN_CLASS
