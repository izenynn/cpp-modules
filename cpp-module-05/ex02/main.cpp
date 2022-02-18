/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 12:47:06 by dpoveda-          #+#    #+#             */
/*   Updated: 2022/02/18 03:04:38 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include <iostream>

int main() {
	std::cout << "\n========== BUREAUCRAT ==========\n" << std::endl;

	Bureaucrat *bob = new Bureaucrat("Bob", 2);
	try {
		std::cout << "1: " << *bob << std::endl;
		bob->increment();
		std::cout << "2: " << *bob << std::endl;
		bob->increment();
		std::cout << "3: " << *bob << std::endl;
		bob->increment();
		std::cout << "4: " << *bob << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	delete bob;

	std::cout << std::endl;

	Bureaucrat *jim = new Bureaucrat("Jim", 10);
	try {
		std::cout << "1: " << *jim << std::endl;
		jim->increment();
		std::cout << "2: " << *jim << std::endl;
		jim->increment();
		std::cout << "3: " << *jim << std::endl;
		jim->increment();
		std::cout << "4: " << *jim << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	delete jim;

	std::cout << std::endl;

	Bureaucrat *luffy = new Bureaucrat("Luffy", 145);
	try {
		std::cout << "1: " << *luffy << std::endl;
		luffy->decrement();
		std::cout << "2: " << *luffy << std::endl;
		luffy->decrement();
		std::cout << "3: " << *luffy << std::endl;
		luffy->decrement();
		std::cout << "4: " << *luffy << std::endl;
		luffy->decrement();
		std::cout << "5: " << *luffy << std::endl;
		luffy->decrement();
		std::cout << "6: " << *luffy << std::endl;
		luffy->decrement();
		std::cout << "7: " << *luffy << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	delete luffy;

	std::cout << std::endl;

	try {
		Bureaucrat yuno("Yuno", 151);
		std::cout << "HELLO WORLD!!!" << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	try {
		Bureaucrat yuno("Yuno", -1);
		std::cout << "HELLO WORLD!!!" << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n========== FORM ==========\n" << std::endl;

	Bureaucrat* b150 = new Bureaucrat("b150", 150);
	Bureaucrat* b140 = new Bureaucrat("b140", 140);
	Bureaucrat* b100 = new Bureaucrat("b100", 100);
	Bureaucrat* b1 = new Bureaucrat("b1", 1);

	std::cout << std::endl;

	std::cout << *b150 << std::endl;
	std::cout << *b140 << std::endl;
	std::cout << *b100 << std::endl;
	std::cout << *b1 << std::endl;

	std::cout << std::endl;

	ShrubberyCreationForm *garden = new ShrubberyCreationForm("garden");
	RobotomyRequestForm *neighbor = new RobotomyRequestForm("neighbor");
	PresidentialPardonForm *rick = new PresidentialPardonForm("rick");

	std::cout << std::endl;

	std::cout << *garden << std::endl;
	std::cout << *neighbor << std::endl;
	std::cout << *rick << std::endl;

	std::cout << std::endl;

	// ShrubberyCreationForm
	try { // try to execute before sign
		b100->executeForm(*garden);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	try { // try to sign with low level
		b150->signForm(*garden);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	try { // sign
		b140->signForm(*garden);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << *garden << std::endl; // display update info
	try { // try to execute with low level
		b140->executeForm(*garden);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	try { // execute
		b100->executeForm(*garden);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	// RobotomyRequestForm (execute main multiple times to check randomizer is working)
	try { // sign
		b1->signForm(*neighbor);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	try { // execute
		b1->executeForm(*neighbor);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	// PresidentialPardonForm
	try { // sign
		b1->signForm(*rick);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	try { // execute
		b1->executeForm(*rick);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	delete garden;
	delete neighbor;
	delete rick;

	std::cout << std::endl;

	delete b150;
	delete b140;
	delete b100;
	delete b1;

	return 0;
}
