/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 13:18:01 by dpoveda-          #+#    #+#             */
/*   Updated: 2022/02/16 18:26:51 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP_
# define CAT_HPP_

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal {
	public:
		Cat();
		Cat(const Cat& other);
		~Cat();

		Cat& operator=(const Cat& other);

		void makeSound() const;

		Brain* getBrain() const;
	private:
		Brain* brain;
};

#endif
