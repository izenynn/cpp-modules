/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 01:03:55 by dpoveda-          #+#    #+#             */
/*   Updated: 2022/02/17 21:29:39 by dpoveda-         ###   ########.fr       */
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
	if (idx >= 0 && idx < this->_nEquiped) {
		int i = idx;
		for (; i < this->_nEquiped - 1; i++) {
			this->_inventory[i] = this->_inventory[i + 1];
		}
		this->_inventory[i] = NULL;
		--(this->_nEquiped);
	}

	// debug
	/*for (int j = 0; j < Character::kInventorySize; j++) {
		std::cout << "inv: " << this->_inventory[j] << std::endl;
	}
	std::cout << std::endl;*/
}

void Character::use(int idx, ICharacter &target) {
	//std::cout << "idx: " << idx << ", nequip: " << this->_nEquiped << std::endl;
	if (idx >= 0 && idx < this->_nEquiped) {
		this->_inventory[idx]->use(target);
	} else {
		std::cout << "can't use materia, index " << idx << " is empty" << std::endl;
	}
}
