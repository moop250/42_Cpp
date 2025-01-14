/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:11:32 by hlibine           #+#    #+#             */
/*   Updated: 2025/01/14 14:52:12 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

	#include "../incl/Dog.hpp"
	#include "../incl/Cat.hpp"
	#include "../incl/WrongCat.hpp"

void defaultAnimals()
{
	const Animal *a = new Animal();
	const Animal *b = new Dog();
	const Animal *c = new Cat();
	
	std::cout << std::endl;
	std::cout << "a is a " << a->getType() << " " << std::endl;
	std::cout << "b is a " << b->getType() << " " << std::endl;
	std::cout << "c is a " << c->getType() << " " << std::endl;
	std::cout << std::endl;
	a->makeSound();
	b->makeSound();
	c->makeSound();
	std::cout << std::endl;

	delete a;
	delete b;
	delete c;
}

void wrongAnimals()
{
	const WrongAnimal *a = new WrongAnimal();
	const WrongAnimal *b = new WrongCat();
	
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

int main()
{
	std::cout << "----Default Animals----" << std::endl;
	defaultAnimals();
	std::cout << std::endl;
	std::cout << "-----Wrong Animals-----" << std::endl;
	wrongAnimals();
	return 0;
}