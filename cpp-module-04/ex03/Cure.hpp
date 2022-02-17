/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 02:48:42 by dpoveda-          #+#    #+#             */
/*   Updated: 2022/02/17 02:50:49 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP_
# define CURE_HPP_

# include "AMateria.hpp"

class Cure : public AMateria {
	public:
		Cure();
		Cure(const Cure& other);
		~Cure();

		Cure& operator=(const Cure& other);

		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif
