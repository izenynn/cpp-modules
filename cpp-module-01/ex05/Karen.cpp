/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:14:42 by dpoveda-          #+#    #+#             */
/*   Updated: 2022/02/17 22:25:11 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

#include <iostream>

Karen::Karen() {}

Karen::~Karen() {}

void Karen::complain(std::string level) {
	static const int kLevels = 4;

	std::string complainLevels[kLevels] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};

	//void (Karen::*functions[4])() = {
	f functions[kLevels] = { // f is a typedef in Karen.hpp
		&Karen::debug,
		&Karen::info,
		&Karen::warning,
		&Karen::error
	};

	for (int i = 0; i < kLevels; i++) {
		if (complainLevels[i].compare(level) == 0) {
			(this->*(functions[i]))();
			return;
		}
	}
	std::cerr << "Error: Invalid complain level" << std::endl;
}

void Karen::debug() {
	std::cout
		<< "[ DEBUG ]\n"
		<< "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger."
		<< " I just love it!"
		<< std::endl;
}

void Karen::info() {
	std::cout
		<< "[ INFO ]\n"
		<< "I cannot believe adding extra bacon cost more money."
		<< " You don’t put enough!"
		<< " If you did I would not have to ask for it!"
		<< std::endl;
}

void Karen::warning() {
	std::cout
		<< "[ WARNING ]\n"
		<< "I think I deserve to have some extra bacon for free."
		<< " I’ve been coming here for years and you just started working here last month."
		<< std::endl;
}

void Karen::error() {
	std::cout
		<< "[ ERROR ]\n"
		<< "This is unacceptable, I want to speak to the manager now."
		<< std::endl;
}
