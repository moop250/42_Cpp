/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 17:17:40 by hlibine           #+#    #+#             */
/*   Updated: 2025/02/24 10:23:33 by hlibine          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/TemplateMax.hpp"
#include "../incl/TemplateMin.hpp"
#include "../incl/TemplateSwap.hpp"
#include <iostream>


int	main(void) {

	int	a = 21;
	int	b = 42;

	::swap(a, b);
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << std::endl;
	std::cout << ::max(a, b) << std::endl;
	std::cout << ::min(a, b) << std::endl;
	std::cout << std::endl;

	a = 30;
	b = 400;

	std::cout << ::max(a, b) << std::endl;
	std::cout << ::min(a, b) << std::endl;
	std::cout << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	::swap(a, b);
	std::cout << a << std::endl;
	std::cout << b << std::endl;

}
