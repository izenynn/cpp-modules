/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 01:13:03 by dpoveda-          #+#    #+#             */
/*   Updated: 2022/02/13 23:50:50 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

#include <iomanip>
#include <climits>

Contact::Contact() {}

Contact::~Contact() {}

namespace {
	bool stringIsalnum(const std::string &str) {
		for (std::string::const_iterator it = str.begin(); it != str.end(); it++) {
			if (std::isalnum(*it)) return true;
		}
		return false;
	}
}

int Contact::setInformation(int index) {
	int id;

	this->index = index;
	id = 0;

	do {
	std::cout << "Add contact: Name (required): ";
	std::getline(std::cin, this->fieldsInfo[id]);

	if (std::cin.eof()) { std::cin.clear(); return 1; }
	} while (this->fieldsInfo[id].empty() || !stringIsalnum(this->fieldsInfo[id]));

	std::cout << "Add contact: Last name: ";
	std::getline(std::cin, this->fieldsInfo[++id]);
	if (std::cin.eof()) { std::cin.clear(); return 1; }

	std::cout << "Add contact: Nickname: ";
	std::getline(std::cin, this->fieldsInfo[++id]);
	if (std::cin.eof()) { std::cin.clear(); return 1; }

	std::cout << "Add contact: Phone number: ";
	std::getline(std::cin, this->fieldsInfo[++id]);
	if (std::cin.eof()) { std::cin.clear(); return 1; }

	std::cout << "Add contact: Darkest secret: ";
	std::getline(std::cin, this->fieldsInfo[++id]);
	if (std::cin.eof()) { std::cin.clear(); return 1; }

	if (this->fieldsInfo[0].length() == 0) {
		std::cout << "\nError: name is required\n";
		return 1;
	}
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

	std::cout << "===== Information of contact #" << this->index << " =====\n\n";

	id = -1;
	std::cout << "# Name:           " << this->fieldsInfo[++id] << "\n";
	std::cout << "# Last name:      " << this->fieldsInfo[++id] << "\n";
	std::cout << "# Nickname:       " << this->fieldsInfo[++id] << "\n";
	std::cout << "# Phone number:   " << this->fieldsInfo[++id] << "\n";
	std::cout << "# Darkest secret: " << this->fieldsInfo[++id] << std::endl;
}
