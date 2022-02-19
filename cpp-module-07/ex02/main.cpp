/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 13:25:39 by dpoveda-          #+#    #+#             */
/*   Updated: 2022/02/19 14:56:12 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

#include <iostream>
#include <string>

int main() {
	Array<int> arrInt(5);
	Array<char> arrChar(5);
	Array<std::string> arrString(3);

	arrInt[0] = 10;
	arrInt[1] = 11;
	arrInt[2] = 12;
	arrInt[3] = 13;
	arrInt[4] = 14;

	arrChar[0] = 'a';
	arrChar[1] = 'b';
	arrChar[2] = 'c';
	arrChar[3] = 'd';
	arrChar[4] = 'e';

	arrString[0] = "hello";
	arrString[1] = "world";
	arrString[2] = ":D";

	std::cout << "\n========== BASIC TESTS ==========\n" << std::endl;

	std::cout << "INT ARRAY:" << std::endl;
	std::cout << "size: " << arrInt.size() << '\n' << std::endl;
	for (std::size_t i = 0; i < arrInt.size(); ++i) {
		std::cout << arrInt[i] << std::endl;
	}

	std::cout << "\nCHAR ARRAY:" << std::endl;
	std::cout << "size: " << arrChar.size() << '\n' << std::endl;
	for (std::size_t i = 0; i < arrChar.size(); ++i) {
		std::cout << arrChar[i] << std::endl;
	}

	std::cout << "\nSTRING ARRAY:" << std::endl;
	std::cout << "size: " << arrString.size() << '\n' << std::endl;
	for (std::size_t i = 0; i < arrString.size(); ++i) {
		std::cout << arrString[i] << std::endl;
	}

	std::cout << "\n========== EXCEPTIONS ==========\n" << std::endl;

	try {
		std::cout << arrString[1] << std::endl;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		std::cout << arrString[-1] << std::endl;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		std::cout << arrString[5] << std::endl;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n========== COPY CONSTRUCTOR (DEEP) ==========\n" << std::endl;

	Array<std::string> copy(arrString);

	std::cout << "\nSTRING ARRAY:" << std::endl;
	std::cout << "size: " << arrString.size() << '\n' << std::endl;
	for (std::size_t i = 0; i < arrString.size(); ++i) {
		std::cout << arrString[i] << std::endl;
	}
	std::cout << "\nCOPY ARRAY:" << std::endl;
	std::cout << "size: " << copy.size() << '\n' << std::endl;
	for (std::size_t i = 0; i < copy.size(); ++i) {
		std::cout << copy[i] << std::endl;
	}

	std::cout << "\n----- change string array[2] to \":(\"-----" << std::endl;
	arrString[2] = ":(";

	std::cout << "\nSTRING ARRAY:" << std::endl;
	std::cout << "size: " << arrString.size() << '\n' << std::endl;
	for (std::size_t i = 0; i < arrString.size(); ++i) {
		std::cout << arrString[i] << std::endl;
	}
	std::cout << "\nCOPY ARRAY:" << std::endl;
	std::cout << "size: " << copy.size() << '\n' << std::endl;
	for (std::size_t i = 0; i < copy.size(); ++i) {
		std::cout << copy[i] << std::endl;
	}

	std::cout << "\n========== ASSIGNMENT OPERATOR (DEEP) ==========\n" << std::endl;

	Array<std::string> copy2(5);

	std::cout << "\nSTRING ARRAY:" << std::endl;
	std::cout << "size: " << arrString.size() << '\n' << std::endl;
	for (std::size_t i = 0; i < arrString.size(); ++i) {
		std::cout << arrString[i] << std::endl;
	}
	std::cout << "\nCOPY ARRAY:" << std::endl;
	std::cout << "size: " << copy2.size() << '\n' << std::endl;
	for (std::size_t i = 0; i < copy2.size(); ++i) {
		std::cout << copy2[i] << std::endl;
	}

	std::cout << "\n----- copy = string array -----" << std::endl;
	copy2 = arrString;

	std::cout << "\nSTRING ARRAY:" << std::endl;
	std::cout << "size: " << arrString.size() << '\n' << std::endl;
	for (std::size_t i = 0; i < arrString.size(); ++i) {
		std::cout << arrString[i] << std::endl;
	}
	std::cout << "\nCOPY ARRAY:" << std::endl;
	std::cout << "size: " << copy2.size() << '\n' << std::endl;
	for (std::size_t i = 0; i < copy2.size(); ++i) {
		std::cout << copy2[i] << std::endl;
	}

	std::cout << "\n----- change string array[2] to \":D\"-----" << std::endl;
	arrString[2] = ":D";

	std::cout << "\nSTRING ARRAY:" << std::endl;
	std::cout << "size: " << arrString.size() << '\n' << std::endl;
	for (std::size_t i = 0; i < arrString.size(); ++i) {
		std::cout << arrString[i] << std::endl;
	}
	std::cout << "\nCOPY ARRAY:" << std::endl;
	std::cout << "size: " << copy2.size() << '\n' << std::endl;
	for (std::size_t i = 0; i < copy2.size(); ++i) {
		std::cout << copy2[i] << std::endl;
	}

	return 0;
}
