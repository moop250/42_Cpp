/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 17:08:14 by hlibine           #+#    #+#             */
/*   Updated: 2025/03/06 18:18:43 by hlibine          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_TEMPLATE_CLASS
# define MUTANTSTACK_TEMPLATE_CLASS

#include <stack>

template<typename T>
class MutantStack : public std::stack<T> {
	public:
		MutantStack(void) : std::stack<T>() {};
		MutantStack(const MutantStack &src) : std::stack<T>(src) {};
		MutantStack& operator=(const MutantStack &src)
		{
			if (this != &src)
				std::stack<T>::operator=(src);
			return *this;
		}
		~MutantStack();
		T& top();
};

#endif
