/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 22:22:49 by dpoveda-          #+#    #+#             */
/*   Updated: 2022/02/12 12:31:48 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP_
# define PHONEBOOK_HPP_

# include "Contact.hpp"

# define MAX_CONTACTS 8

class PhoneBook {
	public:
		PhoneBook();
		~PhoneBook();

		void addContact(void);
		void searchContact();
	private:
		int newContactIndex;
		int contactAmount;
		Contact *contacts[MAX_CONTACTS];
};

#endif
