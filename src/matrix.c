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

void    move_matrix(t_pixel *pixel, double move, int combination)
{
    t_pixel *x;
    t_pixel *y;

    y = pixel;
    while (y->down)
    {
        x = y;
        while (x->right)
        {
            if (combination == 0)
            {
                x->x += move;
                x->y += move;
            }
            if (combination == 1)
            {
                x->x += move;
                x->z += move;
            }
            else if (combination == 2)
            {
                x->y += move;
                x->z += move;
            }
            else if (combination == 3)
            {
                x->x += move;
            }
            else if (combination == 4)
            {
                x->y += move;
            }
            else if (combination == 5)
            {
                x->z += move;
            }
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
    double min_x;
    double min_y;
    double min_z;
    t_pixel *y;
    t_pixel *x;

    min_x = mlx->pixel->x;
    min_y = mlx->pixel->y;
    min_z = mlx->pixel->z;
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
            if (x->x < min_x)
                min_x = x->x;
            if (x->y > max_y)
                max_y = x->y;
            if (x->y < min_y)
                min_y = x->y;
            if (x->z > max_z)
                max_z = x->z;
            if (x->z < min_z)
                min_z = x->z;
            x = x->right;
        }
        y = y->down;
    }
    mlx->center_x = min_x + (max_x - min_x) / 2;
    mlx->center_y = min_y + (max_y - min_y) / 2;
    mlx->center_z = min_z + (max_z - min_z) / 2;
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
        move_matrix(mlx->pixel, window_centre_x - mlx->center_x, 3);
        move_matrix(mlx->pixel, window_centre_y - mlx->center_y, 4);
    }
}