/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 12:36:32 by dpoveda-          #+#    #+#             */
/*   Updated: 2022/02/16 18:27:11 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP_
# define ANIMAL_HPP_

#include "Brain.hpp"

#include <string>

class Animal {
	public:
		Animal();
		Animal(const Animal& other);
		virtual ~Animal();

		Animal& operator=(const Animal& other);

		virtual void makeSound() const;

		const std::string& getType() const;
	protected:
		std::string type;
};

#endif
