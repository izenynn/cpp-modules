/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 03:26:47 by dpoveda-          #+#    #+#             */
/*   Updated: 2022/02/20 03:36:30 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mutantstack.hpp"

#include <iostream>

int main()
{
	MutantStack<int> mstack;
	mstack.push(5); // 5
	mstack.push(17); // 17, 5
	std::cout << mstack.top() << std::endl;
	mstack.pop(); // 5
	std::cout << mstack.size() << std::endl;
	mstack.push(3); // 3, 5
	mstack.push(5); // 5, 3, 5
	mstack.push(737); // 737, 5, 3, 5
	//[...]
	mstack.push(0); // 0, 737, 5, 3, 5
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	std::cout << "\nITERATE STACK:" << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	return 0;
}
