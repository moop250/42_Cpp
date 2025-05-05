/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:41:12 by hlibine           #+#    #+#             */
/*   Updated: 2025/05/05 16:15:14 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PmergeMe_CLASS_HPP
# define PmergeMe_CLASS_HPP

#include <cmath>
#include <cstddef>
#include <iostream>
#include <cstdlib>
#include <exception>
#include <string>
#include <vector>
#include <deque>
#include <climits>
#include <sstream>

#define vi std::vector<int>
#define vit std::vector<int>::iterator
#define dq std::deque<int>
#define dqt std::deque<int>::iterator

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
		size_t		binarySearch_(const size_t target, Container &cont, size_t inc);
		typedef typename Container::iterator Iterator;

	public:
		TPmergeMe(void);
		~TPmergeMe();
		void sortCont(const size_t recLev, Container &cont, const int isOdd);
		void		isSorted(const Container &cont);
};

template<typename Container>
TPmergeMe<Container>::TPmergeMe(void) : comparisons_(0), currentJacobsthal(3), prevJacobsthal(1), lvlJacobsthal(4) {};

template<typename Container>
TPmergeMe<Container>::~TPmergeMe(void) {};

template<typename Container>
void TPmergeMe<Container>::isSorted(const Container &cont) {
	for (size_t i = 1; i < cont.size(); i++) {
		if (cont.at(i) < cont.at(i - 1))
			throw std::runtime_error("list was not sorted correctly");
	}
}

template<typename Container>
void	TPmergeMe<Container>::swapPairs_(Container &cont, size_t index1, size_t index2) {
	++comparisons_;
	if (cont.at(index1) > cont.at(index2))
		for (size_t i = index2 - index1; i > 0; i--) {
			std::swap(cont.at(index1--), cont.at(index2--));
		}
}

template<typename Container>
void	TPmergeMe<Container>::moveTo_(Container &src, Container &dst, const size_t len) {
	for (size_t i = 0; i < len; i++) {
		dst.push_back(src.at(0));
		src.erase(src.begin());
	}
}

template<typename Container>
void TPmergeMe<Container>::augmentJacobsthal_() {
	prevJacobsthal = currentJacobsthal;
	currentJacobsthal = (std::pow(2,lvlJacobsthal) - pow(-1, lvlJacobsthal)) / 3;
	++lvlJacobsthal;
}

template<typename Container>
size_t TPmergeMe<Container>::binarySearch_(const size_t target, Container &cont, size_t inc) {
	size_t left = 0;
	size_t right = cont.size() / inc;

	while (left < right) {
		size_t mid = left + (right - left) / 2;
		++comparisons_;
		if (static_cast<size_t>(cont.at(mid * inc + inc - 1)) < target) {
			left = mid + 1;
		} else {
			right = mid;
		}
	}
	return left * inc;
}

template<typename Container>
void TPmergeMe<Container>::sortCont(const size_t recLev, Container &cont, const int isOdd) {
	size_t inc = std::pow(2, recLev);
	size_t inc2 = 2 * inc;
	/*  Check to see if we have reached the end of the recursion  */
	if (cont.size() < inc2)
		return;

	/*  Merge Sort  */
	size_t limit = cont.size() - inc2 + 1;
	for (size_t i = 0; i < limit; i += inc2) {
		size_t index1 = i + inc - 1;
		size_t index2 = i + inc2 - 1;
		swapPairs_(cont, index1, index2);
	}
	TPmergeMe<Container>::sortCont(recLev + 1, cont, isOdd);

	/*  Split numbers into main and pend  */
	for (size_t i = 0; i < inc2; i++) {
		main_.push_back(cont.at(0));
		cont.erase(cont.begin());
	}

	for (size_t i = 0, b = 0; i + inc < limit; i += inc) {
		if (++b % 2)
			moveTo_(cont, pend_, inc);
		else
			moveTo_(cont, main_, inc);
	}
	moveTo_(cont, non_, cont.size());

	/*  Insertion Sort  */
	size_t jacobsthalDiff = currentJacobsthal - prevJacobsthal;
	while (jacobsthalDiff) {
		if (jacobsthalDiff * inc > pend_.size())
			break;
		size_t bin = binarySearch_(pend_.at((jacobsthalDiff * inc) - 1), main_, inc);
		main_.insert(main_.begin() + bin, pend_.begin() + (jacobsthalDiff * inc) - inc, pend_.begin() + jacobsthalDiff * inc);
		pend_.erase(pend_.begin() + (jacobsthalDiff * inc) - inc, pend_.begin() + jacobsthalDiff * inc);
		--jacobsthalDiff;
	}

	while (!pend_.empty()) {
		size_t bin = binarySearch_(pend_.at(pend_.size() - 1), main_, inc);
		main_.insert(main_.begin() + bin, pend_.end() - inc, pend_.end());
		pend_.erase(pend_.end() - inc, pend_.end());
	}
	augmentJacobsthal_();

	/*  Push everything back into cont  */
	moveTo_(main_, cont, main_.size());
	moveTo_(non_, cont, non_.size());

	return ;
}

#endif