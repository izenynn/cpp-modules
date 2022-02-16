/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 13:13:19 by dpoveda-          #+#    #+#             */
/*   Updated: 2022/02/16 18:33:58 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

#include <iostream>

Dog::Dog() {
	this->type = "Dog";
	this->brain = new Brain();

	std::cout << "Dog: Default constructor" << std::endl;
}

Dog::Dog(const Dog& other) {
	this->brain = new Brain();
	*this = other;

	std::cout << "Dog: Copy constructor" << std::endl;
}

Dog::~Dog() {
	delete this->brain;

	std::cout << "Dog: Destructor" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
	this->Animal::operator=(other);

	//this->brain = other.brain; // shallow copy
	*this->brain = *other.brain; // deep copy

	std::cout << "Dog: Assignment operator" << std::endl;

	return *this;
}

void Dog::makeSound() const {
	std::cout << "Woof! Woof! Woof!" << std::endl;
}

Brain* Dog::getBrain() const {
	return this->brain;
}
