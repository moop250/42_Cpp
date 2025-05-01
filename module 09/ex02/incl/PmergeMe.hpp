/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:41:12 by hlibine           #+#    #+#             */
/*   Updated: 2025/05/01 18:13:40 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PmergeMe_CLASS_HPP
# define PmergeMe_CLASS_HPP

#include <cstddef>
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
		static	vi avToIt_(const char **av, const int ac);
		static	dq avToDq_(const char **av, const int ac);

	public:
		static void 	intake(int ac, const char **av);
		static double	sortVector(const int ac, const char **av);
		static double	sortDeque(const int ac, const char **av);
};

template<typename Container>
class TPmergeMe {
	private:
		size_t		comparisons_;
		Container	main_;
		Container	pend_;
		Container	non_;
		size_t		currentJacobsthal;
		size_t		prevJacobsthal;
		size_t		lvlJacobsthal;
		void		moveTo_(Container &src, Container &dst, const size_t len);
		void		swapPairs_(Container &cont, size_t index1, size_t index2);
		void		augmentJacobsthal_();
		typedef typename Container::iterator Iterator;

	public:
		TPmergeMe(void);
		~TPmergeMe();
		void sortCont(const size_t recLev, Container &cont, const int isOdd);
};

#endif