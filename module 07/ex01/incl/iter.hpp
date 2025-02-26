/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 11:08:17 by hlibine           #+#    #+#             */
/*   Updated: 2025/02/24 17:43:54 by hlibine          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <cstddef>

template<typename T>
void	iter(T *arr, size_t len, void (*f)(T &param)) {
	for (size_t i = 0; i < len; i++)
		f(arr[i]);
}

template<typename T>
void	iter(T *arr, size_t len, void (*f)(T const &param)) {
	for (size_t i = 0; i < len; i++)
		f(arr[i]);
}
#endif // !ITER_HPP
