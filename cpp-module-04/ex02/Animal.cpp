/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 12:54:19 by dpoveda-          #+#    #+#             */
/*   Updated: 2022/02/16 23:26:51 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

#include <iostream>

Animal::Animal() {
	std::cout << "Animal: Default constructor" << std::endl;
}

Animal::Animal(const Animal& other) {
	*this = other;

	std::cout << "Animal: Copy constructor" << std::endl;
}

Animal::~Animal() {
	std::cout << "Animal: Destructor" << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
	this->type = other.type;

	std::cout << "Animal: Assignment operator" << std::endl;

	return *this;
}

const std::string& Animal::getType() const {
	return this->type;
}
