/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 13:19:29 by dpoveda-          #+#    #+#             */
/*   Updated: 2022/02/16 18:35:26 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

#include <iostream>

Cat::Cat() {
	this->type = "Cat";
	this->brain = new Brain();

	std::cout << "Cat: Default constructor" << std::endl;
}

Cat::Cat(const Cat& other) {
	this->brain = new Brain();
	*this = other;

	std::cout << "Cat: Copy constructor" << std::endl;
}

Cat::~Cat() {
	delete this->brain;

	std::cout << "Cat: Destructor" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
	this->Animal::operator=(other);

	//this->brain = other.brain; // shallow copy
	*this->brain = *other.brain; // deep copy

	std::cout << "Cat: Assignment operator" << std::endl;

	return *this;
}

void Cat::makeSound() const {
	std::cout << "Meow! Meow! Meow!" << std::endl;
}

Brain* Cat::getBrain() const {
	return this->brain;
}
