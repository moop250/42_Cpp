/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 17:34:49 by hlibine           #+#    #+#             */
/*   Updated: 2025/02/07 15:38:14 by hlibine          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Base.hpp"
#include "../incl/A.hpp"
#include "../incl/B.hpp"
#include "../incl/C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base *generate(void) {
	srand(time(NULL));
	int i = rand() % 3;

	switch(i){
		case(0):
			// std::cout << "made an A" << std::endl;
			return new A;
			break;
		case(1):
			// std::cout << "made a B" << std::endl;
			return new B;
			break;
		case(2):
			// std::cout << "made a C" << std::endl;
			return new C;
			break;
	}
	return NULL;
}

void	identify(Base *p) {
	if (dynamic_cast<A*>(p))
		std::cout << "its a class of type \"A\"" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "its a class of type \"B\"" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "its a class of type \"C\"" << std::endl;
}

void	identify(Base &p) {
	if (dynamic_cast<A*>(&p))
		std::cout << "its a class of type \"A\"" << std::endl;
	else if (dynamic_cast<B*>(&p))
		std::cout << "its a class of type \"B\"" << std::endl;
	else if (dynamic_cast<C*>(&p))
		std::cout << "its a class of type \"C\"" << std::endl;

}

int	main(void) {
	Base *one;
	Base *two;
	Base *three;

	one = generate();
	two = generate();
	three = generate();

	std::cout << "--- Identify *p" << std::endl;
	identify(one);
	identify(two);
	identify(three);
	std::cout << std::endl;

	std::cout << "--- Identify *p" << std::endl;

	identify(*one);
	identify(*two);
	identify(*three);
	std::cout << std::endl;

	delete one;
	delete two;
	delete three;

	return (0);
}
