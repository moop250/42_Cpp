/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:11:32 by hlibine           #+#    #+#             */
/*   Updated: 2024/12/21 16:15:01 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

	#include "../incl/Dog.hpp"
	#include <cstdio>
	#include "../incl/Cat.hpp"

void defaultAnimals()
{
	Dog b;
	Cat c;
	
	std::cout << std::endl;
	std::cout << b.getType() << " " << std::endl;
	std::cout << c.getType() << " " << std::endl;
	std::cout << std::endl;
	b.makeSound();
	c.makeSound();
	std::cout << std::endl;
}

void ideas()
{
	Dog a;
	Dog b;
	Cat c;
	Cat d;

	std::cout << std::endl;
	std::cout << "Ideas" << std::endl;
	a.printIdeas();
	b.printIdeas();
	c.printIdeas();
	d.printIdeas();
	std::cout << std::endl;
}

void leakTest()
{
	const Dog* j = new Dog();
	const Cat* i = new Cat();
	std::cout << std::endl;
	delete j;
	delete i;
	std::cout << std::endl;
}

int main()
{
	std::cout << "----Default Animals----" << std::endl;
	defaultAnimals();
	std::cout << "\n---------Ideas---------" << std::endl;
	ideas();
	std::cout << "\n-------Leak Test-------" << std::endl;
	leakTest();
	return 0;
}