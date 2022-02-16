/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 02:25:12 by dpoveda-          #+#    #+#             */
/*   Updated: 2022/02/16 03:32:00 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX03_FRAGTRAP_HPP_
# define EX03_FRAGTRAP_HPP_

# include "ClapTrap.hpp"

# include <string>

class FragTrap : virtual public ClapTrap {
	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap& other);
		virtual ~FragTrap();

		FragTrap& operator=(const FragTrap& other);

		void highFivesGuys();
	protected:
};

#endif
