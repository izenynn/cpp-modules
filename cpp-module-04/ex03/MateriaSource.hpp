/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 02:15:49 by dpoveda-          #+#    #+#             */
/*   Updated: 2022/02/17 02:20:03 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP_
# define MATERIASOURCE_HPP_

# include "IMateriaSource.hpp"

# include <string>

class MateriaSource : public IMateriaSource {
	public:
		MateriaSource();
		MateriaSource(const MateriaSource& other);
		~MateriaSource();

		MateriaSource& operator=(const MateriaSource& other);

		void learnMateria(AMateria *materia);
		AMateria* createMateria(const std::string& type);
	private:
		static const int kMateriaSize = 4;

		AMateria* _materias[MateriaSource::kMateriaSize];
		int _nLearned;
};

#endif
