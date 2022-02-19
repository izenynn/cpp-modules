/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 12:56:05 by dpoveda-          #+#    #+#             */
/*   Updated: 2022/02/19 12:58:27 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP_
# define WHATEVER_HPP_

template<typename T>
void swap(T& a, T& b) {
	T tmp;

	tmp = a;
	a = b;
	b = tmp;
}

template<typename T>
const T& max(const T& x, const T& y) {
	if (x > y) return x;
	return y;
}

template<typename T>
const T& min(const T& x, const T& y) {
	if (x < y) return x;
	return y;
}

#endif
