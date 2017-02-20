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
    }
    return (result);
}

void    mas_get_size(char *path, t_struct *mas)
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

void    mas_create(t_struct *mas)
{
    int **result;
    int i;

    result = (int**)malloc(sizeof(int*) * mas->rows);
    i = 0;
    while (i < mas->rows)
    {
        result[i] = (int*)malloc(sizeof(int) * mas->cols);
        i++;
    }
    mas->arr = result;
}

void    mas_fill(char *path, t_struct *mas)
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
            mas->arr[i][j] = atoi_skip(&tmp);
            j++;
        }
        free(line);
        i++;
    }
    close(fd);
}
