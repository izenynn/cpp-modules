/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 00:22:11 by dpoveda-          #+#    #+#             */
/*   Updated: 2022/02/16 03:32:43 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX03_CLAPTRAP_HPP_
# define EX03_CLAPTRAP_HPP_

#include <string>

class ClapTrap {
	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& other);
		virtual ~ClapTrap();

		ClapTrap& operator=(const ClapTrap& other);

		virtual void attack(const std::string& target) const;
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
	protected:
		std::string _name;
		unsigned int _hitPoints;
		unsigned int _energyPoints;
		unsigned int _attackDamage;
};

#endif
