//
// Created by Anton Lushenko on 2/23/17.
//

#include "FdF.h"

void    zoom(t_struct *mlx, double old_centre_x, double old_centre_y, double zoom)
{
    zoom_matrix(mlx->pixel, zoom);
    find_centre(mlx);
    move_matrix(mlx->pixel, old_centre_x - mlx->center_x, 3);
    move_matrix(mlx->pixel, old_centre_y - mlx->center_y, 4);
    draw(mlx);
}

void    draw_rotate(t_struct *mlx, double old_centre_a, double old_centre_b, double step, int combination)
{
    move_matrix(mlx->pixel, -old_centre_a, combination);
    move_matrix(mlx->pixel, -old_centre_b, combination);
    rotate(mlx->pixel, step, combination);
    move_matrix(mlx->pixel, old_centre_a, combination);
    move_matrix(mlx->pixel, old_centre_b, combination);
    draw(mlx);
}

int    key_hook(int key, t_struct *mlx)
{
    double old_centre_x;
    double old_centre_y;
    double old_centre_z;

    find_centre(mlx);
    old_centre_x = mlx->center_x;
    old_centre_y = mlx->center_y;
    old_centre_z = mlx->center_z;
    if (key == KEY_SCALE_INCREASE)
        zoom(mlx, old_centre_x, old_centre_y, STEP_ZOOM_INCREASE);
    else if (key == KEY_SCALE_DECREASE)
        zoom(mlx, old_centre_x, old_centre_y, STEP_ZOOM_DECREASE);
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
    {
        exit(0);
    }
    else if (key == KEY_ROTATE_X_RIGHT)
        draw_rotate(mlx, old_centre_y, old_centre_z, -STEP_ROTATE, 2);
    else if (key == KEY_ROTATE_X_LEFT)
        draw_rotate(mlx, old_centre_y, old_centre_z, STEP_ROTATE, 2);
    else if (key == KEY_ROTATE_Y_RIGHT)
        draw_rotate(mlx, old_centre_x, old_centre_z, -STEP_ROTATE, 1);
    else if (key == KEY_ROTATE_Y_LEFT)
        draw_rotate(mlx, old_centre_x, old_centre_z, STEP_ROTATE, 1);
    else if (key == KEY_ROTATE_Z_RIGHT)
        draw_rotate(mlx, old_centre_x, old_centre_y, STEP_ROTATE, 0);
    else if (key == KEY_ROTATE_Z_LEFT)
        draw_rotate(mlx, old_centre_x, old_centre_y, -STEP_ROTATE, 0);
    return (0);
}