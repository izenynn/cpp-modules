/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 01:12:20 by dpoveda-          #+#    #+#             */
/*   Updated: 2022/02/20 01:17:01 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP_
# define EASYFIND_HPP_

# include <algorithm>

template<typename T>
typename T::iterator easyfind(T& container, int needle) {
	typename T::iterator it = std::find(container.begin(), container.end(), needle);
	return it; // it will be container.end() if needle can't be found
}

#endif
