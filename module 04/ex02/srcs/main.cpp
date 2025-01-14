/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:11:32 by hlibine           #+#    #+#             */
/*   Updated: 2025/01/14 15:52:59 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

	#include "../incl/Dog.hpp"
	#include "../incl/Cat.hpp"


void defaultAnimals()
{
	const Cat *a = new Cat();
	const Dog *b = new Dog();
	//const abAnimal test;

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
	const Dog *a = new Dog();
	const Cat *b = new Cat();

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
	std::cout << std::endl;
}

int main()
{
	std::cout << "----Default Animals----" << std::endl;
	defaultAnimals();
	std::cout << std::endl;
	std::cout << "-------Leak Test-------" << std::endl;
	leaks();
	return 0;
}
