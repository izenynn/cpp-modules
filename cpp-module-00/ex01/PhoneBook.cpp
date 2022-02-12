/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 22:21:42 by dpoveda-          #+#    #+#             */
/*   Updated: 2022/02/12 13:21:29 by dpoveda-         ###   ########.fr       */
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
	if (this->newContactIndex > MAX_CONTACTS) this->newContactIndex = 0;

	Contact *tmp = new Contact;
	if (tmp->setInformation(this->newContactIndex + 1) == 0) {
		delete this->contacts[this->newContactIndex];
		this->contacts[this->newContactIndex] = tmp;
	}

	this->newContactIndex++;
	if (this->contactAmount < 8) this->contactAmount++;
	return;
}

void PhoneBook::searchContact() {
	if (this->contactAmount == 0) {
		std::cout << "Error: no contacts" << std::endl;
	}

	std::cout << "|-------------------------------------------|" << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "|-------------------------------------------|" << std::endl;
	for (int i = 0; i < this->contactAmount; i++)
		this->contacts[i]->tableDisplay();
	std::cout << "|-------------------------------------------|" << std::endl;
}
