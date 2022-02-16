/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 01:33:02 by dpoveda-          #+#    #+#             */
/*   Updated: 2022/02/16 02:23:59 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX02_SCAVTRAP_HPP_
# define EX02_SCAVTRAP_HPP_

#include "ClapTrap.hpp"

#include <string>

class ScavTrap : public ClapTrap {
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap& other);
		~ScavTrap();

		ScavTrap& operator=(const ScavTrap& other);

		void attack(const std::string& target);
		void guardGate();
	private:
};

#endif
