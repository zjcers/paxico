/*
 * tests/math/ceil_neg.c
 * Copyright 2016 Zane J Cersovsky
 * This file is part of Project Paxico.

 * Project Paxico is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * Project Paxico is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with Project Paxico.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * Tests if ceil() works as expected for x<0.0
 */
#include <math.h>
#include <stdlib.h>
int main()
{
	double x = ceil(-3.4);
	if (fabs(x)-3.0 < 0.01)
		return EXIT_SUCCESS;
	return EXIT_FAILURE;
}
