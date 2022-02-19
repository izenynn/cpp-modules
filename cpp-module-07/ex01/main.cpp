/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 13:13:23 by dpoveda-          #+#    #+#             */
/*   Updated: 2022/02/19 13:22:45 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

#include <iostream>

template<typename T>
void debug(const T& var) {
	std::cout << var << std::endl;
}

template<typename T>
void increment(const T& var) {
	++(const_cast<T&>(var));
}

int main() {
	int arrInt[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	std::string arrString[4] = {"abc", "dfg", "hij", "klm"};

	std::cout << "INT ARRAY:\n" << std::endl;
	::iter(arrInt, 10, &debug);

	std::cout << "\nINT ARRAY (after increment):\n" << std::endl;
	::iter(arrInt, 10, &increment);
	::iter(arrInt, 10, &debug);

	std::cout << "\nSTRING ARRAY:\n" << std::endl;
	::iter(arrString, 4, &debug);

	return 0;
}
