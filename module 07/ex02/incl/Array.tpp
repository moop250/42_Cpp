/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:08:24 by hlibine           #+#    #+#             */
/*   Updated: 2025/04/15 17:01:15 by hlibine          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template<class T>
Array<T>::Array(void) : len_(0), arr_(new T[0]()) {}

template<class T>
Array<T>::Array(size_t n) : len_(n), arr_(new T[n]) {}

template<class T>
Array<T>::Array(const Array &src) : len_(src.len_), arr_(new T[src.len_]) {
	for (size_t i = 0; i < src.len_; i++) {
		arr_[i] = src.arr_[i];
	}
}

template<class T>
Array<T>& Array<T>::operator=(const Array &src) {
if (this != &src) {
		this->len_ = src.len_;
		delete [] this->arr_;
		this->arr_ = new T[this->len_];
		for (size_t i = 0; i < this->len_; i++) {
			this->arr_[i] = src.arr_[i];
		}
	}
	return *this;
}

template<class T>
Array<T>::~Array() {
	delete [] this->arr_;
}

template<class T>
T& Array<T>::operator[](const size_t n) const {
	if (n < this->len_)
		return this->arr_[n];
	throw OOBException();
}

template<class T>
size_t Array<T>::size(void) const {
	return this->len_;
}
