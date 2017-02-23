//
// Created by Anton Lushenko on 2/23/17.
//

#include "FdF.h"

void    zoom_matrix(double **arr, int rows, int cols, int multiplier)
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

void    prepare_matrix(t_struct *mlx)
{
    zoom_matrix(mlx->arr_x, mlx->rows, mlx->cols, mlx->zoom);
    zoom_matrix(mlx->arr_y, mlx->rows, mlx->cols, mlx->zoom);
    zoom_matrix(mlx->arr_z, mlx->rows, mlx->cols, mlx->zoom);
}