/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:11:32 by hlibine           #+#    #+#             */
/*   Updated: 2025/01/13 18:28:01 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

	#include <iostream>
	#include "../incl/Dog.hpp"
	#include "../incl/Cat.hpp"
	#include "../incl/WrongCat.hpp"

void defaultAnimals()
{
	Animal a;
	Dog b;
	Cat c;
	WrongCat d;
	
	std::cout << std::endl;
	std::cout << a.getType() << " " << std::endl;
	std::cout << b.getType() << " " << std::endl;
	std::cout << c.getType() << " " << std::endl;
	std::cout << d.getType() << " " << std::endl;
	std::cout << std::endl;
	a.makeSound();
	b.makeSound();
	c.makeSound();
	d.makeSound();
	std::cout << std::endl;
}

int main()
{
	std::cout << "----Default Animals----" << std::endl;
	defaultAnimals();
	return 0;
}