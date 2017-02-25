//
// Created by Anton Lushenko on 2/23/17.
//

#include "FdF.h"

void    zoom_matrix(double **arr, int rows, int cols, double multiplier)
{
    int i;
    int j;

    i = 0;
    while (i < rows)
    {
        j = 0;
        while (j < cols)
        {
            arr[i][j] *= multiplier;
            j++;
        }
        i++;
    }
}

void    move_matrix(double **arr, int rows, int cols, double move)
{
    int i;
    int j;

    i = 0;
    while (i < rows)
    {
        j = 0;
        while (j < cols)
        {
            arr[i][j] += move;
            j++;
        }
        i++;
    }
}

void    find_centre(t_struct *mlx)
{
    double max_x_figure;
    double max_y_figure;
    double min_x_figure;
    double min_y_figure;
    int i;
    int j;

    i = 0;
    max_x_figure = mlx->arr_x[0][0];
    max_y_figure = mlx->arr_y[0][0];
    min_x_figure = mlx->arr_x[0][0];
    min_y_figure = mlx->arr_y[0][0];
    while (i < mlx->rows)
    {
        j = 0;
        while (j < mlx->cols)
        {
            if (mlx->arr_x[i][j] > max_x_figure)
                max_x_figure = mlx->arr_x[i][j];
            if (mlx->arr_x[i][j] < min_x_figure)
                min_x_figure = mlx->arr_x[i][j];
            if (mlx->arr_y[i][j] > max_y_figure)
                max_y_figure = mlx->arr_y[i][j];
            if (mlx->arr_y[i][j] < min_y_figure)
                min_y_figure = mlx->arr_y[i][j];
            j++;
        }
        i++;
    }
    mlx->center_x = min_x_figure + (max_x_figure - min_x_figure) / 2;
    mlx->center_y = min_y_figure + (max_y_figure - min_y_figure) / 2;
}

void    rotate_z(t_struct *mlx, int rows, int cols)
{
    double x;
    double y;
    int i;
    int j;

    i = 0;
    while (i < rows)
    {
        j = 0;
        while (j < cols)
        {
            mlx->arr_x[i][j] = mlx->arr_x[i][j] * cos(ANGLE) - mlx->arr_y[i][j] * sin(ANGLE);
            mlx->arr_y[i][j] = mlx->arr_x[i][j] * sin(ANGLE) + mlx->arr_y[i][j] * cos(ANGLE);
            j++;
        }
        i++;
    }
}

void    prepare_matrix(t_struct *mlx)
{
    double window_centre_x;
    double window_centre_y;

    if (mlx->center_x == 0 && mlx->center_y == 0)
    {
        window_centre_x = WINDOW_SIZE_X / 2;
        window_centre_y = WINDOW_SIZE_Y / 2;
        find_centre(mlx);
        move_matrix(mlx->arr_x, mlx->rows, mlx->cols, window_centre_x - mlx->center_x);
        move_matrix(mlx->arr_y, mlx->rows, mlx->cols, window_centre_y - mlx->center_y);
    }
}