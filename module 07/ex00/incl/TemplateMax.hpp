/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TemplateMax.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 16:55:26 by hlibine           #+#    #+#             */
/*   Updated: 2025/02/21 17:08:32 by hlibine          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATEMAX_HPP
# define TEMPLATEMAX_HPP

template<typename T>
const T& max(const T& a, const T& b) {
	return (b >= a ? b : a);
}

#endif
