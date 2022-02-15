/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:14:42 by dpoveda-          #+#    #+#             */
/*   Updated: 2022/02/15 14:41:55 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

#include <iostream>

typedef void (Karen::*f)();

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

	f functions[kLevels] = {
		&Karen::debug,
		&Karen::info,
		&Karen::warning,
		&Karen::error
	};

	for (int i = 0; i < kLevels; i++) {
		if (complainLevels[i].compare(level)) {
			(this->*(functions[i]))();
		}
	}
}

void Karen::debug() {
	std::cout
		<< "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger."
		<< " I just love it!"
		<< std::endl;
}

void Karen::info() {
	std::cout
		<< "I cannot believe adding extra bacon cost more money."
		<< " You don’t put enough!"
		<< " If you did I would not have to ask for it!"
		<< std::endl;
}

void Karen::warning() {
	std::cout
		<< "I think I deserve to have some extra bacon for free."
		<< " I’ve been coming here for years and you just started working here last month."
		<< std::endl;
}

void Karen::error() {
	std::cout
		<< "This is unacceptable, I want to speak to the manager now."
		<< std::endl;
}
