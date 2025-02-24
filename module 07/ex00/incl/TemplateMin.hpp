/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TemplateMin.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 17:06:35 by hlibine           #+#    #+#             */
/*   Updated: 2025/02/21 17:08:47 by hlibine          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATEMIN_HPP
# define TEMPLATEMIN_HPP

template<typename T>
const T& min(const T& a, const T& b) {
	return (b <= a ? b : a);
}

#endif

