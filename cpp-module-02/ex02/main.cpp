/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:15:44 by dpoveda-          #+#    #+#             */
/*   Updated: 2022/02/15 19:28:01 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <iostream>

int main( void ) {
	{
		Fixed a;
		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;

		std::cout << b << std::endl;

		std::cout << Fixed::max( a, b ) << std::endl;
	}
	// MY TESTS
	{
		std::cout << "\nMY TESTS:\n" << std::endl;
	
		Fixed a(4);
		Fixed const b(2);
	
		std::cout << "a: " << a << std::endl;
		std::cout << "b: " << b << std::endl;
	
		std::cout << "a++: " << a++ << std::endl;
		std::cout << "a: " << a << std::endl;
		std::cout << "++a: " << ++a << std::endl;
		std::cout << "a: " << a << std::endl;
	
		std::cout << "a + b: " << a + b << std::endl;
		std::cout << "b + a: " << b + a << std::endl;
	
		std::cout << "a - b: " << a - b << std::endl;
		std::cout << "b - a: " << b - a << std::endl;
	
		std::cout << "a * b: " << a * b << std::endl;
		std::cout << "b * a: " << b * a << std::endl;
	
		std::cout << "a / b: " << a / b << std::endl;
		std::cout << "b / a: " << b / a << std::endl;
	
		std::cout << "max(a, b): " << Fixed::max(a, b) << std::endl;
		std::cout << "max(b, a): " << Fixed::max(a, b) << std::endl;
	
		std::cout << "min(a, b): " << Fixed::min(a, b) << std::endl;
		std::cout << "min(b, a): " << Fixed::min(a, b) << std::endl;
	
		return 0;
	}
}
