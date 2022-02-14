/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 14:27:32 by dpoveda-          #+#    #+#             */
/*   Updated: 2022/02/14 16:17:11 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#include <iostream>
#include <string>

Zombie::Zombie()
	: _name("zombie") {}

Zombie::Zombie(std::string name)
	: _name(name) {}

Zombie::~Zombie() {
	std::cout << "<" << this->_name << "> Enought brainz..." << std::endl;
}

void Zombie::announce() const {
	std::cout << "<" << this->_name << "> BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string newName) {
	this->_name = newName;
}
