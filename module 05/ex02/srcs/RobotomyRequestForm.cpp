/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:01:00 by hlibine           #+#    #+#             */
/*   Updated: 2025/01/27 16:47:11 by hlibine          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
	AForm("RobotomyRequestForm", 72, 45), target_(target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::beExecuted_() const {
	std::cout << "*Loud Drilling and Buzzing noises*" << std::endl;
	int randomNum = rand() % 101;
	
	if (randomNum <= 50) {
		std::cout << target_ << " has been succesfully robotomized" << std::endl;
	}
	else {
		std::cout << "The robotomy of " << target_ << " has failed" << std::endl;
	}
}
