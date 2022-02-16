#include "Human.hpp"

#include <iostream>

Human::Human() {
	this->type = "Human";
	std::cout << "Human: Default constructor" << std::endl;
}

Human::Human(const Human& other) {
	*this = other;

	std::cout << "Human: Copy constructor" << std::endl;
}

Human::~Human() {
	std::cout << "Human: Destructor" << std::endl;
}

Human& Human::operator=(const Human& other) {
	this->Animal::operator=(other);

	return *this;
}

void Human::makeSound() const {
	std::cout << "Quiero comer" << std::endl;
}
