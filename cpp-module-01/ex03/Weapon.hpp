/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:54:02 by dpoveda-          #+#    #+#             */
/*   Updated: 2022/02/15 11:04:31 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX03_WEAPON_HPP_
# define EX03_WEAPON_HPP_

#include <string>

class Weapon {
	public:
		Weapon(std::string type);
		~Weapon();

		void setType(std::string type);
		std::string getType() const;

	private:
		std::string _type;
};

#endif
