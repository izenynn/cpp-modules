/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 01:13:03 by dpoveda-          #+#    #+#             */
/*   Updated: 2022/02/13 12:53:30 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

#include <iomanip>

Contact::Contact() {}

Contact::~Contact() {}

int Contact::setInformation(int index) {
	int id;

	this->index = index;
	id = -1;

	std::cout << "Add contact: Name: ";
	std::cin >> this->fieldsInfo[++id];
	if (std::cin.eof()) { std::cin.clear(); return 1; }

	std::cout << "Add contact: Last name: ";
	std::cin >> this->fieldsInfo[++id];
	if (std::cin.eof()) { std::cin.clear(); return 1; }

	std::cout << "Add contact: Nickname: ";
	std::cin >> this->fieldsInfo[++id];
	if (std::cin.eof()) { std::cin.clear(); return 1; }

	std::cout << "Add contact: Phone number: ";
	std::cin >> this->fieldsInfo[++id];
	if (std::cin.eof()) { std::cin.clear(); return 1; }

	std::cout << "Add contact: Darkest secret: ";
	std::cin >> this->fieldsInfo[++id];
	if (std::cin.eof()) { std::cin.clear(); return 1; }

	int length = 0;
	for (int i = 0; i < this->FIELDS_CNT; i++) {
		length += this->fieldsInfo[i].length();
	}
	if (length == 0) return 1;
	return 0;
}

void Contact::tableDisplay() {
	std::cout << "|" << std::right << std::setw(10) << this->index;

	for (int i = 0; i < 3; i++) {
		std::cout << "|";
		if (this->fieldsInfo[i].length() > 10) {
			std::cout << this->fieldsInfo[i].substr(0, 9) << ".";
		} else {
			std::cout << std::right << std::setw(10) << this->fieldsInfo[i];
		}
	}
	std::cout << "|" << std::endl;
}

void Contact::fullDisplay() {
	int id;

	std::cout << "Information of contact #" << this->index << "\n\n";

	id = -1;
	std::cout << "Name:           " << this->fieldsInfo[++id] << "\n";
	std::cout << "Last name:      " << this->fieldsInfo[++id] << "\n";
	std::cout << "Nickname:       " << this->fieldsInfo[++id] << "\n";
	std::cout << "Phone number:   " << this->fieldsInfo[++id] << "\n";
	std::cout << "Darkest secret: " << this->fieldsInfo[++id] << std::endl;
}
