/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:00:58 by hlibine           #+#    #+#             */
/*   Updated: 2025/01/27 16:39:26 by hlibine          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMY_REQUEST_FORM_HPP
# define ROBOTOMY_REQUEST_FORM_HPP

#include "AForm.hpp"
#include <string>

class RobotomyRequestForm : public AForm {
	private:
		std::string	target_;
		void		beExecuted_() const;

	public:
		RobotomyRequestForm(std::string target);
		~RobotomyRequestForm();
};

#endif
