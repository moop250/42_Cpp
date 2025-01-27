/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:57:41 by hlibine           #+#    #+#             */
/*   Updated: 2025/01/27 16:57:24 by hlibine          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Bureaucrat.hpp"
#include "../incl/AForm.hpp"
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
	if ((this->grade_ - i) < 1) {
		std::cout << "Error: " << this->name_ << "'s ";
		throw Bureaucrat::GradeTooHighExecption();
	} else {
		this->grade_ -= i;
		std::cout << this->name_ << "was promoted to grade " << this->grade_ << std::endl;
	}
}

void Bureaucrat::decrementGrade(int i) {
	if ((this->grade_ + i) > 150) {
		std::cout << "Error: " << this->name_ << "'s ";
		throw Bureaucrat::GradeTooLowException();
	} else {
		this->grade_ += i;
		std::cout << this->name_ << "was demoted to grade " << this->grade_ << std::endl;
	}
}

void Bureaucrat::signForm(AForm &toSign) const {
	if (toSign.getSignLevel() < this->getGrade()) {
		std::cout << this->name_ << " couldnt sign \"" << toSign.getName() << "\" because their grade is too low" << std::endl;
		throw Bureaucrat::GradeTooLowException();
	}
	else {
		std::cout << "Executed :" << toSign.getExectued() << std::endl;
		toSign.setSigned(true);
		std::cout << "Executed :" << toSign.getExectued() << std::endl;
		std::cout << "Form " << toSign.getName() << " was signed by " << this->name_ << std::endl;
	}
}

void Bureaucrat::executeForm(AForm &toExecute) const {
	if (!toExecute.getSigned()) {
		std::cerr << this->name_ << " cannot execute form \"" << toExecute.getName() << " as it has not been signed" << std::endl;
		return ;
	}
	else if (this->grade_ > toExecute.getExecuteLevel()) {
		std::cerr << this->name_ << " does not have a high enough grade to execute form " << toExecute.getName() << std::endl;
		return ;
	}
	else if (toExecute.getExectued()) {
		std::cerr << this->name_ << " cannot execute \"" << toExecute.getName() << " as it has already been executed " << std::endl;
		return ;
	}
	toExecute.setExecuted(true);
	toExecute.beExecuted_();
	std::cout << this->name_ << " has executed \"" << toExecute.getName() << "\"";
}
