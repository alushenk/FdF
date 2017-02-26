//
// Created by Anton Lushenko on 2/23/17.
//

#include "FdF.h"

void    zoom_matrix(t_pixel *pixel, double multiplier)
{
    t_pixel *x;
    t_pixel *y;

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

void    move_matrix(t_pixel *pixel, double move, int a, int b, int c)
{
    t_pixel *x;
    t_pixel *y;

    y = pixel;
    while (y->down)
    {
        x = y;
        while (x->right)
        {
            if (a)
                x->x += move;
            if (b)
                x->y += move;
            if (c)
                x->z += move;
            x = x->right;
        }
        y = y->down;
    }
}

void    find_centre(t_struct *mlx)
{
    double max_x;
    double max_y;
    double max_z;
    t_pixel *y;
    t_pixel *x;

    mlx->center_x = mlx->pixel->x;
    mlx->center_y = mlx->pixel->y;
    mlx->center_z = mlx->pixel->z;
    max_x = mlx->pixel->x;
    max_y = mlx->pixel->y;
    max_z = mlx->pixel->z;
    y = mlx->pixel;
    while (y->down)
    {
        x = y;
        while (x->right)
        {
            if (x->x > max_x)
                max_x = x->x;
            if (x->x < mlx->center_x)
                mlx->center_x = x->x;
            if (x->y > max_y)
                max_y = x->y;
            if (x->y < mlx->center_y)
                mlx->center_y = x->y;
            if (x->z > max_z)
                max_z = x->z;
            if (x->z < mlx->center_z)
                mlx->center_z = x->z;
            x = x->right;
        }
        y = y->down;
    }
    mlx->center_x = mlx->center_x + (max_x - mlx->center_x) / 2;
    mlx->center_y = mlx->center_y + (max_y - mlx->center_y) / 2;
    mlx->center_z = mlx->center_z + (max_z - mlx->center_z) / 2;
}

void    prepare_matrix(t_struct *mlx)
{
    double window_centre_x;
    double window_centre_y;

    if (mlx->center_x == 0 && mlx->center_y == 0)
    {
        window_centre_x = WINDOW_SIZE_X / 2;
        window_centre_y = WINDOW_SIZE_Y / 2;
        zoom_matrix(mlx->pixel, STEP_ZOOM_INCREASE);
        find_centre(mlx);
        move_matrix(mlx->pixel, window_centre_x - mlx->center_x, 1, 0, 0);
        move_matrix(mlx->pixel, window_centre_y - mlx->center_y, 0, 1, 0);
    }
}