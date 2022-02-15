/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:42:32 by dpoveda-          #+#    #+#             */
/*   Updated: 2022/02/15 14:44:20 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

int main(int argc, char *argv[]) {
	Karen *karen;

	karen = new Karen;
	for (int i = 1; i < argc; i++) {
		karen->complain(argv[i]);
	}
	delete karen;

	return 0;
}
