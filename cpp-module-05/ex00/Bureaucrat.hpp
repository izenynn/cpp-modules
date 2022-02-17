/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 12:12:36 by dpoveda-          #+#    #+#             */
/*   Updated: 2022/02/17 12:46:01 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP_
# define BUREAUCRAT_HPP_

# include <string>
# include <iostream>
# include <exception>

class Bureaucrat {
	public:
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat &other);
		~Bureaucrat();

		Bureaucrat& operator=(const Bureaucrat& other);

		static const int kMinGrade = 150;
		static const int kMaxGrade = 1;

		const std::string& getName() const;
		int getGrade() const;

		void increment();
		void increment(int quantity);
		void decrement();
		void decrement(int quantity);
	private:
		Bureaucrat();

		std::string _name;
		int _grade;
	public:
		class GradeTooHighException : public std::exception {
			const char* what() const throw () {
				return "Grade too high, max value";
			}
		};
		class GradeTooLowException : public std::exception {
			const char* what() const throw() {
				return "Grade too high, max value";
			}
		};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& instance);

#endif