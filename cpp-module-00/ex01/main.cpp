/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 22:55:32 by dpoveda-          #+#    #+#             */
/*   Updated: 2022/02/11 23:39:47 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

#include <iostream>
#include <string>

int main() {
	std::string line;
	PhoneBook *phoneBook = new PhoneBook();

	while (1) {
		std::cout << "$> ";
		std::cin >> line;

		if (line == "SEARCH") {
			phoneBook->searchContact();
		} else if (line == "ADD") {
			phoneBook->addContact();
		} else if (line == "EXIT") {
			std::cout << "exit" << std::endl;
			break;
		} else if (std::cin.eof()) {
			std::cin.clear();
			break;
		}
	}

	delete phoneBook;
	return 0;
}
