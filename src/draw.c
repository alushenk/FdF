/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alushenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 14:08:38 by alushenk          #+#    #+#             */
/*   Updated: 2017/03/01 14:08:40 by alushenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_header.h"

static void	color_increase(double **color, double *color_step)
{
	(*color)[0] += color_step[0];
	(*color)[1] += color_step[1];
	(*color)[2] += color_step[2];
}

static void	draw_line(t_pixel *start, t_pixel *end, t_map *mlx, t_color *col)
{
	t_bresenham b;

	bresen_init(&b, start, end);
	color_init(&col->color, start);
	get_color(col->color_step, start->color, end->color, b.dist);
	while (b.x0 != b.x1 || b.y0 != b.y1)
	{
		if (in_range(b.x0, b.y0))
			write_pixel(b.x0, b.y0, col->color, mlx);
		b.error2 = b.error * 2;
		if (b.error2 > -b.delta_y)
		{
			b.error -= b.delta_y;
			b.x0 += b.move_x;
		}
		if (b.error2 < b.delta_x)
		{
			b.error += b.delta_x;
			b.y0 += b.move_y;
		}
		color_increase(&col->color, col->color_step);
	}
	if (in_range((int)end->x, (int)end->y))
		write_pixel((int)end->x, (int)end->y, col->color, mlx);
}

static void	draw_lines(t_pixel *p, t_map *mlx, t_color *col)
{
	if (p->right && p->right->x)
		draw_line(p, p->right, mlx, col);
	if (p->down && p->down->y)
		draw_line(p, p->down, mlx, col);
	if (p->right && p->right->down && p->right->down->x && p->right->down->y)
		draw_line(p, p->right->down, mlx, col);
}

static void	draw_map(t_map *mlx)
{
	t_color col;
	t_pixel	*y;
	t_pixel	*x;

	col.color = (double*)malloc(sizeof(double) * 3);
	col.color_step = (double*)malloc(sizeof(double) * 3);
	y = mlx->pixel;
	while (y->down)
	{
		x = y;
		while (x->right)
		{
			draw_lines(x, mlx, &col);
			x = x->right;
		}
		y = y->down;
	}
	free(col.color);
	free(col.color_step);
}

void		draw(t_map *mlx)
{
	if (mlx->img)
		mlx_destroy_image(mlx->init, mlx->img);
	mlx->img = mlx_new_image(mlx->init, WIN_SIZE_X, WIN_SIZE_Y);
	mlx->img_d = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->l_size, &mlx->e);
	prepare_matrix(mlx);
	draw_map(mlx);
	mlx_put_image_to_window(mlx->init, mlx->win, mlx->img, 0, 0);
}
