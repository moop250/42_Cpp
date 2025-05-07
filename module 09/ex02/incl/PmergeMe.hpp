/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:41:12 by hlibine           #+#    #+#             */
/*   Updated: 2025/05/07 16:49:07 by hlibine          ###   ########.fr       */
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
		TPmergeMe(void);
		Container	cont_;
		size_t		comparisons_;
		Container	main_;
		Container	pend_;
		Container	non_;
		size_t		currentJacobsthal_;
		size_t		prevJacobsthal_;
		size_t		lvlJacobsthal_;
		void		moveTo_(Container &src, Container &dst, const size_t len);
		void		swapPairs_(Container &cont, size_t index1, size_t index2);
		void		augmentJacobsthal_();
		size_t		binarySearch_(const size_t target, Container &cont, size_t inc);

	public:
		TPmergeMe<Container>(Container cont);
		TPmergeMe<Container>(const TPmergeMe<Container> &src);
		TPmergeMe<Container>& operator=(const TPmergeMe<Container> &src);
		~TPmergeMe();
		void		sortCont(const size_t recLev);
		void		isSorted();
		size_t		getComparisons();
		void		printCont();
};

template<typename Container>
TPmergeMe<Container>::TPmergeMe(void) : comparisons_(0), currentJacobsthal_(3), prevJacobsthal_(1), lvlJacobsthal_(4) {};

template<typename Container>
TPmergeMe<Container>::TPmergeMe(Container cont) : cont_(cont), comparisons_(0), currentJacobsthal_(3), prevJacobsthal_(1), lvlJacobsthal_(4) {};

template<typename Container>
TPmergeMe<Container>::TPmergeMe(const TPmergeMe<Container> &src) :
	cont_(src.cont_),
	comparisons_(src.comparisons_),
	currentJacobsthal_(src.currentJacobsthal_),
	prevJacobsthal_(src.prevJacobsthal_),
	lvlJacobsthal_(src.lvlJacobsthal_) {}

template<typename Container>
TPmergeMe<Container>& TPmergeMe<Container>::operator=(const TPmergeMe<Container> &src) {
	if (src != this) {
		this->cont_ = src.cont_;
		this->comparisons_ = src.comparisons_;
		this->currentJacobsthal_ = src.currentJacobsthal_;
		this->prevJacobsthal_ = src.prevJacobsthal_;
		this->lvlJacobsthal_ = src.lvlJacobsthal_;
	}
	return *this;
}

template<typename Container>
TPmergeMe<Container>::~TPmergeMe(void) {};

template<typename Container>
void TPmergeMe<Container>::isSorted() {
	for (size_t i = 1; i < cont_.size(); i++) {
		if (cont_.at(i) < cont_.at(i - 1))
			throw std::runtime_error("list was not sorted correctly");
	}
}

template<typename Container>
size_t	TPmergeMe<Container>::getComparisons(void) {
	return comparisons_;
}

template<typename Container>
void TPmergeMe<Container>::printCont(void) {
	for (size_t i = 0; i < cont_.size(); i++) {
		std::cout << cont_.at(i) << " ";
	}
	std::cout << std::endl;
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
	prevJacobsthal_ = currentJacobsthal_;
	currentJacobsthal_ = (std::pow(2,lvlJacobsthal_) - pow(-1, lvlJacobsthal_)) / 3;
	++lvlJacobsthal_;
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
void TPmergeMe<Container>::sortCont(const size_t recLev) {
	size_t inc = std::pow(2, recLev);
	size_t inc2 = 2 * inc;
	/*  Check to see if we have reached the end of the recursion  */
	if (cont_.size() < inc2)
		return;

	/*  Merge Sort  */
	size_t limit = cont_.size() - inc2 + 1;
	for (size_t i = 0; i < limit; i += inc2) {
		size_t index1 = i + inc - 1;
		size_t index2 = i + inc2 - 1;
		swapPairs_(cont_, index1, index2);
	}
	TPmergeMe<Container>::sortCont(recLev + 1);

	/*  Split numbers into main and pend  */
	for (size_t i = 0; i < inc2; i++) {
		main_.push_back(cont_.at(0));
		cont_.erase(cont_.begin());
	}

	for (size_t i = 0, b = 0; i + inc < limit; i += inc) {
		if (++b % 2)
			moveTo_(cont_, pend_, inc);
		else
			moveTo_(cont_, main_, inc);
	}
	moveTo_(cont_, non_, cont_.size());

	/*  Insertion Sort  */
	size_t jacobsthalDiff = currentJacobsthal_ - prevJacobsthal_;
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
	moveTo_(main_, cont_, main_.size());
	moveTo_(non_, cont_, non_.size());

	return ;
}

#endif