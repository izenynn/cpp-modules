/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 13:19:29 by dpoveda-          #+#    #+#             */
/*   Updated: 2022/02/16 13:40:27 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

#include <iostream>

WrongCat::WrongCat() {
	this->type = "Cat";

	std::cout << "WrongCat: Default constructor" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) {
	*this = other;

	std::cout << "WrongCat: Copy constructor" << std::endl;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat: Destructor" << std::endl;
}

void WrongCat::makeSound() const {
	std::cout << "Meow! Meow! Meow!" << std::endl;
}
