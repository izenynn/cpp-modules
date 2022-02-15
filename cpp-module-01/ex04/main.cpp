/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 12:11:46 by dpoveda-          #+#    #+#             */
/*   Updated: 2022/02/15 13:30:12 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

#include <iostream>

int main(int argc, char *argv[]) {
	if (argc != 4) {
		std::cout
			<< "Error: Invalid number of arguments." << '\n'
			<< "Usage: <program> <file name> <search> <replace>" << std::endl;
		return 1;
	}
	if (Sed::replace(argv[1], argv[2], argv[3])) {
		return 1;
	}
	return 0;
}
