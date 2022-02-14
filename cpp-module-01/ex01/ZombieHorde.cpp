/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 16:02:42 by dpoveda-          #+#    #+#             */
/*   Updated: 2022/02/14 16:22:41 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name) {
	if (N <= 0) return NULL;

	Zombie *horde = new (std::nothrow) Zombie[N];
	for (int i = 0; i < N; i++) {
		horde[i].setName(name);
	}
	return horde;
}
