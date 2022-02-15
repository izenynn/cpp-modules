/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:54:07 by dpoveda-          #+#    #+#             */
/*   Updated: 2022/02/15 11:06:56 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type)
	: _type(type) {}

Weapon::~Weapon() {}

void Weapon::setType(std::string type) {
	this->_type = type;
}

std::string Weapon::getType() const {
	return this->_type;
}
