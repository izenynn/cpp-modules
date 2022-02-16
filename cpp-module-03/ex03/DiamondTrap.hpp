/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 02:50:32 by dpoveda-          #+#    #+#             */
/*   Updated: 2022/02/16 03:33:09 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX03_DIAMONDTRAP_HPP_
# define EX03_DIAMONDTRAP_HPP_

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {
	public:
		DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap& other);
		~DiamondTrap();

		DiamondTrap& operator=(const DiamondTrap& other);

		void attack(const std::string& target) const;
		void whoAmI() const;
	private:
		std::string _name;
};

#endif
