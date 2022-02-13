/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 22:21:42 by dpoveda-          #+#    #+#             */
/*   Updated: 2022/02/13 13:15:48 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp" 
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
	} else {
		std::cout << "\nError: empty contact not added\n";
	}
	std::cout << std::endl;

	this->newContactIndex++;
	if (this->contactAmount < 8) this->contactAmount++;
	return;
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

	int id;
	std::cout << "\nEnter index of a contact to display all information, or anything else to go back\n"
		<< "Index: " << std::flush;
	if (!(std::cin >> id)) {
		std::cout << "\nInvalid index\n" << std::endl;
		return;
	} else if (id <= 0 || id > this->contactAmount) {
		std::cout << "\nInvalid index\n" << std::endl;
		return;
	}

	std::cout << std::endl;
	this->contacts[id - 1]->fullDisplay();
	std::cout << std::endl;
}
