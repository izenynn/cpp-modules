/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 01:03:55 by dpoveda-          #+#    #+#             */
/*   Updated: 2022/02/17 02:12:50 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

#include <iostream>

Character::Character() {}

Character::Character(const std::string& name)
		: _name(name),
		  _nEquiped(0) {
	for (int i = 0; i < Character::kInventorySize; i++) {
		this->_inventory[i] = NULL;
	}
}

Character::Character(const Character& other) {
	*this = other;
}

Character::~Character() {}

Character& Character::operator=(const Character& other) {
	this->_name = other._name;
	this->_nEquiped = other._nEquiped;
	for (int i = 0; i < Character::kInventorySize; i++) {
		this->_inventory[i] = other._inventory[i];
	}
	return *this;
}

const std::string& Character::getName() const {
	return this->_name;
}

void Character::equip(AMateria *m) {
	if (this->_nEquiped < Character::kInventorySize) {
		this->_inventory[this->_nEquiped] = m;
		this->_nEquiped++;
	}
}

void Character::unequip(int idx) {
	int i = idx + 1;
	for (; i < Character::kInventorySize && this->_inventory[i] != NULL; i++) {
		this->_inventory[i - 1] = this->_inventory[i];
	}
	this->_inventory[i] = NULL;
}

void Character::use(int idx, ICharacter &target) {
	if (idx >= 0 || idx < this->_nEquiped) {
		this->_inventory[idx]->use(target);
	}
}
