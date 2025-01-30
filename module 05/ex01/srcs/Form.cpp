/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:49:30 by hlibine           #+#    #+#             */
/*   Updated: 2025/01/30 14:13:33 by hlibine          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Form.hpp"
#include "../incl/Bureaucrat.hpp"

/*  Constructors and Destructor  */

Form::Form(void) :
	name_("Blank Form"), is_signed_(false), sign_level_(150), execute_level_(100)
{
}

Form::Form(std::string name, int sign_level, int execute_level) :
	name_(name), is_signed_(false), sign_level_(sign_level), execute_level_(execute_level)
{
	if (sign_level < 1 || execute_level < 1)
		throw Form::GradeTooHighException();
	else if (sign_level > 150 || execute_level > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &src) :
	name_(src.name_), sign_level_(src.sign_level_), execute_level_(src.execute_level_)
{
	this->is_signed_ = src.is_signed_;
}

Form	&Form::operator=(const Form &src)
{
	if (this != &src) {
		this->is_signed_ = src.is_signed_;
	}
	return *this;
}

Form::~Form(void)
{
}

/*  Getters and Setters  */

std::string	Form::getName(void) const {
	return (this->name_);
}

bool		Form::getSigned(void) const {
	return (this->is_signed_);
}

int			Form::getSignLevel(void) const {
	return (this->sign_level_);
}

int			Form::getExecuteLevel(void) const {
	return (this->execute_level_);
}

void		Form::setSigned(bool var) {
	this->is_signed_ = var;
}

/*  Member Functions */

void	Form::beSigned(const Bureaucrat &signer) {
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


/*  Ostream Operator Overload  */

std::ostream &operator<<(std::ostream &fd, const Form &src) {
	fd << std::endl;
	fd << "------------------------------" << std::endl;
	fd << "  [Form] \"" << src.getName() <<  "\"" << std::endl;
	fd << std::endl;
	if (src.getSigned())
		fd << "  Signed:       \033[32m[true]\033[0m" << std::endl;
	else
		fd << "  Signed:       \033[31m[false]\033[0m" << std::endl;
	fd << std::endl;
	fd << "  Signing Grade:    [" << src.getSignLevel() << "]" << std::endl;
	fd << "  Execution Grade:  [" << src.getExecuteLevel() << "]" << std::endl;
	fd << std::endl;
	fd << "------------------------------" << std::endl;
	return (fd);
}
