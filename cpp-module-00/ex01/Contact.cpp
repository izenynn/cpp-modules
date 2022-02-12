/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 01:13:03 by dpoveda-          #+#    #+#             */
/*   Updated: 2022/02/12 13:20:58 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

#include <iomanip>

Contact::Contact() {}

Contact::~Contact() {}

int Contact::setInformation(int index) {
	this->index = index;
	std::cout << "add contact: name: ";
	std::cin >> this->fieldsInfo[0];
	std::cout << "add contact: last name: ";
	std::cin >> this->fieldsInfo[1];
	std::cout << "add contact: nickname: ";
	std::cin >> this->fieldsInfo[2];
	std::cout << "add contact: phone number: ";
	std::cin >> this->fieldsInfo[3];
	std::cout << "add contact: darkest secret: ";
	std::cin >> this->fieldsInfo[4];

	int length = 0;
	for (int i = 0; i < this->FIELDS_CNT; i++) {
		length += this->fieldsInfo[i].length();
	}
	if (length == 0) {
		std::cout << "Error: empty contact not added" << std::endl;
		return 1;
	}
	std::cout << "New contact added succesfully" << std::endl;
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
