/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:11:32 by hlibine           #+#    #+#             */
/*   Updated: 2025/01/14 16:12:19 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

	#include "../incl/Dog.hpp"
	#include "../incl/Cat.hpp"


void defaultAnimals()
{
	const Animal *a = new Dog();
	const Animal *b = new Cat();
	//Animal test;
	
	std::cout << std::endl;
	std::cout << "a is a " << a->getType() << " " << std::endl;
	std::cout << "b is a " << b->getType() << " " << std::endl;
	std::cout << std::endl;
	a->makeSound();
	b->makeSound();
	std::cout << std::endl;

	delete a;
	delete b;
}

void leaks()
{
	const Animal *a = new Dog();
	const Animal *b = new Cat();

	std::cout << std::endl;

	delete a;
	delete b;

	std::cout << std::endl << "-----Deep Copy Test-----" << std::endl;
	Dog basic;

	{
		std::cout << std::endl;
		Dog tmp = basic;
		std::cout << std::endl;
	}
}

void execLoop()
{
	const Animal* animals[4] = { new Dog(), new Dog(), new Cat(), new Cat() };
	for ( int i = 0; i < 4; i++ ) {
		delete animals[i];
	}
}

int main()
{
	std::cout << "----Default Animals----" << std::endl;
	defaultAnimals();
	std::cout << std::endl;
	std::cout << "-------Leak Test-------" << std::endl;
	leaks();
	std::cout << std::endl;
	std::cout << "-----Execution Loop----" << std::endl;
	execLoop();
	return 0;
}
