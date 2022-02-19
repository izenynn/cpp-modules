/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 23:48:30 by dpoveda-          #+#    #+#             */
/*   Updated: 2022/02/19 00:08:01 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Scalar.hpp"

#include <iostream>

int main(int argc, char *argv[]) {
	if (argc == 1) {
		std::cout << "Error: no parameters\n" << "Usage: <program> <literal>" << std::endl;
		return 1;
	}

	Scalar::convert(argv[1]);

	return 0;
}
