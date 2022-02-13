/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 22:21:42 by dpoveda-          #+#    #+#             */
/*   Updated: 2022/02/13 23:46:20 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp" 

#include <sstream>

PhoneBook::PhoneBook() {
	this->newContactIndex = 0;
	this->contactAmount = 0;
	for (int i = 0; i < MAX_CONTACTS; i++) {
		this->contacts[i] = new Contact;
	}
}

PhoneBook::~PhoneBook() {
	for (int i = 0; i < MAX_CONTACTS; i++) {
		delete this->contacts[i];
	}
}

void PhoneBook::addContact() {
	if (this->newContactIndex >= this->MAX_CONTACTS) this->newContactIndex = 0;

	std::cout << std::endl;
	Contact *tmp = new Contact;
	if (tmp->setInformation(this->newContactIndex + 1) == 0) {
		delete this->contacts[this->newContactIndex];
		this->contacts[this->newContactIndex] = tmp;
		std::cout << "\nNew contact added succesfully\n";

		this->newContactIndex++;
		if (this->contactAmount < 8) this->contactAmount++;
	} else {
		delete tmp;
	}
	std::cout << std::endl;
	return;
}

namespace {
	bool stringIsalpha(const std::string &str) {
		for (std::string::const_iterator it = str.begin(); it != str.end(); it++) {
			if (std::isalpha(*it)) return true;
		}
		return false;
	}
}

void PhoneBook::searchContact() {
	if (this->contactAmount == 0) {
		std::cout << "\nError: no contacts\n" << std::endl;
		return;
	}

	std::cout << "\n"
	<< "|-------------------------------------------|\n"
	<< "|     Index|First Name| Last Name|  Nickname|\n"
	<< "|-------------------------------------------|\n";
	for (int i = 0; i < this->contactAmount; i++)
		this->contacts[i]->tableDisplay();
	std::cout << "|-------------------------------------------|" << std::endl;

	bool run = true;
	int id;
	std::cout << "\nEnter index of a contact to display all information, or type \"EXIT\" to return\n";
	do {
		std::string str;
		std::cout << "Index: " << std::flush;
		std::getline(std::cin, str);
		if (str == "EXIT") {
			std::cout << std::endl;
			return;
		} else if (stringIsalpha(str)) {
			std::cout << "\nInvalid index: value is not a number" << std::endl;
		} else {
			std::istringstream(str) >> id;
			if (id <= 0 || id > this->contactAmount) {
				std::cout << "\nInvalid index: out of range" << std::endl;
			} else {
				run = false;
			}
		}
	} while (run);

	std::cout << std::endl;
	this->contacts[id - 1]->fullDisplay();
	std::cout << std::endl;
}
