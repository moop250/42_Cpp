/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:16:48 by hlibine           #+#    #+#             */
/*   Updated: 2024/12/19 16:27:10 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_CLASS_HPP
# define BRAIN_CLASS_HPP

# include <iostream>

class Brain {
	private:
		std::string ideas_[100];

	public:
		Brain();
		Brain(const Brain &src);
		Brain &operator=(const Brain &src);
		virtual ~Brain(void);
		std::string getIdea(int index) const;
};

#endif