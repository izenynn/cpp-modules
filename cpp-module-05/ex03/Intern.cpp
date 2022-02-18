/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 03:14:02 by dpoveda-          #+#    #+#             */
/*   Updated: 2022/02/18 03:34:19 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {
	std::cout << "Intern created" << std::endl;
}

Intern::Intern(const Intern& other) {
	std::cout << "Copy of Intern created" << std::endl;
	*this = other;
}

Intern::~Intern() {
	std::cout << "Intern destroyed" << std::endl;
}

Intern& Intern::operator=(const Intern& other) {
	std::cout << "Intern assignment operator" << std::endl;
	if (this == &other) return *this;
	return *this;
}

Form* Intern::makeForm(std::string name, std::string target) {
	static const int kNForms = 3;
	t_forms forms[kNForms] = {
		{ "shrubbery creation", new ShrubberyCreationForm(target) },
		{ "robotomy request", new RobotomyRequestForm(target) },
		{ "presidential pardon", new PresidentialPardonForm(target) }
	};

	Form* ret = NULL;
	for (int i = 0; i < kNForms; i++) {
		if (forms[i].name == name) ret = forms[i].formClass;
		else delete forms[i].formClass;
	}

	if (ret != NULL) std::cout << "Intern creates form " << name << std::endl;
	else std::cout << "Intern was not able to find the form " << name << std::endl;

	return ret; // value will be NULL if no coincidence
}
