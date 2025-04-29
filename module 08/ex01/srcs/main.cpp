/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:08:06 by hlibine           #+#    #+#             */
/*   Updated: 2025/04/29 14:26:58 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Span.hpp"
#include "../utils/colors.h"
#include <ctime>

int	main(void) {

	srand(time(NULL));

	std::cout << C_GREEN << "---- Base Test ----" << C_RESET << std::endl;
	try {
		Span	sp(3);
	
		sp.addNumber(12);
		sp.addNumber(30);
		sp.addNumber(500);

		std::cout << C_YELLOW << "Longest Span: " << C_RESET << sp.longestSpan() << std::endl;
		std::cout << C_YELLOW << "Shortest Span: " << C_RESET << sp.shortestSpan() << std::endl;

	}
	catch (const std::exception& e) {
		std::cerr << C_RED << e.what() << C_RESET;
	}
	std::cout << C_GREEN << "\n---- Copy Constructor Test ----" << C_RESET << std::endl;
	try {
		Span	sp(3);
	
		sp.addNumber(12);
		sp.addNumber(30);

		Span	s2 = sp;

		s2.addNumber(500);

		std::cout << C_YELLOW << "Sp Longest Span: " << C_RESET << sp.longestSpan() << std::endl;
		std::cout << C_YELLOW << "Sp Shortest Span: " << C_RESET << sp.shortestSpan() << std::endl;
		std::cout << std::endl;
		std::cout << C_YELLOW << "S2 Longest Span: " << C_RESET << s2.longestSpan() << std::endl;
		std::cout << C_YELLOW << "S2 Shortest Span: " << C_RESET << s2.shortestSpan() << std::endl;

	}
	catch (const std::exception& e) {
		std::cerr << C_RED << e.what() << C_RESET;
	}
	std::cout << C_GREEN << "\n---- Overflow Test ----" << C_RESET << std::endl;
	try {
		Span	sp(2);
	
		sp.addNumber(42);
		sp.addNumber(84);
		sp.addNumber(900);

		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;

	}
	catch (const std::exception& e) {
		std::cerr << C_RED << e.what() << C_RESET;
	}
	std::cout << C_GREEN << "\n---- Too Small Test ----" << C_RESET << std::endl;
	try {
		Span	sp(1);
	
		sp.addNumber(42);
		sp.addNumber(84);

		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << C_RED << e.what() << C_RESET;
	}
	std::cout << C_GREEN << "\n---- Mass Test ----" << C_RESET << std::endl;
	try {
		Span	sp(10000);
	
		sp.fillList(10000, 100000000);
		std::cout << C_YELLOW << "Longest Span: " << C_RESET << sp.longestSpan() << std::endl;
		std::cout << C_YELLOW << "Shortest Span: " << C_RESET << sp.shortestSpan() << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << C_RED << e.what() << C_RESET;
	}
	std::cout << std::endl;
}
