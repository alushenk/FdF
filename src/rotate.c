//
// Created by Anton Lushenko on 2/25/17.
//

#include "FdF.h"

void    rotate_x(t_struct *mlx, int rows, int cols, int angle)
{
    double y;
    double z;
    int i;
    int j;

    i = 0;
    while (i < rows)
    {
        j = 0;
        while (j < cols)
        {
            y = mlx->arr_y[i][j];
            z = mlx->arr_z[i][j];
            mlx->arr_y[i][j] = (y * cos(angle * RAD)) - (z * sin(angle * RAD));
            mlx->arr_z[i][j] = (y * sin(angle * RAD)) + (z * cos(angle * RAD));
            j++;
        }
        i++;
    }
}

void    rotate_y(t_struct *mlx, int rows, int cols, int angle)
{
    double x;
    double z;
    int i;
    int j;

    i = 0;
    while (i < rows)
    {
        j = 0;
        while (j < cols)
        {
            x = mlx->arr_x[i][j];
            z = mlx->arr_z[i][j];
            mlx->arr_x[i][j] = (x * cos(angle * RAD)) - (z * sin(angle * RAD));
            mlx->arr_z[i][j] = (x * sin(angle * RAD)) + (z * cos(angle * RAD));
            j++;
        }
        i++;
    }
}

void    rotate_z(t_struct *mlx, int rows, int cols, int angle)
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
            x = mlx->arr_x[i][j];
            y = mlx->arr_y[i][j];
            mlx->arr_x[i][j] = (x * cos(angle * RAD)) - (y * sin(angle * RAD));
            mlx->arr_y[i][j] = (x * sin(angle * RAD)) + (y * cos(angle * RAD));
            j++;
        }
        i++;
    }
}
