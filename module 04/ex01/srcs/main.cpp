/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:11:32 by hlibine           #+#    #+#             */
/*   Updated: 2025/01/13 18:26:18 by hlibine          ###   ########.fr       */
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
	const Animal* j = new Dog();
	const Animal* i = new Cat();
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