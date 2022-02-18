/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 02:20:12 by dpoveda-          #+#    #+#             */
/*   Updated: 2022/02/18 16:15:16 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
		: _nLearned(0) {
	for (int i = 0; i < MateriaSource::kMateriaSize; i++) {
		this->_materias[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource& other) {
	*this = other;
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < MateriaSource::kMateriaSize; i++) {
		if (this->_materias[i] != NULL) {
			delete this->_materias[i];
		}
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
	this->_nLearned = other._nLearned;

	for (int i = 0; i < MateriaSource::kMateriaSize; i++) {
		if (this->_materias[i] != NULL) delete this->_materias[i];
		if (other._materias[i] != NULL) {
			this->_materias[i] = other._materias[i]->clone();
		} else {
			this->_materias[i] = NULL;
		}
	}

	return *this;
}

void MateriaSource::learnMateria(AMateria *materia) {
	if (this->_nLearned < MateriaSource::kMateriaSize) {
		this->_materias[this->_nLearned] = materia;
		this->_nLearned++;
	}
}

AMateria *MateriaSource::createMateria(const std::string& type) {
	for (int i = 0; i < MateriaSource::kMateriaSize; i++) {
		if (this->_materias[i]->getType() == type) {
			return this->_materias[i]->clone(); // deep copy
			//return this->_materias[i]; // shallow copy
		}
	}
	return NULL;
}
