/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 02:25:12 by dpoveda-          #+#    #+#             */
/*   Updated: 2022/02/16 02:40:40 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX02_FRAGTRAP_HPP_
# define EX02_FRAGTRAP_HPP_

# include "ClapTrap.hpp"

# include <string>

class FragTrap : public ClapTrap {
	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap& other);
		~FragTrap();

		FragTrap& operator=(const FragTrap& other);

		void highFivesGuys();
	private:
};

#endif
