//
// Created by Anton Lushenko on 2/23/17.
//

#include "FdF.h"

void    zoom_matrix(t_pixel *pixel, double multiplier)
{
    while (pixel->down)
    {
        while (pixel->right)
        {
            pixel->x *= multiplier;
            pixel->y *= multiplier;
            pixel->z *= multiplier;
            pixel = pixel->right;
        }
        pixel = pixel->down;
    }
}

void    move_matrix(t_pixel *pixel, double move, int x, int y, int z)
{
    while (pixel->down)
    {
        while (pixel->right)
        {
            if (x)
                pixel->x += move;
            if (y)
                pixel->y += move;
            if (z)
                pixel->z += move;
            pixel = pixel->right;
        }
        pixel = pixel->down;
    }
}

void    find_centre(t_struct *mlx)
{
    double max_x;
    double max_y;
    double max_z;
    t_pixel *y;
    t_pixel *x;

    mlx->center_x = y->x;
    mlx->center_y = y->y;
    mlx->center_z = y->z;
    max_x = y->x;
    max_y = y->y;
    max_z = y->z;
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