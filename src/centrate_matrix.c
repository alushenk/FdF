/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   centrate_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alushenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 13:48:01 by alushenk          #+#    #+#             */
/*   Updated: 2017/03/01 13:48:02 by alushenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

static void	limits_init(t_map *mlx, t_limits *limits)
{
	limits->max_x = mlx->pixel->x;
	limits->max_y = mlx->pixel->y;
	limits->max_z = mlx->pixel->z;
	limits->min_x = mlx->pixel->x;
	limits->min_y = mlx->pixel->y;
	limits->min_z = mlx->pixel->z;
}

static void	limits_fill(t_limits *lim, t_pixel *pixel)
{
	if (pixel->x > lim->max_x)
		lim->max_x = pixel->x;
	if (pixel->x < lim->min_x)
		lim->min_x = pixel->x;
	if (pixel->y > lim->max_y)
		lim->max_y = pixel->y;
	if (pixel->y < lim->min_y)
		lim->min_y = pixel->y;
	if (pixel->z > lim->max_z)
		lim->max_z = pixel->z;
	if (pixel->z < lim->min_z)
		lim->min_z = pixel->z;
}

void		find_centre(t_map *mlx)
{
	t_limits	lim;
	t_pixel		*y;
	t_pixel		*x;

	limits_init(mlx, &lim);
	y = mlx->pixel;
	while (y->down)
	{
		x = y;
		while (x->right)
		{
			limits_fill(&lim, x);
			x = x->right;
		}
		y = y->down;
	}
	mlx->center_x = lim.min_x + (lim.max_x - lim.min_x) / 2;
	mlx->center_y = lim.min_y + (lim.max_y - lim.min_y) / 2;
	mlx->center_z = lim.min_z + (lim.max_z - lim.min_z) / 2;
}
