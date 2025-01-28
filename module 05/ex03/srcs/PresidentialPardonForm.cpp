/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:33:37 by hlibine           #+#    #+#             */
/*   Updated: 2025/01/28 13:48:12 by hlibine          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
	  AForm("Presidential Pardon", 25, 5), target_(target) {};

PresidentialPardonForm::~PresidentialPardonForm() {};

void	PresidentialPardonForm::beExecuted_() const {
	std::cout << target_ << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
