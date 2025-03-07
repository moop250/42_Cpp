/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:59:33 by hlibine           #+#    #+#             */
/*   Updated: 2025/01/07 13:35:26 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

#include <iostream>
#include <math.h>

class Fixed {
private:
	int					value_;
	static const int	fractionalBits_ = 8;

public:
	Fixed(void);
	Fixed(const Fixed &src);
	Fixed &operator=(const Fixed &src);
	Fixed(const int value);
	Fixed(const float value);
	~Fixed(void);
	
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	int		toInt(void) const;
	float	toFloat(void) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif // FIXED_HPP