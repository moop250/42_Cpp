/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:49:32 by hlibine           #+#    #+#             */
/*   Updated: 2025/01/22 17:35:50 by hlibine          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_CLASS_HPP
# define FORM_CLASS_HPP

#include "Bureaucrat.hpp"
#include <exception>
#include <string>
#include <ostream>

class Form {
	private:
		const std::string	name_;
		bool				is_signed_;
		const int			sign_level_;
		const int			execute_level_;
	public:
	/*  Constructors and Destructors  */
		Form(void);
		Form(std::string name, int sign_level, int execute_level);
		Form(const Form &src);
		Form &operator=(const Form &src);
		~Form(void);
	/*  Getters & Setters  */
		std::string	getName(void) const;
		bool		getSigned() const;
		int			getSignLevel() const;
		int			getExecuteLevel() const;
		void		setSigned(bool var);
	/* Member Functions */
		void	beSigned(Bureaucrat &signer);
	
	/*  Exception Definitions  */
	class GradeTooHighException : public std::exception {
		virtual const char *what() const throw() {
			return ("Form level is too high");
		}
	};

	class GradeTooLowException : public std::exception {
		virtual const char *what() const throw() {
			return ("Form level is too low");
		}
	};
};

/* Ostream Operator Overload  */
std::ostream &operator<<(std::ostream &fd, const Form &src);

#endif
