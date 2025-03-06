/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:08:06 by hlibine           #+#    #+#             */
/*   Updated: 2025/03/05 19:25:36 by hlibine          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Span.hpp"

int	main(void) {

	std::cout << "---- Base Test ----" << std::endl;
	try {
		Span	sp(3);
	
		sp.addNumber(12);
		sp.addNumber(30);
		sp.addNumber(500);

		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;

	}
	catch (const std::exception& e) {
		std::cerr << e.what();
	}
	std::cout << "\n---- Overflow Test ----" << std::endl;
	try {
		Span	sp(2);
	
		sp.addNumber(42);
		sp.addNumber(84);
		sp.addNumber(900);

		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;

	}
	catch (const std::exception& e) {
		std::cerr <<  e.what();
	}
	std::cout << "\n---- Too Small Test ----" << std::endl;
	try {
		Span	sp(1);
	
		sp.addNumber(42);
		sp.addNumber(84);

		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << e.what();
	}
	std::cout << "\n---- Mass Test ----" << std::endl;
	try {
		Span	sp(10000);
	
		sp.fillList(10000, 1000000);
		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << e.what();
	}
}
