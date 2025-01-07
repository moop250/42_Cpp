/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:59:33 by hlibine           #+#    #+#             */
/*   Updated: 2025/01/07 13:27:37 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

#include <iostream>

class Fixed {
private:
	int					value_;
	static const int	fractionalBits_ = 8;

public:
	Fixed(void);
	Fixed(const Fixed &src);
	Fixed &operator=(const Fixed &src);
	~Fixed(void);
	
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
};

#endif // FIXED_HPP