/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 19:40:39 by dpoveda-          #+#    #+#             */
/*   Updated: 2022/02/15 22:10:21 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

#include <iostream>

/********** GOOD IMPLEMENTATION **********/
/* edges are not part of the triangle */

namespace {
	Fixed side (const Point p, const Point p1, const Point p2) {
		return (p2.getY() - p1.getY()) * (p.getX() - p1.getX())
			+ ((p2.getX() * -1) + p1.getX()) * (p.getY() - p1.getY());
	}
}

bool bsp(const Point a, const Point b, const Point c, const Point point) {
	bool side1, side2, side3;

	side1 = side(point, a, b) > 0;
	side2 = side(point, b, c) > 0;
	side3 = side(point, c, a) > 0;

	return side1 && side2 && side3;
}

/********** OTHER IMPLEMENTATIONS **********/
/* edges are part of the triangle */

/*namespace {
	float sign (const Point p1, const Point p2, const Point p3) {
		return Fixed((p1.getX() - p3.getX()) * (p2.getY()) - (p2.getX() - p3.getX()) * (p1.getY() - p3.getY())).toFloat();
	}
}

bool bsp(const Point a, const Point b, const Point c, const Point point) {
	float d1, d2, d3;
	bool has_neg, has_pos;

	d1 = sign(point, a, b);
	d2 = sign(point, b, c);
	d3 = sign(point, c, a);

	has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
	has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

	return !(has_neg && has_pos);
}*/

/*bool bsp(const Point a, const Point b, const Point c, const Point point) {
	Fixed s, t;

	s = (a.getX() - c.getX()) * (point.getY() - c.getY()) - (a.getY() - c.getY()) * (point.getX() - c.getX());
	t = (b.getX() - a.getX()) * (point.getY() - a.getY()) - (b.getY() - a.getY()) * (point.getX() - a.getX());

	if ((s < 0) != (t < 0) && s != 0 && t != 0)
		return false;

	Fixed d = (c.getX() - b.getX()) * (point.getY() - b.getY()) - (c.getY() - b.getY()) * (point.getX() - b.getX());

	return d == 0 || (d < 0) == (s + t <= 0);
}*/

/*namespace {
	Fixed side (const Point p, const Point p1, const Point p2) {
		return (p2.getY() - p1.getY()) * (p.getX() - p1.getX())
			+ ((p2.getX() * -1) + p1.getX()) * (p.getY() - p1.getY());
	}
}

bool bsp(const Point a, const Point b, const Point c, const Point point) {
	bool side1, side2, side3;

	side1 = side(point, a, b) >= 0;
	side2 = side(point, b, c) >= 0;
	side3 = side(point, c, a) >= 0;

	return side1 && side2 && side3;
}*/
