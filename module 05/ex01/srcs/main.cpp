/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:58:01 by hlibine           #+#    #+#             */
/*   Updated: 2025/02/12 14:21:39 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Bureaucrat.hpp"
#include "../incl/Form.hpp"
#include <exception>

void baseTests(void) {
	try {
		Bureaucrat	jeff = Bureaucrat("jeff", 50);
		Form		a113 = Form("A113", 100, 50);
	
		std::cout << a113 << std::endl;
		a113.beSigned(jeff);
		std::cout << a113 << std::endl;
		jeff.signForm(a113);
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}

void tooHigh(void) {
	try {
		Bureaucrat	nep = Bureaucrat("nep", 1);
		Form		prom = Form("promote eployee", 0, 1);

		prom.beSigned(nep);
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << "\n-- Too High Exec --" << std::endl;
	try {
		Bureaucrat	ero = Bureaucrat("ero", 1);
		Form		dem = Form("demote employee", 1, 0);

		ero.signForm(dem);
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}

void tooLow() {
	try {
		Bureaucrat	jerry = Bureaucrat("jerry", 100);
		Form		pardon = Form("pardon", 151, 100);

		pardon.beSigned(jerry);
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << "\n-- Too Low Exec --" << std::endl;
	try {
		Bureaucrat	james = Bureaucrat("james", 100);
		Form		obt = Form("obtain tree", 100, 151);

		james.signForm(obt);
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << "\n-- Too Low Bureaucrat --" << std::endl;
	try {
		Bureaucrat	mars = Bureaucrat("mars", 150);
		Form		order = Form("Order", 100, 50);

		mars.signForm(order);
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << "\n-- Too Low Bureaucrat 2 --" << std::endl;
	try {
		Bureaucrat	mars = Bureaucrat("mars", 150);
		Form		order = Form("Order", 100, 50);

		order.beSigned(mars);
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}

int main (void) {
	std::cout << "---- Base Tests ----" << std::endl;
	baseTests();
	std::cout << "\n-- Too High Sign --" << std::endl;
	tooHigh();
	std::cout << "\n----- Too Low  -----" << std::endl;
	tooLow();
	return 0;
}
