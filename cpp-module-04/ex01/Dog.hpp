/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 13:09:12 by dpoveda-          #+#    #+#             */
/*   Updated: 2022/02/16 18:26:41 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP_
# define DOG_HPP_

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal {
	public:
		Dog();
		Dog(const Dog& other);
		~Dog();

		Dog& operator=(const Dog& other);

		void makeSound() const;

		Brain* getBrain() const;
	private:
		Brain* brain;
};

#endif
