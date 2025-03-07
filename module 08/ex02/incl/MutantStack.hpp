/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 17:08:14 by hlibine           #+#    #+#             */
/*   Updated: 2025/03/07 16:55:08 by hlibine          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_TEMPLATE_CLASS
# define MUTANTSTACK_TEMPLATE_CLASS

#include <stack>

template<class T, class Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
	public:
		typedef typename Container::iterator iterator;
		typedef typename Container::const_iterator const_iterator;

		iterator begin() {
			return this->c.begin();
		}
		iterator end() {
			return this->c.end();
		}
	
		const_iterator begin() const {
			return this->c.begin();
		}
		const_iterator end() const {
			return this->c.end();
		}
};

#endif
