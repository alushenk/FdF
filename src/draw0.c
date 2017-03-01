/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw0.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alushenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 17:18:31 by alushenk          #+#    #+#             */
/*   Updated: 2017/03/01 17:18:49 by alushenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_header.h"

void	write_pixel(int x, int y, double *color, t_map *mlx)
{
	int a;

	a = (y * mlx->l_size + (x * (mlx->bpp / 8)));
	a += mlx->bpp;
	mlx->img_d[a] = (unsigned char)color[2];
	mlx->img_d[a + 1] = (unsigned char)color[1];
	mlx->img_d[a + 2] = (unsigned char)color[0];
}

int		in_range(int x, int y)
{
	if (x < 0 || y < 0 || x >= WIN_SIZE_X || y >= WIN_SIZE_Y)
		return (0);
	return (1);
}

void	get_color(double *color, int start, int end, double dist)
{
	color[0] = (((U_CHAR)(end >> 16) - (U_CHAR)(start >> 16)));
	color[1] = (((U_CHAR)(end >> 8) - (U_CHAR)(start >> 8)));
	color[2] = (U_CHAR)end - (U_CHAR)start;
	if (dist)
	{
		color[0] /= dist;
		color[1] /= dist;
		color[2] /= dist;
	}
}

void	bresen_init(t_bresenham *b, t_pixel *start, t_pixel *end)
{
	b->x0 = (int)start->x;
	b->y0 = (int)start->y;
	b->x1 = (int)end->x;
	b->y1 = (int)end->y;
	b->move_x = start->x < end->x ? 1 : -1;
	b->move_y = start->y < end->y ? 1 : -1;
	b->delta_x = abs(b->x1 - b->x0);
	b->delta_y = abs(b->y1 - b->y0);
	b->error = b->delta_x - b->delta_y;
	b->dist = sqrt(pow((end->x - start->x), 2) + pow((end->y - start->y), 2));
}

void	color_init(double **color, t_pixel *start)
{
	(*color)[0] = (U_CHAR)(start->color >> 16);
	(*color)[1] = (U_CHAR)(start->color >> 8);
	(*color)[2] = (U_CHAR)start->color;
}
