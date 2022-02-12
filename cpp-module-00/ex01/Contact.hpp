/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 01:02:12 by dpoveda-          #+#    #+#             */
/*   Updated: 2022/02/12 13:09:49 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP_
# define CONTACT_HPP_

# include <iostream>

# define FIELDS_CNT 5

class Contact {
	public:
		Contact();
		~Contact();
		int setInformation(int index);
		void tableDisplay();

	private:
		enum fields {
			firstName = 0,
			lastName,
			nickname,
			phone,
			darkestSecret
		};

		int index;
		std::string fieldsInfo[FIELDS_CNT];
};

#endif
