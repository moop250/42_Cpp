/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:50:29 by hlibine           #+#    #+#             */
/*   Updated: 2025/02/27 19:19:59 by hlibine          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATE_ARRAY_CLASS_HPP
# define TEMPLATE_ARRAY_CLASS_HPP

#include <cstddef>
#include <exception>

template<typename T>
class	Array {
	private:
		size_t	len_;
		T*		arr_;

	public:
	/*  constructors and destructors  */
		Array(void);
		Array(size_t n);
		Array(const Array &src);
		Array&	operator=(const Array &src);
		T&		operator[](const size_t n) const;
		~Array(void);
	/*  member functions  */
		size_t size(void) const;

	class OOBException : public std::exception {
		public:
			virtual const char *what() const throw() {
				return ("Attempted to access an index that is out of bounds\n");
		}
	};
};

#endif
