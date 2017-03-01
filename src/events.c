/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alushenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 17:47:39 by alushenk          #+#    #+#             */
/*   Updated: 2017/03/01 17:47:40 by alushenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void		zoom(t_map *mlx, double old_x, double old_y, double zoom)
{
	zoom_matrix(mlx->pixel, zoom);
	find_centre(mlx);
	move_matrix(mlx->pixel, old_x - mlx->center_x, 3);
	move_matrix(mlx->pixel, old_y - mlx->center_y, 4);
	draw(mlx);
}

static void	get_ab(int *a, int *b, int comb)
{
	if (comb == 0)
	{
		*a = 3;
		*b = 4;
	}
	else if (comb == 1)
	{
		*a = 3;
		*b = 5;
	}
	else if (comb == 2)
	{
		*a = 4;
		*b = 5;
	}
	else
	{
		ft_putstr("error");
		*a = 0;
		*b = 0;
	}
}

static void	get_oldcent(t_oldcent *o, double *cent_a, double *cent_b, int comb)
{
	if (comb == 0)
	{
		*cent_a = o->old_x;
		*cent_b = o->old_y;
	}
	else if (comb == 1)
	{
		*cent_a = o->old_x;
		*cent_b = o->old_z;
	}
	else if (comb == 2)
	{
		*cent_a = o->old_y;
		*cent_b = o->old_z;
	}
	else
	{
		ft_putstr("error");
		*cent_a = 0;
		*cent_b = 0;
	}
}

static void	draw_rotate(t_map *mlx, t_oldcent *oldcentre, double step, int comb)
{
	int		a;
	int		b;
	double	oldcentre_a;
	double	oldcentre_b;

	get_ab(&a, &b, comb);
	get_oldcent(oldcentre, &oldcentre_a, &oldcentre_b, comb);
	move_matrix(mlx->pixel, -oldcentre_a, a);
	move_matrix(mlx->pixel, -oldcentre_b, b);
	rotate(mlx->pixel, step, comb);
	move_matrix(mlx->pixel, oldcentre_a, a);
	move_matrix(mlx->pixel, oldcentre_b, b);
	draw(mlx);
}

static void	centre_init(t_map *mlx, t_oldcent *oldcentre)
{
	find_centre(mlx);
	oldcentre->old_x = mlx->center_x;
	oldcentre->old_y = mlx->center_y;
	oldcentre->old_z = mlx->center_z;
}

int			key_hook(int key, t_map *mlx)
{
	t_oldcent	cen;

	centre_init(mlx, &cen);
	if (key == KEY_SCALE_INCREASE)
		zoom(mlx, cen.old_x, cen.old_y, STEP_ZOOM_INCREASE);
	else if (key == KEY_SCALE_DECREASE)
		zoom(mlx, cen.old_x, cen.old_y, STEP_ZOOM_DECREASE);
	else if (key == KEY_RIGHT)
	{
		move_matrix(mlx->pixel, STEP_MOVE, 3);
		draw(mlx);
	}
	else if (key == KEY_LEFT)
	{
		move_matrix(mlx->pixel, -STEP_MOVE, 3);
		draw(mlx);
	}
	else if (key == KEY_UP)
	{
		move_matrix(mlx->pixel, -STEP_MOVE, 4);
		draw(mlx);
	}
	else if (key == KEY_DOWN)
	{
		move_matrix(mlx->pixel, STEP_MOVE, 4);
		draw(mlx);
	}
	else if (key == KEY_EXIT)
		exit(0);
	else if (key == KEY_ROTATE_X_RIGHT)
		draw_rotate(mlx, &cen, -STEP_ROTATE, 2);
	else if (key == KEY_ROTATE_X_LEFT)
		draw_rotate(mlx, &cen, STEP_ROTATE, 2);
	else if (key == KEY_ROTATE_Y_RIGHT)
		draw_rotate(mlx, &cen, -STEP_ROTATE, 1);
	else if (key == KEY_ROTATE_Y_LEFT)
		draw_rotate(mlx, &cen, STEP_ROTATE, 1);
	else if (key == KEY_ROTATE_Z_RIGHT)
		draw_rotate(mlx, &cen, STEP_ROTATE, 0);
	else if (key == KEY_ROTATE_Z_LEFT)
		draw_rotate(mlx, &cen, -STEP_ROTATE, 0);
	return (0);
}
