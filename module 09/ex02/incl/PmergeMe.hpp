/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:41:12 by hlibine           #+#    #+#             */
/*   Updated: 2025/04/25 17:15:59 by hlibine          ###   ########.fr       */
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

// template<typename Container>
class PmergeMe {
	private:
		static vi avToIt_(const char **av, const int ac);
		static void swapPairs_(vi &vec, size_t index1, size_t index2);

	public:
		static void 	intake(int ac, const char **av);
		static double	sortVector(const int ac, const char **av);
		static double	sortDeque(const int ac, const char **av);
};

#endif