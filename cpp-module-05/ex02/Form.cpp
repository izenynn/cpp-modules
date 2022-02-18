/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 23:13:03 by dpoveda-          #+#    #+#             */
/*   Updated: 2022/02/18 02:56:21 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

namespace {
	void checkGrade(int grade) {
		if (grade < Bureaucrat::kMaxGrade) throw Bureaucrat::GradeTooHighException();
		if (grade > Bureaucrat::kMinGrade) throw Bureaucrat::GradeTooLowException();
	}
}

Form::Form()
		: _signed(false),
		  _name("form"),
		  _target("none"),
		  _signGrade(150),
		  _executeGrade(150) {}

Form::Form(const std::string& name, const std::string& target, int signGrade, int executeGrade)
		: _signed(false),
		  _name(name),
		  _target(target),
		  _signGrade(signGrade),
		  _executeGrade(executeGrade) {
	checkGrade(signGrade);
	checkGrade(executeGrade);
	std::cout << "Form created" << std::endl;
}

Form::Form(const Form& other)
		: _signed(other._signed),
		  _name(other._name),
		  _target(other._target),
		  _signGrade(other._signGrade),
		  _executeGrade(other._executeGrade) {
	std::cout << "Copy of Form created" << std::endl;
}

Form::~Form() {
	std::cout << "Form destroyed" << std::endl;
}

Form& Form::operator=(const Form& other) {
	std::cout << "Form assignment operator" << std::endl;
	if (this == &other) return *this;
	return *this;
}

const std::string& Form::getName() const {
	return this->_name;
}

const std::string& Form::getTarget() const {
	return this->_target;
}

bool Form::getSigned() const {
	return this->_signed;
}

int Form::getSignGrade() const {
	return this->_signGrade;
}

int Form::getExecuteGrade() const {
	return this->_executeGrade;
}

void Form::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() <= this->_signGrade) {
		this->_signed = true;
		std::cout << bureaucrat.getName() << " has signed " << this->_name << std::endl;
	} else {
		std::cout << bureaucrat.getName() << " can't sign " << this->_name << std::endl;
		throw Form::GradeTooLowException();
	}
}

void Form::beExecuted(const Bureaucrat& bureaucrat) const {
	if (this->_signed == false) {
		std::cout << bureaucrat.getName() << " can't execute " << this->_name << std::endl;
		throw Form::NotSigned();
	}
	if (bureaucrat.getGrade() > this->_executeGrade) {
		std::cout << bureaucrat.getName() << " can't execute " << this->_name << std::endl;
		throw Form::GradeTooLowException();
	}

	std::cout << bureaucrat.getName() << " has executed " << this->_name << std::endl;
	this->executeAction();
}

const char* Form::GradeTooHighException::what() const throw() {
	return "Exception: grade too high";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "Exception: grade too low";
}

const char* Form::NotSigned::what() const throw() {
	return "Exception: form is not signed so it can't be executed";
}

std::ostream& operator<<(std::ostream& os, const Form& instance) {
	os << "Form " << instance.getName()
		<< ", status: " << (instance.getSigned() ? "signed" : "not signed")
		<< ", sign grade: " << instance.getSignGrade()
		<< ", execute grade: " << instance.getExecuteGrade();
	return os;
}
