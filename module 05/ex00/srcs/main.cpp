/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:58:01 by hlibine           #+#    #+#             */
/*   Updated: 2025/01/22 14:41:35 by hlibine          ###   LAUSANNE.ch       */
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
	}
	catch (const std::exception& e) {
		std::cerr << "Error: Grade to set " << e.what() << std::endl;
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
		std::cerr << "Error: Grade to set " << e.what() << std::endl;
	}
	std::cout <<
	try
}

void tooLow

int main (void) {
	std::cout << "---- Base Tests ----" << std::endl;
	baseTests();
	std::cout << "----- Too High -----" << std::endl;
	tooHigh();
	std::cout << "----- Too Low  -----" << std::endl;
	return 0;
}
