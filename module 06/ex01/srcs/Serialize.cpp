/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialize.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 17:56:34 by hlibine           #+#    #+#             */
/*   Updated: 2025/02/10 12:55:42 by hlibine          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Serialize.hpp"

Serialize::Serialize(){}
Serialize::Serialize(const Serialize &src){(void)src;}
Serialize &Serialize::operator=(Serialize &src){(void)src; return *this;}
Serialize::~Serialize(){}

uintptr_t Serialize::serialize(Data *ptr) {
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data *Serialize::deserialize(uintptr_t raw) {
	return (reinterpret_cast<Data*>(raw));
}
