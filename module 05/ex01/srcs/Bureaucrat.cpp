/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:57:41 by hlibine           #+#    #+#             */
/*   Updated: 2025/01/22 17:45:14 by hlibine          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Bureaucrat.hpp"
#include "../incl/Form.hpp"
#include <string>


Bureaucrat::Bureaucrat(void) : name_("Standard Employee"), grade_(150) {
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name_(name), grade_(grade) {
	if (this->grade_ < 1)
		throw Bureaucrat::GradeTooHighExecption();
	else if (this->grade_ > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : name_(src.name_) {
	this->grade_ = src.grade_;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src) {
	if (this != &src) {
		this->grade_ = src.grade_;
	}
	return *this;
}

Bureaucrat::~Bureaucrat() {
}

/*  Class Functions  */

int Bureaucrat::getGrade(void) const {
	return this->grade_;
}

std::string Bureaucrat::getName(void) const {
	return this->name_;
}

void Bureaucrat::incrementGrade(int i) {
	if ((this->grade_ - i) < 1)
		throw Bureaucrat::GradeTooHighExecption();
	else {
		this->grade_ -= i;
		std::cout << this->name_ << "was promoted to grade " << this->grade_ << std::endl;
	}
}

void Bureaucrat::decrementGrade(int i) {
	if ((this->grade_ + i) > 150) {
		throw Bureaucrat::GradeTooLowException();
	} else {
		this->grade_ += i;
		std::cout << this->name_ << "was demoted to grade " << this->grade_ << std::endl;
	}
}

void Bureaucrat::signForm(Form &toSign) const {
	if (toSign.getSignLevel() < this->getGrade()) {
		std::cout << this->name_ << " couldnt sighn form " << toSign.getName() << " because their grade ";
		throw Bureaucrat::GradeTooLowException();
	} else {
		toSign.setSigned(true);
		std::cout << "Form " << toSign.getName() << " was signed by " << this->name_ << std::endl;
	}
}
