/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 12:36:32 by dpoveda-          #+#    #+#             */
/*   Updated: 2022/02/16 23:26:39 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP_
# define ANIMAL_HPP_

#include "Brain.hpp"

#include <string>

class Animal {
	public:
		virtual ~Animal();

		Animal& operator=(const Animal& other);

		virtual void makeSound() const = 0;

		const std::string& getType() const;
	protected:
		Animal();
		Animal(const Animal& other);

		std::string type;
	private:
};

#endif
