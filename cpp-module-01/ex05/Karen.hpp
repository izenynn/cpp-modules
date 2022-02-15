/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:14:55 by dpoveda-          #+#    #+#             */
/*   Updated: 2022/02/15 15:13:16 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX05_KAREN_HPP_
# define EX05_KAREN_HPP_

# include <string>

class Karen {
	public:
		Karen();
		~Karen();

		void complain(std::string level);
	private:
		void debug();
		void info();
		void warning();
		void error();

		typedef void (Karen::*f)();
};

#endif
