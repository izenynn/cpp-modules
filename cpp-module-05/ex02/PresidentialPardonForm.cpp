/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 02:23:27 by dpoveda-          #+#    #+#             */
/*   Updated: 2022/02/18 02:28:26 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
		: Form("presidential pardon", "none", 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
		: Form("presidential pardon", target, 25, 5) {
	std::cout << "Presidential Pardon Form created" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
		: Form(other.getName(), other.getTarget(), other.getSignGrade(), other.getExecuteGrade()) {
	*this = other;
	std::cout << "Copy of Presidential Pardon Form created" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "Presidential Pardon Form destroyed" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	std::cout << "Presidential Pardon Form assignment operator" << std::endl;
	if (this == &other) return *this;
	return *this;
}

void PresidentialPardonForm::executeAction() const {
	std::cout << this->getTarget() << " has been pardoned by Zafod Beeblebrox" << std::endl;
}
