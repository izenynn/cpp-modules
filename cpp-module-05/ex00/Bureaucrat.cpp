/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 12:27:42 by dpoveda-          #+#    #+#             */
/*   Updated: 2022/02/20 18:03:57 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

namespace {
	void checkGrade(int grade) {
		if (grade < Bureaucrat::kMaxGrade) throw Bureaucrat::GradeTooHighException();
		if (grade > Bureaucrat::kMinGrade) throw Bureaucrat::GradeTooLowException();
	}
}

Bureaucrat::Bureaucrat() {}

Bureaucrat::Bureaucrat(const std::string& name, int grade)
		: _name(name),
		  _grade(grade) {
	checkGrade(grade);
	std::cout << "Bureaucrat created" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
		: _name(other._name) {
	*this = other;
	std::cout << "Copy of bureaucrat created" << std::endl;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat destroyed" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	this->_grade = other._grade;
	std::cout << "Assignment operator" << std::endl;
	return *this;
}

const std::string& Bureaucrat::getName() const {
	return this->_name;
}

int Bureaucrat::getGrade() const {
	return this->_grade;
}

void Bureaucrat::increment() {
	std::cout << "Incrementing grade by 1" << std::endl;
	checkGrade(this->_grade - 1);
	--this->_grade;
}

void Bureaucrat::increment(int quantity) {
	std::cout << "Incrementing grade by " << quantity << std::endl;
	checkGrade(this->_grade - quantity);
	this->_grade -= quantity;
}

void Bureaucrat::decrement() {
	std::cout << "Decrementing grade by 1" << std::endl;
	checkGrade(this->_grade + 1);
	++this->_grade;
}

void Bureaucrat::decrement(int quantity) {
	std::cout << "Decrementing grade by " << quantity << std::endl;
	checkGrade(this->_grade + quantity);
	this->_grade += quantity;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Exception: grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Exception: grade too low";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& instance) {
	os << instance.getName() << ", bureaucrat grade " << instance.getGrade();
	return os;
}
