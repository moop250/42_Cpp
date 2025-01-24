/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:49:30 by hlibine           #+#    #+#             */
/*   Updated: 2025/01/24 16:14:15 by hlibine          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/AForm.hpp"
#include "../incl/Bureaucrat.hpp"
#include <iostream>

/*  Constructors and Destructor  */

AForm::AForm(void) :
	name_("Blank Form"), is_signed_(false), is_executed_(false), sign_level_(150), execute_level_(100)
{
}

AForm::AForm(std::string name, int sign_level, int execute_level) :
	name_(name), is_signed_(false), is_executed_(false), sign_level_(sign_level), execute_level_(execute_level)
{
	if (sign_level < 1 || execute_level < 1)
		throw AForm::GradeTooHighException();
	else if (sign_level > 150 || execute_level > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &src) :
	name_(src.name_), sign_level_(src.sign_level_), execute_level_(src.execute_level_)
{
	this->is_signed_ = src.is_signed_;
}

AForm	&AForm::operator=(const AForm &src)
{
	if (this != &src) {
		this->is_signed_ = src.is_signed_;
	}
	return *this;
}

AForm::~AForm(void)
{
}

/*  Getters and Setters  */

std::string	AForm::getName(void) const {
	return (this->name_);
}

bool		AForm::getSigned(void) const {
	return (this->is_signed_);
}

bool		AForm::getExectued(void) const {
	return (this->is_signed_);
}

int			AForm::getSignLevel(void) const {
	return (this->sign_level_);
}

int			AForm::getExecuteLevel(void) const {
	return (this->execute_level_);
}

void		AForm::setSigned(bool var) {
	this->is_signed_ = var;
}


/*  Member Functions */

void	AForm::beSigned(Bureaucrat &signer) {
	if(signer.getGrade() > this->sign_level_) {
		std::cout << signer.getName() << " couldn't sign \"" << this->name_ << "\" because they are too low of a grade!" << std::endl;
		throw Bureaucrat::GradeTooLowException();
	}
	else if (!this->is_signed_) {
		std::cout << signer.getName() << " has signed form " << this->name_ << std::endl;
		this->is_signed_ = true;
	}
	else {
		std::cout << "This form has already been signed" << std::endl;
	}
}

void	AForm::execute(Bureaucrat const & executor) {
	if (executor.getGrade() > this->execute_level_) {
		std::cerr << "Bureaucrat " << executor.getName() << " does not have a high enough grade to sign \"" << this->name_ << "\"" << std::endl;
		return ;
	}
	else if (this->is_executed_) {
		std::cerr << "\"" << this->name_ << "\" has already been executed" << std::endl;
		return ;
	}
	this->is_executed_ = true;
	beExecuted_();
}


/*  Ostream Operator Overload  */

std::ostream &operator<<(std::ostream &fd, const AForm &src) {
	fd << std::endl;
	fd << "------------------------------" << std::endl;
	fd << "  [AForm] \"" << src.getName() <<  "\"" << std::endl;
	fd << std::endl;
	if (src.getSigned())
		fd << "  Signed:       \033[32m[true]\033[0m" << std::endl;
	else
		fd << "  Signed:       \033[31m[false]\033[0m" << std::endl;
	fd << std::endl;
	if (src.getExectued())
		fd << "  Executed:     \033[32m[true]\033[0m" << std::endl;
	else
		fd << "  Executed:     \033[31m[false]\033[0m" << std::endl;
	fd << std::endl;
	fd << "  Signing Grade:    [" << src.getSignLevel() << "]" << std::endl;
	fd << "  Execution Grade:  [" << src.getExecuteLevel() << "]" << std::endl;
	fd << std::endl;
	fd << "------------------------------" << std::endl;
	return (fd);
}
