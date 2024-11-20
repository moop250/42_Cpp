/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:59:33 by hlibine           #+#    #+#             */
/*   Updated: 2024/11/20 14:57:58 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <math.h>

class Fixed {
private:
	int					value_;
	static const int	fractionalBits_ = 8;

public:
//	Constructors and Destructor
	Fixed(void);
	Fixed(const Fixed &src);
	Fixed &operator=(const Fixed &src);
	Fixed(const int value);
	Fixed(const float value);
	~Fixed(void);
//	Class Methods
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	int		toInt(void) const;
	float	toFloat(void) const;
// Static Class Methods
	static Fixed&		min(Fixed &a, Fixed &b);
	static const Fixed&	min(const Fixed &a, const Fixed &b);
	static Fixed&		max(Fixed &a, Fixed &b);
	static const Fixed&	max(const Fixed &a, const Fixed &b);
//	Operator Overloads
	Fixed	operator+(const Fixed &obj) const;
	Fixed	operator-(const Fixed &obj) const;
	Fixed	operator*(const Fixed &src) const;
	Fixed	operator/(const Fixed &src) const;
	Fixed	operator++(int);
	Fixed	operator++(void);
	Fixed	operator--(int);
	Fixed	operator--(void);
	bool	operator>(const Fixed &src) const;
	bool	operator<(const Fixed &src) const;
	bool	operator>=(const Fixed &src) const;
	bool	operator<=(const Fixed &src) const;
	bool	operator==(const Fixed &src) const;
	bool	operator!=(const Fixed &src) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& obj);
