/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalar.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 23:47:47 by dpoveda-          #+#    #+#             */
/*   Updated: 2022/02/19 10:56:34 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_HPP_
# define SCALAR_HPP_

# include <string>

class Scalar {
	public:
		~Scalar();

		static void convert(const std::string& literal);
	private:
		Scalar();
		Scalar(const Scalar& other);
		Scalar& operator=(const Scalar& other);

		//static bool tryChar(const std::string& literal);
		//static bool tryInt(const std::string& literal);
		//static bool tryFloat(const std::string& literal);
		//static bool tryDouble(const std::string& literal);
};

#endif
