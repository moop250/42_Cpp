/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 11:08:21 by hlibine           #+#    #+#             */
/*   Updated: 2025/02/26 16:20:00 by hlibine          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/iter.hpp"
#include "../incl/print.hpp"
#include "../incl/aug.hpp"

int	main(void) {
	int array1[] = {1, 2, 4, 5, 6, 8, 32, 42};
	std::string array2[] = {"aur", "naur", "big boss"};

	iter(array1, 8, print<const int>);
	std::cout << std::endl;
	iter(array1, 8, augment<int>);
	iter(array1, 8, print<const int>);

	std::cout << std::endl;
	iter(array2, 3, print<const std::string>);

	return (0);
}
