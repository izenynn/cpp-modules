/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 22:55:32 by dpoveda-          #+#    #+#             */
/*   Updated: 2022/02/13 20:47:37 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

#include <iostream>
#include <string>
#include <csignal>
#include <climits>

int main() {
	std::string line;
	PhoneBook *phoneBook = new PhoneBook();

	while (std::cout << "$> ", std::getline(std::cin, line)) {
		if (line == "SEARCH") {
			phoneBook->searchContact();
		} else if (line == "ADD") {
			phoneBook->addContact();
		} else if (line == "EXIT") {
			std::cout << "exit" << std::endl;
			break;
		} else if (std::cin.eof()) {
			break;
		}
		std::cin.clear();
	}
	std::cin.clear();

	delete phoneBook;
	return 0;
}
