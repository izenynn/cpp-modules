/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 23:09:13 by dpoveda-          #+#    #+#             */
/*   Updated: 2022/02/20 14:53:15 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP_
# define FORM_HPP_

# include "Bureaucrat.hpp"

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat;

class Form {
	public:
		Form(const std::string& name, int signGrade, int executeGrade);
		Form(const Form& form);
		~Form();

		Form& operator=(const Form& other);

		void beSigned(const Bureaucrat& bureaucrat);

		const std::string& getName() const;
		bool getSigned() const;
		int getSignGrade() const;
		int getExecuteGrade() const;
	private:
		Form();

		bool _signed;

		const std::string _name;
		const int _signGrade;
		const int _executeGrade;
	public:
		class GradeTooHighException : public std::exception {
			public: const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public: const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const Form& instance);

#endif
