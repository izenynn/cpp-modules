/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 01:35:56 by dpoveda-          #+#    #+#             */
/*   Updated: 2022/02/21 13:12:15 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

#include <algorithm>

Span::Span() {}

Span::Span(unsigned int n) : _size(n) {}

Span::Span(const Span& other) : _vector(other._vector), _size(other._size) {
	*this = other;
}

Span::~Span() {}

Span& Span::operator=(const Span& other) {
	if (this == &other) return *this;

	this->_size = other._size;
	this->_vector = other._vector;

	return *this;
}

void Span::addNumber(int n) {
	if (this->_vector.size() == this->_size) {
		throw Span::SpanIsFullException();
	}
	this->_vector.push_back(n);
}

void Span::addRange(IT begin, IT end) {
	if (this->_vector.size() + std::distance(begin, end) > this->_size) {
		throw Span::SpanIsFullException();
	}
	this->_vector.insert(this->_vector.end(), begin, end);
}

int Span::shortestSpan() const {
	if (this->_size < 2 || this->_vector.size() < 2) throw Span::SizeTooSmallException();

	std::vector<int> copy(this->_vector);
	std::sort(copy.begin(), copy.end());
	int ret = *(copy.begin() + 1) - *copy.begin();
	for (IT it = copy.begin(); it != copy.end() - 1; ++it) {
		if(*(it + 1) - *it < ret) {
			ret = *(it + 1) - *it;
		}
	}
	return ret;
}

int Span::longestSpan() const {
	if (this->_size < 2 || this->_vector.size() < 2) throw Span::SizeTooSmallException();
	return *std::max_element(this->_vector.begin(), this->_vector.end())
		- *std::min_element(this->_vector.begin(), this->_vector.end());
}

std::size_t Span::size() const {
	return this->_size;
}

const char* Span::SpanIsFullException::what() const throw() {
	return "Can't add another number, span is full";
}

const char* Span::SizeTooSmallException::what() const throw() {
	return "Size of span is less or equal to 1, no span to find";
}
