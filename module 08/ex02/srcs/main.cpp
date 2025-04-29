/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 17:08:17 by hlibine           #+#    #+#             */
/*   Updated: 2025/04/29 14:57:23 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/MutantStack.hpp"
#include <algorithm>
#include <iostream>
#include <list>
#include "../utils/colors.h"

int	main(void) {
	{
		std::cout << C_GREEN << "----- Sort Test -----" << C_RESET << std::endl;
		MutantStack<int> mutstack;
	
		mutstack.push(10);
		mutstack.push(61);
		mutstack.push(42);
		mutstack.push(-42);
		mutstack.push(789);
		mutstack.push(543);
	
		std::sort(mutstack.begin(), mutstack.end());
		for (int i = 0; !mutstack.empty(); i++) {
			std::cout << C_YELLOW << "Element " << C_RESET << i << C_YELLOW ": " << C_RESET << mutstack.top() << std::endl;
			mutstack.pop();
		}
	}
	{
		std::cout << C_GREEN << "\n----- List Comparison Test -----" << C_RESET << std::endl;
		std::list<int> tstlst;
	
		tstlst.push_back(10);
		tstlst.push_back(61);
		tstlst.push_back(42);
		tstlst.push_back(-42);
		tstlst.push_back(789);
		tstlst.push_back(543);
	
		tstlst.sort();
		for (int i = 0; !tstlst.empty(); i++) {
			std::cout << C_YELLOW << "Element " << C_RESET << i << C_YELLOW ": " << C_RESET << tstlst.back() << std::endl;
			tstlst.pop_back();
		}
	}
	{
		std::cout << C_GREEN << "\n----- Pop Test -----" << C_RESET << std::endl;

		MutantStack<std::string> mutstack;

		mutstack.push("The Man Who Sold the world");
		mutstack.push("Big Boss");

		std::cout << C_YELLOW << "Stack.top(): " << C_RESET << mutstack.top() << std::endl;
		mutstack.pop();
		std::cout << C_YELLOW << "Stack.top(): " << C_RESET << mutstack.top() << std::endl;
	}
	{
		std::cout << C_GREEN << "\n----- Pop List Test -----" << C_RESET << std::endl;

		std::list<std::string> tstlst;

		tstlst.push_back("The Man Who Sold the world");
		tstlst.push_back("Big Boss");

		std::cout << C_YELLOW << "List.back(): " << C_RESET << tstlst.back() << std::endl;
		tstlst.pop_back();
		std::cout << C_YELLOW << "List.back(): " << C_RESET << tstlst.back() << std::endl;
	}
	{
		std::cout << C_GREEN << "\n----- Copy Constructor Test -----" << C_RESET << std::endl;

		MutantStack<std::string> mutstack;
		MutantStack<std::string> otherstack;


		mutstack.push("Hello World");
		mutstack.push(":3");

		std::cout << C_YELLOW << "Mutstack.top(): " << C_RESET << mutstack.top() << std::endl;
	
		otherstack = mutstack;

		std::cout << std::endl << C_YELLOW << "Otherstack.top(): " << C_RESET << otherstack.top() << std::endl;
		otherstack.pop();
		std::cout << C_YELLOW << "Otherstack.top(): " << C_RESET << otherstack.top() << std::endl;

		std::cout << std::endl << C_YELLOW << "Mutstack.top(): " << C_RESET << mutstack.top() << std::endl;
	}
}
