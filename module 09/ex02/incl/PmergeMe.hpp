/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:41:12 by hlibine           #+#    #+#             */
/*   Updated: 2025/04/21 14:35:09 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PmergeMe_CLASS_HPP
# define PmergeMe_CLASS_HPP

#include <string>
#include <vector>
#include <deque>

#define vi std::vector<int>
#define vit std::vector<int>::iterator
#define dq std::deque<int>
#define dqt std::deque<int>::iterator

class PmergeMe {
	public:
		static std::string 	intake(int ac, const char **av);
		static double		sortVector(const std::string in);
		static double		sortDeque(const std::string in);
};

#endif