/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalar.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 23:47:49 by dpoveda-          #+#    #+#             */
/*   Updated: 2022/02/19 11:31:55 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Scalar.hpp"

#include <iostream>
#include <string>
#include <cstdlib>
#include <climits>

Scalar::Scalar() {}

Scalar::Scalar(const Scalar& other) { *this = other; }

Scalar& Scalar::operator=(const Scalar& other) { (void)other; return *this; }

void Scalar::convert(const std::string& literal) {
	std::string specialTypes[6] = {
		"-inff", "+inff", "nanf",
		"-inf", "+inf", "nan"
	};

	std::string toChar = "";
	int toInt = std::atoi(literal.c_str());
	float toFloat = std::atof(literal.c_str());
	double toDouble = 0;

	for (int i = 0; i < 6; ++i) {
		if (literal == specialTypes[i]) {
			toChar = "imposible"; break;
		}
	}
	if (toChar == "" && std::isprint(toInt)) {
		toChar = "'";
		toChar += static_cast<char>(toInt);
		toChar += "'";
	} else if (toChar == "") {
		toChar = "Non displayable";
	}

	toDouble = static_cast<double>(toFloat);

	// Display
	std::cout << "char: " << toChar << std::endl;
	if (toChar == "imposible") {
		std::cout << "int: imposible" << std::endl;
	} else {
		std::cout << "int: " << toInt << std::endl;
	}

	if (toChar == "imposible" && toFloat == 0) {
		std::cout << "float: imposible" << std::endl;
		std::cout << "double: imposible" << std::endl;
	} else {
		if (toChar != "imposible" && toFloat - static_cast<int>(toFloat) == 0) {
			std::cout << "float: " << toFloat << ".0f" << std::endl;
			std::cout << "double: " << toDouble << ".0" << std::endl;
		} else {
			std::cout << "float: " << toFloat << "f" << std::endl;
			std::cout << "double: " << toDouble << std::endl;
		}
	}
}
