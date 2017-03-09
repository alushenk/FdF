/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alushenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 17:26:53 by alushenk          #+#    #+#             */
/*   Updated: 2017/03/01 17:27:21 by alushenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_header.h"

static void	get_ab(t_pixel *x, double *a, double *b, int combination)
{
	if (combination == 0)
	{
		*a = x->x;
		*b = x->y;
	}
	else if (combination == 1)
	{
		*a = x->x;
		*b = x->z;
	}
	else if (combination == 2)
	{
		*a = x->y;
		*b = x->z;
	}
}

static void	set_ab(t_pixel *x, double a, double b, int combination)
{
	if (combination == 0)
	{
		x->x = a;
		x->y = b;
	}
	else if (combination == 1)
	{
		x->x = a;
		x->z = b;
	}
	else if (combination == 2)
	{
		x->y = a;
		x->z = b;
	}
}

void		rotate(t_pixel *pixel, double angle, int combination)
{
	double	a;
	double	b;
	t_pixel	*x;
	t_pixel	*y;

	y = pixel;
	while (y->down)
	{
		x = y;
		while (x->right)
		{
			get_ab(x, &a, &b, combination);
			a = (a * cos(angle * RAD)) - (b * sin(angle * RAD));
			b = (a * sin(angle * RAD)) + (b * cos(angle * RAD));
			set_ab(x, a, b, combination);
			x = x->right;
		}
		y = y->down;
	}
}
