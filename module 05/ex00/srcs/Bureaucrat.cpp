/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:57:41 by hlibine           #+#    #+#             */
/*   Updated: 2025/01/20 18:21:58 by hlibine          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Bureaucrat.hpp"
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
	if ((this->grade_ + i) > 250)
		throw Bureaucrat::GradeTooLowException();
	this->grade_ += i;
}
