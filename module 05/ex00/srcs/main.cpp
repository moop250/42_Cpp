/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:58:01 by hlibine           #+#    #+#             */
/*   Updated: 2025/01/22 15:07:55 by hlibine          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Bureaucrat.hpp"

void baseTests(void) {
	try {
		Bureaucrat jeff = Bureaucrat("jeff", 50);
		Bureaucrat nep = Bureaucrat("nep", 1);
		Bureaucrat ero = Bureaucrat("ero", 150);
		
		std::cout << jeff.getName() << " has a grade of " << jeff.getGrade() << std::endl;
		std::cout << nep.getName() << " has a grade of " << nep.getGrade() << std::endl;
		std::cout << ero.getName() << " has a grade of " << ero.getGrade() << std::endl;

		jeff.incrementGrade(10);
		std::cout << jeff.getName() << " has a grade of " << jeff.getGrade() << std::endl;
		nep.decrementGrade(10);
		std::cout << nep.getName() << " has a grade of " << nep.getGrade() << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Error: Grade to set " << e.what();
	}
}

void tooHigh(void) {
	try {
		Bureaucrat jeff = Bureaucrat("jeff", 50);
		Bureaucrat nep = Bureaucrat("nep", 0);
		Bureaucrat ero = Bureaucrat("ero", 150);
		
		std::cout << jeff.getName() << " has a grade of " << jeff.getGrade() << std::endl;
		std::cout << nep.getName() << " has a grade of " << nep.getGrade() << std::endl;
		std::cout << ero.getName() << " has a grade of " << ero.getGrade() << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Error: Grade to set " << e.what();
	}
	std::cout << "\n-- Too High increment --" << std::endl;
	try {
		Bureaucrat pluto = Bureaucrat("pluto", 3);

		std::cout << pluto.getName() << " has a grade of " << pluto.getGrade() << std::endl;
		pluto.incrementGrade(1);
		std::cout << pluto.getName() << " has a grade of " << pluto.getGrade() << std::endl;
		pluto.incrementGrade(1);
		std::cout << pluto.getName() << " has a grade of " << pluto.getGrade() << std::endl;
		pluto.incrementGrade(1);
		std::cout << pluto.getName() << " has a grade of " << pluto.getGrade() << std::endl;
	}
	catch (const std::exception& e) {
		
		std::cerr << "Error: Grade to set " << e.what();
	}
}

void tooLow() {
	try {
		Bureaucrat jeff = Bureaucrat("jeff", 50);
		Bureaucrat nep = Bureaucrat("nep", 1);
		Bureaucrat ero = Bureaucrat("ero", 151);
		
		std::cout << jeff.getName() << " has a grade of " << jeff.getGrade() << std::endl;
		std::cout << nep.getName() << " has a grade of " << nep.getGrade() << std::endl;
		std::cout << ero.getName() << " has a grade of " << ero.getGrade() << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Error: Grade to set " << e.what();
	}
	std::cout << "\n-- Too Low decrement --" << std::endl;
	try {
		Bureaucrat mars = Bureaucrat("pluto", 148);

		std::cout <<  mars.getName() << " has a grade of " << mars.getGrade() << std::endl;
		mars.decrementGrade(1);
		std::cout <<  mars.getName() << " has a grade of " << mars.getGrade() << std::endl;
		mars.decrementGrade(1);
		std::cout <<  mars.getName() << " has a grade of " << mars.getGrade() << std::endl;
		mars.decrementGrade(1);
		std::cout <<  mars.getName() << " has a grade of " << mars.getGrade() << std::endl;
	}
	catch (const std::exception& e) {
		
		std::cerr << "Error: Grade to set " << e.what();
	}
}

int main (void) {
	std::cout << "---- Base Tests ----" << std::endl;
	baseTests();
	std::cout << "----- Too High -----" << std::endl;
	tooHigh();
	std::cout << "----- Too Low  -----" << std::endl;
	tooLow();
	return 0;
}
