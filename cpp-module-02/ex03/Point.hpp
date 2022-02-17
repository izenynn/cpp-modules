/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 19:41:04 by dpoveda-          #+#    #+#             */
/*   Updated: 2022/02/17 18:26:14 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX03_POINT_HPP_
# define EX03_POINT_HPP_

#include "Fixed.hpp"

class Point {
	public:
		Point();
		Point(const float x, const float y);
		Point(const Fixed x, const Fixed y);
		Point(const Point& other);
		~Point();

		Fixed getX() const;
		Fixed getY() const;
	private:
		Point& operator=(const Point& other); // Don't implement

		const Fixed x;
		const Fixed y;
};

#endif
