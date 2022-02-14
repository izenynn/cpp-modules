/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:46:50 by dpoveda-          #+#    #+#             */
/*   Updated: 2022/02/14 16:19:17 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#include <iostream>
#include <string>

Zombie *newZombie(std::string);
void randomChump(std::string name);

int main() {
	// watson the zombie
	Zombie *watson = new Zombie("Watson");;
	watson->announce();
	randomChump("otaku zombie");
	delete watson;

	std::cout << std::endl;

	// mickel jackson con tremenda bachata zombie
	Zombie *mickel = newZombie("Mickel");
	mickel->announce();
	// peppa pig
	Zombie *peppa = newZombie("Peppa pig");
	peppa->announce();
	mickel->announce();
	delete mickel;
	peppa->announce();
	delete peppa;

	std::cout << std::endl;

	// random chumps
	randomChump("vegan zombie");

	return 0;
}
