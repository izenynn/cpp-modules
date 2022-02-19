/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 13:10:32 by dpoveda-          #+#    #+#             */
/*   Updated: 2022/02/19 13:12:38 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP_
# define ITER_HPP_

# include <cstddef>

template<typename T>
void iter(T* arr, std::size_t lenght, void (*f)(const T&)) {
	for (std::size_t i = 0; i < lenght; ++i) {
		f(arr[i]);
	}
}

#endif
