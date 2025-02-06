/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialize.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 17:56:33 by hlibine           #+#    #+#             */
/*   Updated: 2025/02/06 14:32:59 by hlibine          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZE_CLASS_HPP
# define SERIALIZE_CLASS_HPP

#include <cstdint>
#include <string>

typedef struct s_data {
	int			i;
	std::string	tst;
} Data;

class Serialize {
	private:
		Serialize();
		Serialize(const Serialize &src);
		Serialize& operator=(Serialize &src);
		virtual ~Serialize();

	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif
