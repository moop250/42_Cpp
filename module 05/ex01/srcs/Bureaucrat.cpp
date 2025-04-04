/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:57:41 by hlibine           #+#    #+#             */
/*   Updated: 2025/02/12 14:08:55 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Bureaucrat.hpp"
#include "../incl/Form.hpp"


Bureaucrat::Bureaucrat(void) {
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

void Bureaucrat::signForm(Form &toSign) const {
	if (toSign.getSignLevel() < this->getGrade()) {
		std::cout << this->name_ << " couldnt sign \"" << toSign.getName() << "\" because their grade is too low" << std::endl;
		throw Bureaucrat::GradeTooLowException();
	} else {
		toSign.beSigned(*this);
	}
}

/*  ostream  */
std::ostream &operator<<(std::ostream &out, const Bureaucrat &src) {
	out << src.getName() << ", bureaucrat grade " << src.getGrade() << std::endl;
	return out;
}