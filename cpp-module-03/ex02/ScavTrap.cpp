/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 01:32:46 by dpoveda-          #+#    #+#             */
/*   Updated: 2022/02/16 03:12:42 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

#include <iostream>

ScavTrap::ScavTrap() {
	this->_name = "ScavTrap";
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_hitPoints = 20;

	std::cout << this->_name << " ScavTrap created" << std::endl;
}

ScavTrap::ScavTrap(std::string name) {
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_hitPoints = 20;

	std::cout << this->_name << " ScavTrap created" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) {
	*this = other;

	std::cout << this->_name << " ScavTrap copy created" << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << this->_name << " ScavTrap destroyed" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
	this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;

	std::cout << this->_name << " ScavTrap = " << other._name << std::endl;

	return *this;
}

void ScavTrap::attack(const std::string& target) {
	if (this->_hitPoints == 0) {
		std::cout << this->_name << " ScavTrap can't attack because is dead" << std::endl;
		return;
	}

	std::cout
		<< this->_name << " ScavTrap attack " << target
		<< ", causing " << this->_attackDamage << " damage"
		<< std::endl;
}

void ScavTrap::guardGate() {
	if (this->_hitPoints == 0) {
		std::cout << this->_name << " ScavTrap can't guard gate because is dead" << std::endl;
		return;
	}

	std::cout << this->_name << " ScavTrap is now guarding the gate" << std::endl;
}
