/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:58:01 by hlibine           #+#    #+#             */
/*   Updated: 2025/01/30 15:13:28 by hlibine          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Bureaucrat.hpp"
#include "../incl/AForm.hpp"
#include "../incl/ShrubberyCreationForm.hpp"
#include "../incl/RobotomyRequestForm.hpp"
#include "../incl/PresidentialPardonForm.hpp"
#include <exception>

void shrubTests(void) {
	Bureaucrat	venus = Bureaucrat("Venus", 130);
	Bureaucrat	neptune = Bureaucrat("Neptune", 120);
	ShrubberyCreationForm shrubForm = ShrubberyCreationForm("home");

	try {
		std::cout << shrubForm << std::endl;
		venus.signForm(shrubForm);
		std::cout << shrubForm << std::endl;
		shrubForm.execute(venus);
		std::cout << shrubForm << std::endl;
		neptune.executeForm(shrubForm);
		std::cout << shrubForm << std::endl;
		shrubForm.execute(neptune);
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}

void robotomyTests(void) {
	Bureaucrat	jupiter = Bureaucrat("Jupiter", 70);
	Bureaucrat	pluto = Bureaucrat("Pluto", 40);
	RobotomyRequestForm	robotomite = RobotomyRequestForm("Alexi");
	
	try {
		std::cout << robotomite << std::endl;
		jupiter.executeForm(robotomite);
		std::cout << robotomite << std::endl;
		pluto.executeForm(robotomite);
		std::cout << robotomite << std::endl;
		robotomite.beSigned(jupiter);
		std::cout << robotomite << std::endl;
		robotomite.execute(pluto);
		std::cout << robotomite << std::endl;
	}
		catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << "\n--- Robotomy Tests No Fail ---";
	try {
		std::cout << robotomite << std::endl;
		robotomite.beSigned(jupiter);
		std::cout << robotomite << std::endl;
		robotomite.execute(pluto);
		std::cout << robotomite << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}

void presidentialShit() {
	Bureaucrat				presi = Bureaucrat("Zaphod Beeblebrox", 1);
	Bureaucrat				clerk = Bureaucrat("Le Vice Prsidente", 20);
	PresidentialPardonForm	ppf = PresidentialPardonForm("Big Boss");
	
	try {
	std::cout << ppf << std::endl;
	clerk.signForm(ppf);
	std::cout << ppf << std::endl;
	ppf.execute(presi);
	std::cout << ppf << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}

int main (void) {
	std::cout << "---- Base Tests ----" << std::endl;
	shrubTests();
	std::cout << "\n-- Robotomy Tests --" << std::endl;
	robotomyTests();
	std::cout << "\n-- Pardoning Time  --" << std::endl;
	presidentialShit();
	return 0;
}
