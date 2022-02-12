/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 01:02:12 by dpoveda-          #+#    #+#             */
/*   Updated: 2022/02/12 01:24:05 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP_
# define CONTACT_HPP_

# include <iostream>

class Contact {
	public:
		Contact();
		~Contact();

	private:
		std::string firstName;
		std::string lastName;
		std::string nickName;
		std::string login;
		std::string address;
		std::string email;
		std::string phone;
		std::string birthday;
		std::string favoriteMeal;
		std::string underwearColor;
		std::string secret;
};

#endif
