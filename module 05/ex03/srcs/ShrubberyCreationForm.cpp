/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:55:33 by hlibine           #+#    #+#             */
/*   Updated: 2025/01/24 16:13:17 by hlibine          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
	AForm("ShrubberyCrationForm", 145, 137), target_(target + "_shrubbery") {}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

void ShrubberyCreationForm::beExecuted_() const {
	std::ofstream	tree(target_.c_str());

	tree << "          &&& &&  & &&" << std::endl;
	tree << "      && &\\/&\\|& ()|/ @, &&" << std::endl;
	tree << "      &\\/(/&/&||/& /_/)_&/_&" << std::endl;
	tree << "   &() &\\/&|()|/&\\/ '%\" & ()" << std::endl;
	tree << "  &_\\_&&_\\ |& |&&/&__%_/_& &&" << std::endl;
	tree << "&&   && & &| &| /& & % ()& /&&" << std::endl;
	tree << " ()&_---()&\\&\\|&&-&&--%---()~" << std::endl;
	tree << "     &&     \\|||" << std::endl;
	tree << "             |||" << std::endl;
	tree << "             |||" << std::endl;
	tree << "             |||" << std::endl;
	tree << "       , -=-~  .-^- _" << std::endl;

	std::cout << "Tree has been sucessfully created" << std::endl;
}
