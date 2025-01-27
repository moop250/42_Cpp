/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:58:01 by hlibine           #+#    #+#             */
/*   Updated: 2025/01/27 17:00:36 by hlibine          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Bureaucrat.hpp"
#include "../incl/AForm.hpp"
#include "../incl/ShrubberyCreationForm.hpp"
#include "../incl/RobotomyRequestForm.hpp"
#include <exception>

void shrubTests(void) {
	Bureaucrat	venus = Bureaucrat("Venus", 130);
	Bureaucrat	neptune = Bureaucrat("Neptune", 120);
	ShrubberyCreationForm shrubForm = ShrubberyCreationForm("park");

	std::cout << shrubForm << std::endl;
	venus.signForm(shrubForm);
	std::cout << shrubForm << std::endl;
	shrubForm.execute(venus);
	std::cout << shrubForm << std::endl;
	neptune.executeForm(shrubForm);
	std::cout << shrubForm << std::endl;
	shrubForm.execute(neptune);
}

void robotomyTests(void) {
	Bureaucrat	jupiter = Bureaucrat("Jupiter", 70);
	Bureaucrat	pluto = Bureaucrat("Pluto", 40);
	RobotomyRequestForm	robotomite = RobotomyRequestForm("Alexi");

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

/*void tooLow() {
	try {
		Bureaucrat	jerry = Bureaucrat("jerry", 100);
		AForm		pardon = AForm("pardon", 151, 100);

		pardon.beSigned(jerry);
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << "-- Too Low Exec --" << std::endl;
	try {
		Bureaucrat	james = Bureaucrat("james", 100);
		AForm		obt = AForm("obtain tree", 100, 151);

		james.signAForm(obt);
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << "-- Too Low Bureaucrat --" << std::endl;
	try {
		Bureaucrat	mars = Bureaucrat("mars", 150);
		AForm		order = AForm("Order", 100, 50);

		mars.signAForm(order);
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << "-- Too Low Bureaucrat 2 --" << std::endl;
	try {
		Bureaucrat	mars = Bureaucrat("mars", 150);
		AForm		order = AForm("Order", 100, 50);

		order.beSigned(mars);
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}
*/
int main (void) {
	std::cout << "---- Base Tests ----" << std::endl;
	shrubTests();
	std::cout << "-- Robotomy Tests --" << std::endl;
	robotomyTests();
/*	std::cout << "----- Too Low  -----" << std::endl;
	tooLow();*/
	return 0;
}
