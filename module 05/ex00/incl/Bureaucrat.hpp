/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:57:40 by hlibine           #+#    #+#             */
/*   Updated: 2025/02/12 14:07:46 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_CLASS_HPP
# define BUREAUCRAT_CLASS_HPP

#include <exception>
#include <iostream>
#include <ostream>
#include <string>

class Bureaucrat {
	private:
		const std::string	name_;
		int					grade_;
		Bureaucrat(void);

	public:
	/*  Constructors and Destructor  */
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat &src);
		Bureaucrat &operator=(const Bureaucrat &src);
		~Bureaucrat(void);
	/*  Member Functions  */
		std::string	getName(void);
		int			getGrade(void);
		void		incrementGrade(int i);
		void		decrementGrade(int i);

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

std::ostream	&operator<<(std::ostream &o, Bureaucrat &src);

#endif
