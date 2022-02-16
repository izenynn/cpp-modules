/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 13:22:05 by dpoveda-          #+#    #+#             */
/*   Updated: 2022/02/16 13:36:25 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#include <iostream>

int main() {
	std::cout << "==========  GOOD  ANIMALS  ==========\n" << std::endl;

	Animal *animal = new Animal();
	Animal *dog = new Dog();
	Animal *cat = new Cat();

	std::cout << std::endl;

	std::cout << animal->getType() << std::endl;
	std::cout << dog->getType() << std::endl;
	std::cout << cat->getType() << std::endl;

	std::cout << std::endl;

	animal->makeSound();
	dog->makeSound();
	cat->makeSound();

	std::cout << std::endl;

	delete animal;
	delete dog;
	delete cat;

	/**********************************************************/

	std::cout << "\n========== WRONG ANIMALS ==========\n" << std::endl;

	WrongAnimal *wAnimal = new WrongAnimal();
	WrongAnimal *wCat = new WrongCat();

	std::cout << std::endl;

	std::cout << wAnimal->getType() << std::endl;
	std::cout << wCat->getType() << std::endl;

	std::cout << std::endl;

	wAnimal->makeSound();
	wCat->makeSound();

	std::cout << std::endl;

	delete wAnimal;
	delete wCat;
}
