/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 17:22:48 by hlibine           #+#    #+#             */
/*   Updated: 2024/12/23 14:18:54 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(void) {
	std::string		str = "HI THIS IS BRAIN";

	std::string*	ptr = &str;
	std::string&	ref = str;

	std::cout << "\n --- Address ---\n" << std::endl;
	std::cout << "String address:    " << &str << std::endl;
	std::cout << "Pointer address:   " << ptr << std::endl;
	std::cout << "Reference address: " << &ref << std::endl;

	std::cout << "\n --- Value ---\n" << std::endl;
	std::cout << "String:           " << str << std::endl;
	std::cout << "Pointer string:   " << *ptr << std::endl;
	std::cout << "Reference string: " << ref << std::endl;
	
	return 0;
}
