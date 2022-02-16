/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 12:54:19 by dpoveda-          #+#    #+#             */
/*   Updated: 2022/02/16 13:39:58 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

#include <iostream>

WrongAnimal::WrongAnimal()
		: type("Animal") {
	std::cout << "WrongAnimal: Default constructor" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) {
	*this = other;

	std::cout << "WrongAnimal: Copy constructor" << std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal: Destructor" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
	this->type = other.type;

	std::cout << "WrongAnimal: Assignment operator" << std::endl;

	return *this;
}

void WrongAnimal::makeSound() const {
	std::cout << "\"Animal generic sound\"" << std::endl;
}

const std::string& WrongAnimal::getType() const {
	return this->type;
}
