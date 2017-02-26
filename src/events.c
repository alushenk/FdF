//
// Created by Anton Lushenko on 2/23/17.
//

#include "FdF.h"

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
    {
        zoom_matrix(mlx->pixel, STEP_ZOOM_INCREASE);
        find_centre(mlx);
        move_matrix(mlx->pixel, old_centre_x - mlx->center_x, 1, 1, 0);
        draw(mlx);
    }
    else if (key == KEY_SCALE_DECREASE)
    {
        zoom_matrix(mlx->pixel, STEP_ZOOM_DECREASE);
        find_centre(mlx);
        move_matrix(mlx->pixel, old_centre_x - mlx->center_x, 1, 1, 0);
        draw(mlx);
    }
    else if (key == KEY_RIGHT)
    {
        move_matrix(mlx->pixel, STEP_MOVE, 1, 0, 0);
        draw(mlx);
    }
    else if (key == KEY_LEFT)
    {
        move_matrix(mlx->pixel, -STEP_MOVE, 1, 0, 0);
        draw(mlx);
    }
    else if (key == KEY_UP)
    {
        move_matrix(mlx->pixel, -STEP_MOVE, 0, 1, 0);
        draw(mlx);
    }
    else if (key == KEY_DOWN)
    {
        move_matrix(mlx->pixel, STEP_MOVE, 0, 1, 0);
        draw(mlx);
    }
    else if (key == KEY_EXIT)
    {
        exit(0);
    }
    else if (key == KEY_ROTATE_X_RIGHT)
    {
        move_matrix(mlx->pixel, -old_centre_y, 0, 1, 1);
        rotate_x(mlx->pixel, -STEP_ROTATE);
        move_matrix(mlx->pixel, old_centre_y, 0, 1, 1);
        draw(mlx);
    }
    else if (key == KEY_ROTATE_X_LEFT)
    {
        move_matrix(mlx->pixel, -old_centre_y, 0, 1, 1);
        rotate_x(mlx->pixel, STEP_ROTATE);
        move_matrix(mlx->pixel, old_centre_y, 0, 1, 1);
        draw(mlx);
    }
    else if (key == KEY_ROTATE_Y_RIGHT)
    {
        move_matrix(mlx->pixel, -old_centre_x, 1, 0, 1);
        rotate_y(mlx->pixel, -STEP_ROTATE);
        move_matrix(mlx->pixel, old_centre_x, 1, 0, 1);
        draw(mlx);
    }
    else if (key == KEY_ROTATE_Y_LEFT)
    {
        move_matrix(mlx->pixel, -old_centre_x, 1, 0, 1);
        rotate_y(mlx->pixel, STEP_ROTATE);
        move_matrix(mlx->pixel, old_centre_x, 1, 0, 1);
        draw(mlx);
    }
    else if (key == KEY_ROTATE_Z_RIGHT)
    {
        move_matrix(mlx->pixel, -old_centre_x, 1, 1, 0);
        rotate_z(mlx->pixel, STEP_ROTATE);
        move_matrix(mlx->pixel, old_centre_x, 1, 1, 0);
        draw(mlx);
    }

    else if (key == KEY_ROTATE_Z_LEFT)
    {
        move_matrix(mlx->pixel, -old_centre_x, 1, 1, 0);
        rotate_z(mlx->pixel, -STEP_ROTATE);
        move_matrix(mlx->pixel, old_centre_x, 1, 1, 0);
        draw(mlx);
    }
    return (0);
}