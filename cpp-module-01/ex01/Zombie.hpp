/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 14:27:34 by dpoveda-          #+#    #+#             */
/*   Updated: 2022/02/14 16:16:21 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX00_ZOMBIE_HPP_
# define EX00_ZOMBIE_HPP_

# include <string>

class Zombie {
	public:
		Zombie();
		Zombie(std::string name);
		~Zombie();

		void setName(std::string newName);
		void announce() const;
	private:
		std::string _name;
};

#endif
