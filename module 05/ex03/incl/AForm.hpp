/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:49:32 by hlibine           #+#    #+#             */
/*   Updated: 2025/02/12 14:32:30 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_CLASS_HPP
# define AFORM_CLASS_HPP

#include <exception>
#include <string>
#include <ostream>

class Bureaucrat;

class AForm {
	private:
		const std::string	name_;
		bool				is_signed_;
		bool				is_executed_;
		const int			sign_level_;
		const int			execute_level_;
		AForm(void);
	protected:
		virtual void	beExecuted_() const = 0;
	public:
	/*  Constructors and Destructors  */
		AForm(std::string name, int sign_level, int execute_level);
		AForm(const AForm &src);
		AForm &operator=(const AForm &src);
		virtual ~AForm(void);
	/*  Getters & Setters  */
		std::string	getName(void) const;
		bool		getSigned() const;
		bool		getExectued() const;
		int			getSignLevel() const;
		int			getExecuteLevel() const;
		void		setSigned(bool var);
		void		setExecuted(bool var);
	/* Member Functions */
		void			beSigned(Bureaucrat const &signer);
		void			execute(Bureaucrat const & executor);

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
	class FormNotSigned : public std::exception {
		virtual const char *what() const throw() {
			return ("Form needs to be signed before it can be executed");
		}
	};
	class CantBeExecuted : public std::exception {
		virtual const char *what() const throw() {
			return ("This Bureaucrat does not have a sufficent grade to execute this form");
		}
	};
	class FormAlreadyExecuted : public std::exception {
		virtual const char *what() const throw() {
			return ("This Form has already been executed");
		}
	};

};
/* Ostream Operator Overload  */
std::ostream &operator<<(std::ostream &fd, const AForm &src);

#endif
