/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 00:44:55 by dpoveda-          #+#    #+#             */
/*   Updated: 2022/02/17 02:19:39 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP_
# define CHARACTER_HPP_

# include "ICharacter.hpp"

# include <string>

class Character : public ICharacter {
	public:
		Character(const std::string& name);
		Character(const Character& other);
		~Character();

		Character& operator=(const Character& other);

		const std::string& getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
	private:
		Character();

		static const int kInventorySize = 4;

		std::string _name;
		AMateria* _inventory[Character::kInventorySize];
		int _nEquiped;
};

#endif
