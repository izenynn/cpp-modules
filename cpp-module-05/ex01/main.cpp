/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 12:47:06 by dpoveda-          #+#    #+#             */
/*   Updated: 2022/02/18 15:58:23 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

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

	Bureaucrat* poor = new Bureaucrat("Poor", 130);
	Bureaucrat* rich = new Bureaucrat("Rich", 15);
	Form* budgets = new Form("budgets", 30, 10);

	std::cout << std::endl;

	// Bureaucrat::signForm()
	std::cout << *budgets;
	std::cout << std::endl;
	try {
		poor->signForm(*budgets);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		rich->signForm(*budgets);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << *budgets;

	std::cout << std::endl;

	// Form::beSigned()
	try {
		budgets->beSigned(*poor);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	
	try {
		budgets->beSigned(*rich);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	delete poor;
	delete rich;
	delete budgets;

	return 0;
}
