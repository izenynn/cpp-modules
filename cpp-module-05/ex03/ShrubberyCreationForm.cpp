/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 01:35:50 by dpoveda-          #+#    #+#             */
/*   Updated: 2022/02/18 22:50:23 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
		: Form("shrubbery creation", "none", 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
		: Form("shrubbery creation", target, 145, 137) {
	std::cout << "Shrubbery Creation Form created" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
		: Form(other.getName(), other.getTarget(), other.getSignGrade(), other.getExecuteGrade()) {
	*this = other;
	std::cout << "Copy of Shrubbery Creation Form created" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "Shrubbery Creation Form destroyed" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	std::cout << "Shrubbery Creation Form assignment operator" << std::endl;
	if (this == &other) return *this;
	return *this;
}

void ShrubberyCreationForm::executeAction() const {
	std::ofstream out;

	out.open((this->getTarget() + "_shrubbery").c_str(), std::ofstream::out | std::ofstream::trunc);

	out << std::endl;
	out << "               ,@@@@@@@,                  " << std::endl;
	out << "       ,,,.   ,@@@@@@/@@,  .oo8888o.      " << std::endl;
	out << "    ,&&%&%&&%,@@@@@/@@@@@@,8888|88/8o     " << std::endl;
	out << "   ,%&|%&&%&&%,@@@|@@@/@@@88|88888/88'    " << std::endl;
	out << "   %&&%&%&/%&&%@@|@@/ /@@@88888|88888'    " << std::endl;
	out << "   %&&%/ %&&%&&@@| V /@@' `88|8 `/88'     " << std::endl;
	out << "   `&%| ` /%&'    |.|        | '|8'       " << std::endl;
	out << "       |o|        | |         | |         " << std::endl;
	out << "       |.|        | |         | |         " << std::endl;
	out << "    ||/ ._|//_/__/  ,|_//__||/.  |_//__/_ " << std::endl;
}
