/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:10:57 by dpoveda-          #+#    #+#             */
/*   Updated: 2022/02/15 20:30:39 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX00_FIXED_HPP_
# define EX00_FIXED_HPP_

#include <string>

class Fixed {
	public:
		Fixed();
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed& other);
		~Fixed();

		Fixed& operator=(const Fixed& other);

		bool operator>(const Fixed& other) const;
		bool operator<(const Fixed& other) const;
		bool operator>=(const Fixed& other) const;
		bool operator<=(const Fixed& other) const;
		bool operator==(const Fixed& other) const;
		bool operator!=(const Fixed& other) const;

		Fixed operator+(const Fixed& other) const;
		Fixed operator-(const Fixed& other) const;
		Fixed operator*(const Fixed& other) const;
		Fixed operator/(const Fixed& other) const;

		Fixed& operator++();
		Fixed& operator--();

		Fixed operator++(int);
		Fixed operator--(int);

		static Fixed& min(Fixed& lhs, Fixed& rhs);
		static Fixed& max(Fixed& lhs, Fixed& rhs);
		static const Fixed& min(const Fixed& lhs, const Fixed& rhs);
		static const Fixed& max(const Fixed& lhs, const Fixed& rhs);

		void setRawBits(const int rawBits);
		int getRawBits() const;
		int toInt() const;
		float toFloat() const;
	private:
		static const int _nFracBits = 8;
		int _rawBits;
};

std::ostream &operator<<(std::ostream &ostream, const Fixed& myClass);

#endif
