/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 00:22:05 by dpoveda-          #+#    #+#             */
/*   Updated: 2022/02/16 03:00:37 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

#include <iostream>

ClapTrap::ClapTrap()
	: _name("ScavTrap")
	, _hitPoints(10)
	, _energyPoints(10)
	, _attackDamage(0) {
	std::cout << this->_name << " ClapTrap created" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
	: _name(name)
	, _hitPoints(10)
	, _energyPoints(10)
	, _attackDamage(0) {
	std::cout << this->_name << " ClapTrap created" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
	*this = other;

	std::cout << this->_name << " ClapTrap copy created" << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << this->_name << " ClapTrap destroyed" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;

	std::cout << this->_name << " ClapTrap = " << other._name << std::endl;

	return *this;
}

void ClapTrap::attack(const std::string &target) const {
	if (this->_hitPoints == 0) {
		std::cout << this->_name << " ClapTrap can't attack because is dead" << std::endl;
		return;
	}

	std::cout
		<< this->_name << " ClapTrap attack " << target
		<< ", causing " << this->_attackDamage << " damage"
		<< std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->_hitPoints == 0) {
		std::cout << this->_name << " ClapTrap can't take damage because is dead" << std::endl;
		return;
	}

	if (amount > this->_hitPoints) {
		amount = this->_hitPoints;
	}

	this->_hitPoints -= amount;

	std::cout << this->_name << " ClapTrap has taken " << amount << " damage" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->_hitPoints == 0) {
		std::cout << this->_name << " ClapTrap can't be repaired because is dead" << std::endl;
		return;
	}

	this->_hitPoints += amount;
	std::cout << this->_name << " ClapTrap has repaired " << amount << " hit points" << std::endl;
}
