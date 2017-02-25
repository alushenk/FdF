//
// Created by Anton Lushenko on 2/19/17.
//

#include "FdF.h"

static int     get_nums_count(char *str)
{
    int result;

    result = 0;
    while(*str)
    {
        while (ft_isspace(*str))
            str++;
        if (ft_isdigit(*str))
            result++;
        while (ft_isdigit(*str))
            str++;
        while(*str != ' ' && *str)
            str++;
    }
    return (result);
}

static void    mas_get_size(char *path, t_struct *mas)
{
    int fd;
    char *line;

    fd = open(path, O_RDONLY);
    mas->rows = 0;
    mas->cols = 0;
    while (get_next_line(fd, &line))
    {
        if (mas->cols == 0)
            mas->cols = get_nums_count(line);
        if (mas->cols != get_nums_count(line))
        {
            printf("error");
            exit(0);
        }
        mas->rows++;
        free(line);
    }
    close(fd);
}

static void    mas_create(double ***arr, int rows, int cols)
{
    double **result;
    int i;

    result = (double**)malloc(sizeof(double*) * rows);
    i = 0;
    while (i < rows)
    {
        result[i] = (double*)malloc(sizeof(double) * cols);
        i++;
    }
    *arr = result;
}

static void    mas_fill(char *path, t_struct *mas)
{
    int     fd;
    char    *line;
    char    *tmp;
    int     i;
    int     j;

    fd = open(path, O_RDONLY);
    i = 0;
    while (get_next_line(fd, &line))
    {
        tmp = line;
        j = 0;
        while (*tmp)
        {
            mas->arr_z[i][j] = atoi_skip(&tmp);
            mas->arr_x[i][j] = j;
            mas->arr_y[i][j] = i;
            if (ft_strncmp(tmp, ",0x", 3) == 0)
            {
                tmp += 3;
            }
            j++;
        }
        free(line);
        i++;
    }
    close(fd);
}

void    parse_file(char *path, t_struct *mlx)
{
    mas_get_size(path, mlx);
    mas_create(&mlx->arr_x, mlx->rows, mlx->cols);
    mas_create(&mlx->arr_y, mlx->rows, mlx->cols);
    mas_create(&mlx->arr_z, mlx->rows, mlx->cols);
    mas_fill(path, mlx);
}