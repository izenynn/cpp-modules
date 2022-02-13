/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 22:22:49 by dpoveda-          #+#    #+#             */
/*   Updated: 2022/02/13 12:44:14 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP_
# define PHONEBOOK_HPP_

# include "Contact.hpp"

class PhoneBook {
	public:
		PhoneBook();
		~PhoneBook();

		void addContact(void);
		void searchContact();
	private:
		static const int MAX_CONTACTS = 8;
		int newContactIndex;
		int contactAmount;
		Contact *contacts[MAX_CONTACTS];
};

#endif
