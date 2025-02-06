/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 13:53:07 by hlibine           #+#    #+#             */
/*   Updated: 2025/02/06 14:39:23 by hlibine          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Serialize.hpp"
#include <iostream>

int	main(void) {

	Data* tmp = new Data;
	Data* out;
	uintptr_t	ptr;

	tmp->i = 20;
	tmp->tst = "wawa :3";

	std::cout << "tmp address:\t" << &tmp << std::endl;
	std::cout << "tmp tst:\t" << tmp->tst << std::endl << "tmp i:\t" << tmp->i << std::endl;
	ptr = Serialize::serialize(tmp);
	std::cout << "serialized pointer:\t" << ptr << std::endl;
	out = Serialize::deserialize(ptr);
	std::cout << "out address:\t" << &out << std::endl;
	std::cout << "out tst:\t" << out->tst << std::endl << "out i:\t" << out->i << std::endl;

	delete tmp;
}
