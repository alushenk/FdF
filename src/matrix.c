/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alushenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 12:32:16 by alushenk          #+#    #+#             */
/*   Updated: 2017/03/01 12:32:18 by alushenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void		zoom_matrix(t_pixel *pixel, double multiplier)
{
	t_pixel	*x;
	t_pixel	*y;

	y = pixel;
	while (y->down)
	{
		x = y;
		while (x->right)
		{
			x->x *= multiplier;
			x->y *= multiplier;
			x->z *= multiplier;
			x = x->right;
		}
		y = y->down;
	}
}

static void	do_combination(t_pixel *pixel, double move, int combination)
{
	if (combination == 0)
	{
		pixel->x += move;
		pixel->y += move;
	}
	if (combination == 1)
	{
		pixel->x += move;
		pixel->z += move;
	}
	else if (combination == 2)
	{
		pixel->y += move;
		pixel->z += move;
	}
	else if (combination == 3)
		pixel->x += move;
	else if (combination == 4)
		pixel->y += move;
	else if (combination == 5)
		pixel->z += move;
}

void		move_matrix(t_pixel *pixel, double move, int combination)
{
	t_pixel	*x;
	t_pixel	*y;

	y = pixel;
	while (y->down)
	{
		x = y;
		while (x->right)
		{
			do_combination(x, move, combination);
			x = x->right;
		}
		y = y->down;
	}
}

void		prepare_matrix(t_map *mlx)
{
	double	window_centre_x;
	double	window_centre_y;

	if (mlx->center_x == 0 && mlx->center_y == 0)
	{
		rotate(mlx->pixel, 30, 2);
		window_centre_x = WINDOW_SIZE_X / 2;
		window_centre_y = WINDOW_SIZE_Y / 2;
		zoom_matrix(mlx->pixel, STEP_ZOOM_INCREASE);
		find_centre(mlx);
		move_matrix(mlx->pixel, window_centre_x - mlx->center_x, 3);
		move_matrix(mlx->pixel, window_centre_y - mlx->center_y, 4);
	}
}
