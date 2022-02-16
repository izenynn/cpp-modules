/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 01:33:02 by dpoveda-          #+#    #+#             */
/*   Updated: 2022/02/16 03:31:43 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX03_SCAVTRAP_HPP_
# define EX03_SCAVTRAP_HPP_

#include "ClapTrap.hpp"

#include <string>

class ScavTrap : virtual public ClapTrap {
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap& other);
		virtual ~ScavTrap();

		ScavTrap& operator=(const ScavTrap& other);

		virtual void attack(const std::string& target) const;
		void guardGate();
	protected:
};

#endif
