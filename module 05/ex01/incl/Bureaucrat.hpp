/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:57:40 by hlibine           #+#    #+#             */
/*   Updated: 2025/01/22 17:37:59 by hlibine          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_CLASS_HPP
# define BUREAUCRAT_CLASS_HPP

#include <exception>
#include <iostream>
#include <ostream>
#include <string>

// Inclduing this here so that it can be used in toSign
class Form;

class Bureaucrat {
	private:
		const std::string	name_;
		int					grade_;

	public:
	/*  Constructors and Destructor  */
		Bureaucrat(void);
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat &src);
		Bureaucrat &operator=(const Bureaucrat &src);
		~Bureaucrat(void);
	/*  Member Functions  */
		std::string	getName(void) const;
		int			getGrade(void) const;
		void		incrementGrade(int i);
		void		decrementGrade(int i);
		void		signForm(Form &toSign) const;

	/*  Exception Definitions  */
	class GradeTooHighExecption : public std::exception {
		public:
			virtual const char *what() const throw() {
				return ("is to high!\n");
			}
	};
	class GradeTooLowException : public std::exception {
		public:
			virtual const char *what() const throw() {
				return ("is too low!\n");
			}
	};
};

std::ostream	&operator<<(std::ostream &o, Bureaucrat const &src);

#endif
