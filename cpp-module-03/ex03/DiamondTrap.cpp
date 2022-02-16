/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 03:00:59 by dpoveda-          #+#    #+#             */
/*   Updated: 2022/02/16 03:30:29 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

#include <iostream>

DiamondTrap::DiamondTrap() {
	this->_name = "DiamondTrap";
	this->ClapTrap::_name = std::string("DiamondTrap").append("_clap_name");
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;

	std::cout << this->_name << " DiamondTrap created" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) {
	this->_name = name;
	this->ClapTrap::_name = name.append("_clap_name");
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;

	std::cout << this->_name << " DiamondTrap created" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) {
	*this = other;

	std::cout << this->_name << " DiamondTrap copy created" << std::endl;
}

DiamondTrap::~DiamondTrap() {
	std::cout << this->_name << " DiamondTrap destroyed" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
	this->ClapTrap::_name = other.ClapTrap::_name;
	this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;

	std::cout << this->_name << " DiamondTrap = " << other._name << std::endl;

	return *this;
}

void DiamondTrap::attack(const std::string& target) const {
	this->ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() const {
	std::cout << "I am " << this->_name << ", my ClapTrap name is " << this->ClapTrap::_name << std::endl;
}
