/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 03:00:39 by dpoveda-          #+#    #+#             */
/*   Updated: 2022/02/20 14:38:53 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP_
# define MUTANTSTACK_HPP_

# include <stack>
# include <deque>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
	public:
		MutantStack() {}
		MutantStack(const MutantStack& other) : std::stack<T, Container>(other) {
			*this = other;
		}
		~MutantStack() {}

		MutantStack& operator=(const MutantStack& other) {
			if (this == &other) return *this;
			this->std::stack<T, Container>::operator=(other);
			return *this;
		}

		typedef typename std::stack<T, Container>::container_type::iterator iterator;
		typedef typename std::stack<T, Container>::container_type::const_iterator const_iterator;
		typedef typename std::stack<T, Container>::container_type::reverse_iterator reverse_iterator;
		typedef typename std::stack<T, Container>::container_type::const_reverse_iterator const_reverse_iterator;

		iterator begin() { return this->std::stack<T, Container>::c.begin(); }
		iterator end() { return this->std::stack<T, Container>::c.end(); }

		reverse_iterator rbegin() { return this->std::stack<T, Container>::c.rbegin(); }
		reverse_iterator rend() { return this->std::stack<T, Container>::c.rend(); }

		const_iterator begin() const { return this->std::stack<T, Container>::c.begin(); }
		const_iterator end() const { return this->std::stack<T, Container>::c.end(); }

		const_reverse_iterator rbegin() const { return this->std::stack<T, Container>::c.rbegin(); }
		const_reverse_iterator rend() const { return this->std::stack<T, Container>::c.rend(); }
};

#endif
