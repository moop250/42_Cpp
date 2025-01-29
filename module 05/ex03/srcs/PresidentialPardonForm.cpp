/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:33:37 by hlibine           #+#    #+#             */
/*   Updated: 2025/01/29 14:55:14 by hlibine          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
	  AForm("Presidential Pardon", 25, 5), target_(target) {};

PresidentialPardonForm::~PresidentialPardonForm() {};

void	PresidentialPardonForm::beExecuted_() const {
	std::cout << target_ << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
