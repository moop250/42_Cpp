/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:58:01 by hlibine           #+#    #+#             */
/*   Updated: 2025/01/29 14:58:08 by hlibine          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Bureaucrat.hpp"
#include "../incl/AForm.hpp"
#include "../incl/ShrubberyCreationForm.hpp"
#include "../incl/RobotomyRequestForm.hpp"
#include "../incl/PresidentialPardonForm.hpp"
#include "../incl/Intern.hpp"
#include <cstdlib>
#include <exception>

void internTests(void) {
	Bureaucrat	venus = Bureaucrat("Venus", 5);
	Intern		dispo = Intern();
	AForm		*rrf;
	AForm		*pp;
	AForm		*sc;
	
	try {
		rrf	= dispo.makeForm("robotomy request", "james");
		pp	= dispo.makeForm("presidential pardon", "large commander");
		sc	= dispo.makeForm("shrubbery creation", "mother base");
	} catch (std::bad_alloc&) {
		std::cerr << "memory allocation failure" << std::endl;
		exit(1) ;
	}
	
	std::cout << std::endl;
	venus.signForm(*rrf);
	venus.executeForm(*rrf);
	std::cout << *rrf << std::endl;
	pp->beSigned(venus);
	pp->execute(venus);
	std::cout << *pp << std::endl;
	venus.signForm(*sc);
	venus.executeForm(*sc);
	std::cout << *sc << std::endl;
	
	delete rrf;
	delete pp;
	delete sc;

	AForm	*lunch = dispo.makeForm("lunch order", "samich");
	if (lunch != NULL)
		delete lunch;
}

int main (void) {
	std::cout << "---- Base Tests ----" << std::endl;
	internTests();
	return 0;
}
