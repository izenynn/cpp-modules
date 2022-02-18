/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 13:22:05 by dpoveda-          #+#    #+#             */
/*   Updated: 2022/02/18 12:37:24 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Human.hpp"

#include <iostream>

#define N_ANIMALS 10

int main() {
	std::cout << "==================   SHITY TEST   ==================\n" << std::endl;

	std::cout << "==================   BASIC TEST   ==================\n" << std::endl;

	Dog *dog = new Dog();
	Cat *cat = new Cat();
	Human *human = new Human();

	std::cout << std::endl;

	std::cout << dog->getType() << std::endl;
	std::cout << cat->getType() << std::endl;
	std::cout << human->getType() << std::endl;

	std::cout << std::endl;

	dog->makeSound();
	cat->makeSound();
	human->makeSound();

	std::cout << std::endl;

	// TEST DEEP COPY
	std::cout << "================== TEST DEEP COPY ==================\n" << std::endl;

	cat->getBrain()->ideas[0] = "I like potatoes";
	cat->getBrain()->ideas[1] = "I like ice cream";

	std::cout << "Cat ideas:" << std::endl;
	for (int i = 0; i < 2; i++) std::cout << "Idea: " << cat->getBrain()->ideas[i] << std::endl;
	std::cout << std::endl;

	std::cout << "Create cat2" << std::endl;
	Cat *cat2 = new Cat();
	std::cout << std::endl;

	std::cout << "Cat2 ideas" << std::endl;
	for (int i = 0; i < 2; i++) std::cout << "Idea: " << cat2->getBrain()->ideas[i] << std::endl;
	std::cout << std::endl;

	std::cout << "Cat2 = Cat" << std::endl;
	*cat2 = *cat;
	std::cout << std::endl;

	std::cout << "Cat ideas:" << std::endl;
	for (int i = 0; i < 2; i++) std::cout << "Idea: " << cat->getBrain()->ideas[i] << std::endl;
	std::cout << std::endl;

	std::cout << "Cat2 ideas" << std::endl;
	for (int i = 0; i < 2; i++) std::cout << "Idea: " << cat2->getBrain()->ideas[i] << std::endl;
	std::cout << std::endl;

	std::cout << "Cat ideas (now he hates ice cream)" << std::endl;
	cat->getBrain()->ideas[1] = "I hate ice cream";
	for (int i = 0; i < 2; i++) std::cout << "Idea: " << cat->getBrain()->ideas[i] << std::endl;
	std::cout << std::endl;

	std::cout << "Cat2 ideas" << std::endl;
	for (int i = 0; i < 2; i++) std::cout << "Idea: " << cat2->getBrain()->ideas[i] << std::endl;
	std::cout << std::endl;

	std::cout << "==================   CLEAN ALL    ==================\n" << std::endl;

	delete dog;
	delete cat;
	delete cat2;
	delete human;

	std::cout << std::endl;

	std::cout << "================ SUBJECT ARRAY TEST ================\n" << std::endl;

	Animal *animals[N_ANIMALS];

	for (int i = 0; i < N_ANIMALS; i++) {
		if (i < N_ANIMALS / 2) {
			animals[i] = new Cat();
		} else {
			animals[i] = new Dog();
		}
	}

	std::cout << std::endl;

	for (int i = 0; i < N_ANIMALS; i++) {
		animals[i]->makeSound();
	}

	std::cout << std::endl;

	for (int i = 0; i < N_ANIMALS; i++) {
		delete animals[i];
	}
}
