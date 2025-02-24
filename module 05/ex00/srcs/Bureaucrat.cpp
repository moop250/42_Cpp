/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:57:41 by hlibine           #+#    #+#             */
/*   Updated: 2025/02/12 14:11:35 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Bureaucrat.hpp"


Bureaucrat::Bureaucrat(void) {}

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

int Bureaucrat::getGrade(void) {
	return this->grade_;
}

std::string Bureaucrat::getName(void) {
	return this->name_;
}

void Bureaucrat::incrementGrade(int i) {
	if ((this->grade_ - i) < 1)
		throw Bureaucrat::GradeTooHighExecption();
	this->grade_ -= i;
}

void Bureaucrat::decrementGrade(int i) {
	if ((this->grade_ + i) > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade_ += i;
}

/*  ostream  */
std::ostream &operator<<(std::ostream &out, Bureaucrat &src) {
	out << src.getName() << ", bureaucrat grade " << src.getGrade() << std::endl;
	return out;
}