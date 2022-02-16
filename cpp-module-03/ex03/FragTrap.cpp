/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 02:24:32 by dpoveda-          #+#    #+#             */
/*   Updated: 2022/02/16 03:12:26 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

#include <iostream>

FragTrap::FragTrap() {
	this->_name = "FragTrap";
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;

	std::cout << this->_name << " FragTrap created" << std::endl;
}

FragTrap::FragTrap(std::string name) {
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;

	std::cout << this->_name << " FragTrap created" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) {
	*this = other;

	std::cout << this->_name << " FragTrap copy created" << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << this->_name << " FragTrap destroyed" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
	this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;

	std::cout << this->_name << " FragTrap = " << other._name << std::endl;

	return *this;
}

void FragTrap::highFivesGuys() {
	if (this->_hitPoints == 0) {
		std::cout << this->_name << " FragTrap can't hight fives because is dead" << std::endl;
		return;
	}

	std::cout << this->_name << " FragTrap hight fives guys!!!" << std::endl;
}
