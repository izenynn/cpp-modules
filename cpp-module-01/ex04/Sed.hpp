/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 12:16:35 by dpoveda-          #+#    #+#             */
/*   Updated: 2022/02/15 13:17:37 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX04_SED_HPP_
# define EX04_SED_HPP_

#include <string>

class Sed {
	public:
		Sed();
		~Sed();

		static int replace(std::string const filename, std::string const s1, std::string const s2);
	private:
		static std::string _strReplace(std::string line, std::string const s1, std::string const s2);
};

#endif
