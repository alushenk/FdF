//
// Created by Anton Lushenko on 2/17/17.
//

#include "FdF.h"

void    print_mlx(t_struct *mlx)
{
    int i;
    int j;

    i = 0;
    while (i < mlx->rows)
    {
        j = 0;
        while (j < mlx->cols)
        {
            printf("%-3d", mlx->arr[i][j]);
            j++;
        }
        i++;
        printf("\n");
    }
}

void    parse_file(char *path)
{
    t_struct mlx;

    mas_get_size(path, &mlx);
    mas_create(&mlx);
    mas_fill(path, &mlx);

    //print_mlx(&mlx);

    fdf(&mlx);

}

int main(int argc, char **argv)
{
    g_angle = 0;
    if (argc == 2)
    {
        parse_file(argv[1]);
    }
    else
        printf("arguments needed");
    return (0);

}