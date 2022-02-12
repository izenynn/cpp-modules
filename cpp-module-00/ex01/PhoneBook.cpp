/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 22:21:42 by dpoveda-          #+#    #+#             */
/*   Updated: 2022/02/12 01:25:09 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
	for (int i = 0; i < MAX_CONTACTS; i++) {
		contacts[i] = new Contact;
	}
}

PhoneBook::~PhoneBook() {
	for (int i = 0; i < MAX_CONTACTS; i++) {
		delete contacts[i];
	}
}

void PhoneBook::addContact() {
	return;
}

void PhoneBook::searchContact() {
	return;
}
