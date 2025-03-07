/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 17:08:17 by hlibine           #+#    #+#             */
/*   Updated: 2025/03/07 17:05:07 by hlibine          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/MutantStack.hpp"
#include <algorithm>
#include <iostream>

int	main(void) {
	MutantStack<int> mutstack;

	mutstack.push(10);
	mutstack.push(61);
	mutstack.push(42);
	mutstack.push(-42);
	mutstack.push(789);
	mutstack.push(543);

	std::sort(mutstack.begin(), mutstack.end());

	for (int i = 0; !mutstack.empty(); i++) {
		std::cout << "Element " << i << ": " << mutstack.top() << std::endl;
		mutstack.pop();
	}
}
