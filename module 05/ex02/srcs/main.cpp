/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:58:01 by hlibine           #+#    #+#             */
/*   Updated: 2025/01/24 16:15:50 by hlibine          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Bureaucrat.hpp"
#include "../incl/AForm.hpp"
#include "../incl/ShrubberyCreationForm.hpp"
#include <exception>

void shrubTests(void) {
	Bureaucrat	venus = Bureaucrat("Venus", 130);
	Bureaucrat	neptune = Bureaucrat("Neptune", 120);
	ShrubberyCreationForm shrubForm = ShrubberyCreationForm("park");

	std::cout << shrubForm << std::endl;
	venus.signForm(shrubForm);
	shrubForm.execute(venus);
	std::cout << shrubForm << std::endl;
	neptune.executeForm(shrubForm);
	std::cout << shrubForm << std::endl;
}

void tooHigh(void) {
	try {
		Bureaucrat	nep = Bureaucrat("nep", 1);
		AForm		prom = AForm("promote eployee", 0, 1);

		prom.beSigned(nep);
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << "-- Too High Exec --" << std::endl;
	try {
		Bureaucrat	ero = Bureaucrat("ero", 1);
		AForm		dem = AForm("demote employee", 1, 0);

		ero.signAForm(dem);
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}

void tooLow() {
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

int main (void) {
	std::cout << "---- Base Tests ----" << std::endl;
	baseTests();
	std::cout << "-- Too High Sign --" << std::endl;
	tooHigh();
	std::cout << "----- Too Low  -----" << std::endl;
	tooLow();
	return 0;
}
