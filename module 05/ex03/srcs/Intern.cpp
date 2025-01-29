/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:39:08 by hlibine           #+#    #+#             */
/*   Updated: 2025/01/29 14:45:03 by hlibine          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &src) {
	(void)src;
}

Intern &Intern::operator=(const Intern &src) {
	(void)src;
	return *this;
}

Intern::~Intern() {};


/*  Member Functions  */

AForm *Intern::mkPresForm_(const std::string &target) const {return (new PresidentialPardonForm(target));}

AForm *Intern::mkRobotForm_(const std::string &target) const {return (new RobotomyRequestForm(target));}

AForm *Intern::mkShrubForm_(const std::string &target) const {return (new ShrubberyCreationForm(target));}

AForm *Intern::makeForm(const std::string form, const std::string target) {
	const iFunc	 funcs[NUMFORMS] = {&Intern::mkPresForm_, &Intern::mkRobotForm_, &Intern::mkShrubForm_};
	const std::string forms[NUMFORMS] = {"presidential pardon", "robotomy request", "shrubbery creation"};

	for (int i = 0; i < NUMFORMS; i++ ) {
		if (!forms[i].compare(form)) {
			std::cout << "Intern creates: \"" << form << "\"" << std::endl;
			return (this->*funcs[i])(target);
		}
	}
	std::cout << "Intern reports: \"" << form << "\" couldn't be found" << std::endl;
	return NULL;
}
