/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 01:03:55 by dpoveda-          #+#    #+#             */
/*   Updated: 2022/02/18 16:26:25 by dpoveda-         ###   ########.fr       */
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

Character::~Character() {
	for (int i = 0; i < this->_nEquiped; i++) {
		delete this->_inventory[i];
	}
}

Character& Character::operator=(const Character& other) {
	this->_name = other._name;
	this->_nEquiped = other._nEquiped;
	for (int i = 0; i < Character::kInventorySize; i++) {
		//this->_inventory[i] = other._inventory[i]; // shallow copy
		this->_inventory[i] = other._inventory[i]->clone(); // deep copy
	}
	return *this;
}

const std::string& Character::getName() const {
	return this->_name;
}

void Character::equip(AMateria *m) {
	if (this->_nEquiped < Character::kInventorySize) {
		this->_inventory[this->_nEquiped] = m; // shallow copy
		this->_nEquiped++;
	}
}

void Character::unequip(int idx) {
	if (idx >= 0 && idx < this->_nEquiped) {
		delete this->_inventory[idx];
		int i = idx;
		for (; i < this->_nEquiped - 1; i++) {
			this->_inventory[i] = this->_inventory[i + 1];
		}
		this->_inventory[i] = NULL;
		--(this->_nEquiped);
	}
}

void Character::use(int idx, ICharacter &target) {
	if (idx >= 0 && idx < this->_nEquiped) {
		this->_inventory[idx]->use(target);
	} else {
		std::cout << "can't use materia, index " << idx << " is empty" << std::endl;
	}
}
